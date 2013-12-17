#pragma once


// DialogAddText dialog

class DialogAddText : public CDialogEx
{
	DECLARE_DYNAMIC(DialogAddText)

public:
	DialogAddText(CWnd* pParent = NULL);   // standard constructor
	virtual ~DialogAddText();

// Dialog Data
	enum { IDD = IDD_ADDTEXT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
