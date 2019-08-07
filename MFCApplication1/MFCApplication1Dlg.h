
// MFCApplication1Dlg.h: 헤더 파일
//

#pragma once

#define	MAX_EAT_COUNT		300
#define MAX_LENGTH			250

struct MapPoint
{
	char x;
	char y;
};

// CMFCApplication1Dlg 대화 상자
class CMFCApplication1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CImage m_draw_image;
	CDC m_draw_dc;

	// 먹이 메모리 최적화
	//COLORREF m_table[60][80] = { 0, };		// 60 * 80 * 4 = 19200 Bytes(18.75K)
	//POINT m_eat_pos[MAX_EAT_COUNT];			// 8 * 300 = 2400 Bytes
	MapPoint m_eat_pos[MAX_EAT_COUNT];			// 2 * 300 = 600 Bytes

	// 뱀 크기 메모리 최적화
	//int m_count_map[60][80] = { 0, };			// 60 * 80 * 4 = 19200 Bytes(18.75K)
	MapPoint m_snake_pos[MAX_LENGTH];			// 2 * 250 = 500 Bytes

	// POINT m_pos = { 40, 30 };		// 녹색 뱀의 위치
	MapPoint m_pos = { 40, 30 };

	int m_direction = 0;			// 0 left / 1 up / 2 right / 3 bottom
	int m_eat_count = 0;

	int m_remain_count = MAX_EAT_COUNT;

	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void DrawMap();
	void GameOver();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnChangeEdit1();
};
