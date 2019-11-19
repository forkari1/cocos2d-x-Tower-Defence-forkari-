#include "WindowManager.h"

void WindowManager::init()
{
	m_pBuild = NULL;
	m_pStatus = NULL;
	m_pLayer = NULL;
}

void WindowManager::createWindow( Land* _pLand, int _index	)
{
	if( m_pLayer  == NULL ) return;
	if( m_pBuild != NULL ) return;

	m_pBuild = new BuildWindow;
	m_pBuild->init();
	m_pBuild->setPosition( _pLand->getPosition() );
	m_pBuild->setTowerIndex( _index );
	m_pBuild->setTower( _pLand->getTower() );

	if( m_pBuild->getTower() == NULL ){			//Window�� ������ Land�� Ÿ���� �����ϴ� ���
		m_pMenu = CCMenu::menuWithItems( 
			m_pBuild->m_pItemArrow, 
			m_pBuild->m_pItemBomb, 
			m_pBuild->m_pItemMagic, 
			m_pBuild->m_pItemShield, NULL );
	}else{										// �׷��� ���� ���
		switch( m_pBuild->getTower()->getTowerType() ){
		case BOMB:case MAGIC:case ARCHER:
			m_pMenu = CCMenu::menuWithItems( 
				m_pBuild->m_pItemUpgrade, 
				m_pBuild->m_pItemSell, NULL );
			break;	
		default:
			m_pMenu = CCMenu::menuWithItems( 
				m_pBuild->m_pItemNone, 
				m_pBuild->m_pItemSell, NULL );
			break;
		}		

		m_pBuild->popupRange();
		this->popupStatus();									// Status�� Build�� ����� �ƴ� ������ ��ġ�� action����
		m_pStatus->updateTowerInfo( m_pBuild->getTower() );		// Status�� ����� (�Ű������� �Ѿ��)Tower������ update
		m_pStatus->updateTowerLabel();							// update�� Tower������ ���
	}

	m_pBuild->addChild( m_pMenu );
	m_pMenu->setPosition( ccp(0,40) );
	m_pLayer->addChild( m_pBuild, 600 );
}

void WindowManager::popupStatus()
{
	m_pStatus = new StatusWindow;
	m_pStatus->init();
	m_pLayer->addChild( m_pStatus );
}

void WindowManager::closeWindow()
{
	if( m_pLayer == NULL ) return;

	if( m_pBuild == NULL ) return;
	m_pLayer->removeChild( m_pBuild, true );
	m_pBuild  = NULL;

	if( m_pStatus == NULL ) return;
	m_pLayer->removeChild( m_pStatus, true );
	m_pStatus = NULL;
}