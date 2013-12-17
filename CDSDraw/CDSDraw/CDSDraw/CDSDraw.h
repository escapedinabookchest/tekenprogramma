
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
	afx_msg void OnEditUndo();
	afx_msg void OnFillcolorBlue();
	afx_msg void OnUpdateFillcolorBlue(CCmdUI *pCmdUI);
	afx_msg void OnFillcolorRed();
	afx_msg void OnUpdateFillcolorRed(CCmdUI *pCmdUI);
	afx_msg void OnFillcolorGreen();
	afx_msg void OnUpdateFillcolorGreen(CCmdUI *pCmdUI);
	afx_msg void OnFillcolorWhite();
	afx_msg void OnUpdateFillcolorWhite(CCmdUI *pCmdUI);
	afx_msg void OnLinethicknessThin();
	afx_msg void OnUpdateLinethicknessThin(CCmdUI *pCmdUI);
	afx_msg void OnLinethicknessNormal();
	afx_msg void OnUpdateLinethicknessNormal(CCmdUI *pCmdUI);
	afx_msg void OnLinethicknessFat();
	afx_msg void OnUpdateLinethicknessFat(CCmdUI *pCmdUI);
	afx_msg void OnLinestyleSolid();
	afx_msg void OnUpdateLinestyleSolid(CCmdUI *pCmdUI);
	afx_msg void OnLinestyleDashed();
	afx_msg void OnUpdateLinestyleDashed(CCmdUI *pCmdUI);
	afx_msg void OnLinestyleDotted();
	afx_msg void OnUpdateLinestyleDotted(CCmdUI *pCmdUI);
	afx_msg void OnLinecolorBlack();
	afx_msg void OnUpdateLinecolorBlack(CCmdUI *pCmdUI);
	afx_msg void OnLinecolorBlue();
	afx_msg void OnUpdateLinecolorBlue(CCmdUI *pCmdUI);
	afx_msg void OnLinecolorRed();
	afx_msg void OnUpdateLinecolorRed(CCmdUI *pCmdUI);
	afx_msg void OnLinecolorGreen();
	afx_msg void OnUpdateLinecolorGreen(CCmdUI *pCmdUI);
	afx_msg void OnGraphicsAddtext();
	afx_msg void OnUpdateGraphicsAddtext(CCmdUI *pCmdUI);
};

extern CCDSDrawApp theApp;
