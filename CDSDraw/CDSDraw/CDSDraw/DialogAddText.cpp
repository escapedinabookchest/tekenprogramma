// DialogAddText.cpp : implementation file
//

#include "stdafx.h"
#include "CDSDraw.h"
#include "DialogAddText.h"
#include "afxdialogex.h"


// DialogAddText dialog

IMPLEMENT_DYNAMIC(DialogAddText, CDialogEx)

DialogAddText::DialogAddText(CWnd* pParent /*=NULL*/)
	: CDialogEx(DialogAddText::IDD, pParent)
{

}

DialogAddText::~DialogAddText()
{
}

void DialogAddText::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DialogAddText, CDialogEx)
END_MESSAGE_MAP()


// DialogAddText message handlers
