
// ���ݿ�ϵͳDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ݿ�ϵͳ.h"
#include "���ݿ�ϵͳDlg.h"
#include "afxdialogex.h"
#include "DatabaseDialog.h"
#include "DatabaseDialog1.h"
#include <vector>
#include <iostream>
#include "Table.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
typedef list<string> StringList;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

using namespace std;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C���ݿ�ϵͳDlg �Ի���



C���ݿ�ϵͳDlg::C���ݿ�ϵͳDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���ݿ�ϵͳDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C���ݿ�ϵͳDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE3, Tree);
}

BEGIN_MESSAGE_MAP(C���ݿ�ϵͳDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32781, &C���ݿ�ϵͳDlg::DeleteDatabase)
	ON_COMMAND(ID_32773, &C���ݿ�ϵͳDlg::CreateDatabase)
END_MESSAGE_MAP()


// C���ݿ�ϵͳDlg ��Ϣ�������

BOOL C���ݿ�ϵͳDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	Database db;
	list<string> mylist = db.getDatabases();
	std::vector<int>::size_type size = mylist.size();
	CString r;

	for (StringList::const_iterator ci = mylist.begin(); ci != mylist.end(); ++ci){
		//ת��
		char tab2[1024];
		strcpy(tab2, ci->c_str());
		HTREEITEM db=Tree.InsertItem(tab2,0,0);
    }

	//Table mTable;
	//mTable.getColumns("test.txt");
	printf("dsdsd");



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C���ݿ�ϵͳDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C���ݿ�ϵͳDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C���ݿ�ϵͳDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//�˵�ѡ���½����ݿ�
void C���ݿ�ϵͳDlg::CreateDatabase()
{
	//�����½����ݿ�ĶԻ���
	CDatabaseDialog CreateDatabase;
	CreateDatabase.DoModal();
	//GetDlgItemText(IDC_EDIT1,r);
	/*HTREEITEM db=Tree.InsertItem("����",0,0);*/
	// TODO: �ڴ���������������
}

//�˵�ѡ��ɾ�����ݿ�
void C���ݿ�ϵͳDlg::DeleteDatabase()
{
	//����ɾ�����ݿ�ĶԻ���
	DatabaseDialog1 DropDatabase;
	DropDatabase.DoModal();
	// TODO: �ڴ���������������
}

