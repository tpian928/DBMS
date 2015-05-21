#pragma once
#include "Database.h"

// DatabaseDialog1 对话框

class DatabaseDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(DatabaseDialog1)

public:
	DatabaseDialog1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DatabaseDialog1();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
