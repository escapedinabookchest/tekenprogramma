
// CDSDraw.h : main header file for the CDSDraw application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCDSDrawApp:
// See CDSDraw.cpp for the implementation of this class
//

class CCDSDrawApp : public CWinApp
{
public:
	CCDSDrawApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnShapeCircle();
	afx_msg void OnShapeEllipse();
	afx_msg void OnShapeLine();
	afx_msg void OnShapeRectangle();
	afx_msg void OnShapeSquare();
	afx_msg void OnUpdateShapeCircle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeEllipse(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeRectangle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeSquare(CCmdUI *pCmdUI);
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
};

extern CCDSDrawApp theApp;
