#pragma once
#include "Database.h"
#include "���ݿ�ϵͳDlg.h"
// CDatabaseDialog �Ի���


class CDatabaseDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDatabaseDialog)

public:
	CDatabaseDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDatabaseDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
