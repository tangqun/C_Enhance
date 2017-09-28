
// C_Dynamic_Library_Function_CallDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "C_Dynamic_Library_Function_Call.h"
#include "C_Dynamic_Library_Function_CallDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CC_Dynamic_Library_Function_CallDlg �Ի���



CC_Dynamic_Library_Function_CallDlg::CC_Dynamic_Library_Function_CallDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_C_DYNAMIC_LIBRARY_FUNCTION_CALL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CC_Dynamic_Library_Function_CallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CC_Dynamic_Library_Function_CallDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CC_Dynamic_Library_Function_CallDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CC_Dynamic_Library_Function_CallDlg ��Ϣ�������

BOOL CC_Dynamic_Library_Function_CallDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CC_Dynamic_Library_Function_CallDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CC_Dynamic_Library_Function_CallDlg::OnPaint()
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
HCURSOR CC_Dynamic_Library_Function_CallDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

typedef int(*CltSocketInit)(void **handle /*out*/);
typedef int(*CltSocketSend)(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/);
typedef int(*CltSocketRev)(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/);
typedef int(*CltSocketDestory)(void *handle /*in*/);

void CC_Dynamic_Library_Function_CallDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ret = 0;
	void *handle = NULL;

	HINSTANCE hInstance;

	hInstance = LoadLibrary("c:/socketclient.dll");
	if (NULL == hInstance)
	{
		;
	}
	CltSocketInit cltSocketInit = (CltSocketInit)GetProcAddress(hInstance, "cltSocketInit");
	if (NULL == cltSocketInit)
	{
		return;
	}
	CltSocketSend cltSocketSend = (CltSocketSend)GetProcAddress(hInstance, "cltSocketSend");
	if (NULL == cltSocketInit)
	{
		return;
	}
	CltSocketRev cltSocketRev = (CltSocketRev)GetProcAddress(hInstance, "cltSocketRev");
	if (NULL == cltSocketInit)
	{
		return;
	}
	CltSocketDestory cltSocketDestory = (CltSocketDestory)GetProcAddress(hInstance, "cltSocketDestory");
	if (NULL == cltSocketInit)
	{
		return;
	}

	char buf[1024] = { 0 };
	strcpy(buf, "dddddsssssaaaa");
	int buflen = 10;
	char out[1024] = { 0 };
	int outlen;

	ret = cltSocketInit(&handle);
	if (0 != ret)
	{
		return;
	}
	ret = cltSocketSend(handle, (unsigned char *)buf, buflen);
	if (0 != ret)
	{
		return;
	}
	ret = cltSocketRev(handle, (unsigned char *)out, &outlen);
	if (0 != ret)
	{
		return;
	}
	ret = cltSocketDestory(handle);
	if (0 != ret)
	{
		return;
	}

	AfxMessageBox(out);
}
