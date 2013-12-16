
// CDSDraw.cpp : Defines the class behaviors for the application.
//

#define _CRTDBG_MAP_ALLOC

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "CDSDraw.h"
#include "MainFrm.h"

#include <fstream>
#include <iostream>
#include <string>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCDSDrawApp

BEGIN_MESSAGE_MAP(CCDSDrawApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CCDSDrawApp::OnAppAbout)
	ON_COMMAND(ID_SHAPE_CIRCLE, &CCDSDrawApp::OnShapeCircle)
	ON_COMMAND(ID_SHAPE_ELLIPSE, &CCDSDrawApp::OnShapeEllipse)
	ON_COMMAND(ID_SHAPE_LINE, &CCDSDrawApp::OnShapeLine)
	ON_COMMAND(ID_SHAPE_RECTANGLE, &CCDSDrawApp::OnShapeRectangle)
	ON_COMMAND(ID_SHAPE_SQUARE, &CCDSDrawApp::OnShapeSquare)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_CIRCLE, &CCDSDrawApp::OnUpdateShapeCircle)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_ELLIPSE, &CCDSDrawApp::OnUpdateShapeEllipse)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_LINE, &CCDSDrawApp::OnUpdateShapeLine)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_RECTANGLE, &CCDSDrawApp::OnUpdateShapeRectangle)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_SQUARE, &CCDSDrawApp::OnUpdateShapeSquare)
	ON_COMMAND(ID_FILE_OPEN32776, &CCDSDrawApp::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE32777, &CCDSDrawApp::OnFileSave)
	ON_COMMAND(ID_EDIT_UNDO, &CCDSDrawApp::OnEditUndo)
END_MESSAGE_MAP()


// CCDSDrawApp construction

CCDSDrawApp::CCDSDrawApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("CDSDraw.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CCDSDrawApp object

CCDSDrawApp theApp;


// CCDSDrawApp initialization
BOOL CCDSDrawApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// create and load the frame with its resources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);

	// The one and only window has been initialized, so show and update it
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int CCDSDrawApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CCDSDrawApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CCDSDrawApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CCDSDrawApp message handlers

// Select the Circle shape as the current shape
void CCDSDrawApp::OnShapeCircle()
{
	CChildView::shapeIndex = (CChildView::shapeIndex == 0) ? -1 : 0;
}

// Select the Ellipse shape as the current shape
void CCDSDrawApp::OnShapeEllipse()
{
	CChildView::shapeIndex = (CChildView::shapeIndex == 1) ? -1 : 1;
}

// Select the Line shape as the current shape
void CCDSDrawApp::OnShapeLine()
{
	CChildView::shapeIndex = (CChildView::shapeIndex == 2) ? -1 : 2;
}

// Select the Rectangle shape as the current shape
void CCDSDrawApp::OnShapeRectangle()
{
	CChildView::shapeIndex = (CChildView::shapeIndex == 3) ? -1 : 3;
}

// Select the Square shape as the current shape
void CCDSDrawApp::OnShapeSquare()
{
	CChildView::shapeIndex = (CChildView::shapeIndex == 4) ? -1 : 4;
}

// Check/Uncheck the Circle shape in the menu bar
void CCDSDrawApp::OnUpdateShapeCircle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck((CChildView::shapeIndex == 0) ? 1 : 0);
}

// Check/Uncheck the Ellipse shape in the menu bar
void CCDSDrawApp::OnUpdateShapeEllipse(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck((CChildView::shapeIndex == 1) ? 1 : 0);
}

// Check/Uncheck the Line shape in the menu bar
void CCDSDrawApp::OnUpdateShapeLine(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck((CChildView::shapeIndex == 2) ? 1 : 0);
}

// Check/Uncheck the Rectangle shape in the menu bar
void CCDSDrawApp::OnUpdateShapeRectangle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck((CChildView::shapeIndex == 3) ? 1 : 0);
}

// Check/Uncheck the Square shape in the menu bar
void CCDSDrawApp::OnUpdateShapeSquare(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck((CChildView::shapeIndex == 4) ? 1 : 0);
}


// Opens a previous saved file
void CCDSDrawApp::OnFileOpen()
{
	// Prepare the file dialog to open a CRDS file
	CFileDialog fileDialog(TRUE, _T("dscr"), _T("*.dscr"), OFN_FILEMUSTEXIST);

	fileDialog.m_ofn.lpstrFilter = _T("DSCR Files Only (*.dscr)\0*.dscr\0\0");
	fileDialog.m_ofn.lpstrTitle = _T("Open DSCR File");

	// Handling the input for the file in the system
	CString cPath;
	if (fileDialog.DoModal() == IDOK)
	{
		cPath = fileDialog.GetPathName();
		CT2CA pszConvertedAnsiiString(cPath);

		string filename(pszConvertedAnsiiString);

		ifstream inputFile;
		inputFile.open(filename);

		char chars;
		string fileSource;

		while (!inputFile.eof())
		{
			inputFile.get(chars);
			if (!inputFile.eof())
				fileSource.append(sizeof(chars), chars);
		}

		inputFile.close();

		CChildView::LoadShapes(fileSource.c_str());
	}
}

// Saves the current file
void CCDSDrawApp::OnFileSave()
{
	// Prepare the file dialog to save a CRDS file
	CFileDialog fileDialog(FALSE, _T("dscr"), NULL, 0, NULL);

	fileDialog.SetDefExt(_T("dscr"));
	fileDialog.m_ofn.lpstrFilter = _T("DSCR Files Only (*.dscr)\0*.dscr\0\0");
	fileDialog.m_ofn.lpstrTitle = _T("Save DSCR File");

	//BUG: Assertion fails on 

	// Write the shape-data to the file
	CString cPath;
	if (IDOK == fileDialog.DoModal())
	{
		cPath = fileDialog.GetPathName();
		//CT2CA pszConvertedAnsiiString(cPath);

		//string filename(pszConvertedAnsiiString);


		ofstream outputFile;
		outputFile.open(cPath);
		
		string fileSource = CChildView::SaveShapes();
		outputFile << fileSource;

		outputFile.close();
	}
}


void CCDSDrawApp::OnEditUndo()
{
	CChildView::TryUndo();
}
