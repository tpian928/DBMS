#pragma once
#include "Database.h"
#include "数据库系统Dlg.h"
// CDatabaseDialog 对话框


class CDatabaseDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDatabaseDialog)

public:
	CDatabaseDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDatabaseDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
