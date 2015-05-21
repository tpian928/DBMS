// DatabaseDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "数据库系统.h"
#include "DatabaseDialog.h"
#include "afxdialogex.h"

// CDatabaseDialog 对话框

IMPLEMENT_DYNAMIC(CDatabaseDialog, CDialogEx)

CDatabaseDialog::CDatabaseDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDatabaseDialog::IDD, pParent)
{

}

CDatabaseDialog::~CDatabaseDialog()
{
}

void CDatabaseDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDatabaseDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDatabaseDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDatabaseDialog 消息处理程序


void CDatabaseDialog::OnBnClickedButton1()
{
	CString r;
	GetDlgItemText(IDC_EDIT1,r);
	char myString[256];
	strcpy(myString, (LPCTSTR)r);
	Database mydb;
	mydb.addDatabase(myString);
	MessageBox(_T("新建成功！"));
	PostMessage(WM_CLOSE);
	//// TODO: 在此添加控件通知处理程序代码
}
