
// 数据库系统Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "数据库系统.h"
#include "数据库系统Dlg.h"
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

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

using namespace std;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// C数据库系统Dlg 对话框



C数据库系统Dlg::C数据库系统Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C数据库系统Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C数据库系统Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE3, Tree);
}

BEGIN_MESSAGE_MAP(C数据库系统Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32781, &C数据库系统Dlg::DeleteDatabase)
	ON_COMMAND(ID_32773, &C数据库系统Dlg::CreateDatabase)
END_MESSAGE_MAP()


// C数据库系统Dlg 消息处理程序

BOOL C数据库系统Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	Database db;
	list<string> mylist = db.getDatabases();
	std::vector<int>::size_type size = mylist.size();
	CString r;

	for (StringList::const_iterator ci = mylist.begin(); ci != mylist.end(); ++ci){
		//转化
		char tab2[1024];
		strcpy(tab2, ci->c_str());
		HTREEITEM db=Tree.InsertItem(tab2,0,0);
    }

	//Table mTable;
	//mTable.getColumns("test.txt");
	printf("dsdsd");



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C数据库系统Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C数据库系统Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C数据库系统Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//菜单选项新建数据库
void C数据库系统Dlg::CreateDatabase()
{
	//调用新建数据库的对话框
	CDatabaseDialog CreateDatabase;
	CreateDatabase.DoModal();
	//GetDlgItemText(IDC_EDIT1,r);
	/*HTREEITEM db=Tree.InsertItem("胡江",0,0);*/
	// TODO: 在此添加命令处理程序代码
}

//菜单选项删除数据库
void C数据库系统Dlg::DeleteDatabase()
{
	//调用删除数据库的对话框
	DatabaseDialog1 DropDatabase;
	DropDatabase.DoModal();
	// TODO: 在此添加命令处理程序代码
}

