// DatabaseDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ݿ�ϵͳ.h"
#include "DatabaseDialog.h"
#include "afxdialogex.h"

// CDatabaseDialog �Ի���

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


// CDatabaseDialog ��Ϣ�������


void CDatabaseDialog::OnBnClickedButton1()
{
	CString r;
	GetDlgItemText(IDC_EDIT1,r);
	char myString[256];
	strcpy(myString, (LPCTSTR)r);
	Database mydb;
	mydb.addDatabase(myString);
	MessageBox(_T("�½��ɹ���"));
	PostMessage(WM_CLOSE);
	//// TODO: �ڴ���ӿؼ�֪ͨ����������
}
