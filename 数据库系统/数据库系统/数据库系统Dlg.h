
// ���ݿ�ϵͳDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// C���ݿ�ϵͳDlg �Ի���
class C���ݿ�ϵͳDlg : public CDialogEx
{
// ����
public:
	C���ݿ�ϵͳDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void DeleteDatabase();
	afx_msg void CreateDatabase();;
	CTreeCtrl Tree;
};
