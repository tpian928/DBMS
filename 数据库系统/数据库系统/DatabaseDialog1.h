#pragma once
#include "Database.h"

// DatabaseDialog1 �Ի���

class DatabaseDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(DatabaseDialog1)

public:
	DatabaseDialog1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DatabaseDialog1();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
