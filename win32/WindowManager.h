#pragma once
#include "cocos2d.h"
#include "BuildWindow.h"
#include "StatusWindow.h"
#include "Land.h"
using namespace cocos2d;

class WindowManager
{
private:
	BuildWindow*	m_pBuild;
	StatusWindow*	m_pStatus;
	CCLayer*		m_pLayer;
	CCMenu*			m_pMenu;

public:
	void init();
	void popupStatus();
	void setLayer( CCLayer*	_pLayer ){ m_pLayer = _pLayer; }
	void createWindow( Land* _pLand, int _index	);
	void closeWindow();
	BuildWindow* getWindow(){ return m_pBuild; }
};