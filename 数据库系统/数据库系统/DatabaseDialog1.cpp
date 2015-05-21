// DatabaseDialog1.cpp : 实现文件
//

#include "stdafx.h"
#include "数据库系统.h"
#include "DatabaseDialog1.h"
#include "afxdialogex.h"


// DatabaseDialog1 对话框

IMPLEMENT_DYNAMIC(DatabaseDialog1, CDialogEx)

DatabaseDialog1::DatabaseDialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(DatabaseDialog1::IDD, pParent)
{

}

DatabaseDialog1::~DatabaseDialog1()
{
}

void DatabaseDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DatabaseDialog1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DatabaseDialog1::OnBnClickedButton1)
END_MESSAGE_MAP()


// DatabaseDialog1 消息处理程序


void DatabaseDialog1::OnBnClickedButton1()
{
	CString r;
	GetDlgItemText(IDC_EDIT1,r);
	char myString[256];
	strcpy(myString, (LPCTSTR)r);
	Database mydb;
	mydb.deleteDatabase(myString);
	MessageBox(_T("删除成功！"));
	PostMessage(WM_CLOSE);
	// TODO: 在此添加控件通知处理程序代码
}
