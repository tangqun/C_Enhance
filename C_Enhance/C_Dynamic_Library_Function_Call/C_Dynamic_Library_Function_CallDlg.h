
// C_Dynamic_Library_Function_CallDlg.h : ͷ�ļ�
//

#pragma once


// CC_Dynamic_Library_Function_CallDlg �Ի���
class CC_Dynamic_Library_Function_CallDlg : public CDialogEx
{
// ����
public:
	CC_Dynamic_Library_Function_CallDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_C_DYNAMIC_LIBRARY_FUNCTION_CALL_DIALOG };
#endif

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
	afx_msg void OnBnClickedButton1();
};
