// DatabaseDialog1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ݿ�ϵͳ.h"
#include "DatabaseDialog1.h"
#include "afxdialogex.h"


// DatabaseDialog1 �Ի���

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


// DatabaseDialog1 ��Ϣ�������


void DatabaseDialog1::OnBnClickedButton1()
{
	CString r;
	GetDlgItemText(IDC_EDIT1,r);
	char myString[256];
	strcpy(myString, (LPCTSTR)r);
	Database mydb;
	mydb.deleteDatabase(myString);
	MessageBox(_T("ɾ���ɹ���"));
	PostMessage(WM_CLOSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
