// ���� WINDOWS.H �������� �����������, �������, � ��������� 
// ������� ������������ ��� ��������� ���������� ��� Windows. 
#include <windows.h>
#include <tchar.h>
#include <map>
using namespace std;

//�������� ������� ���������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("��������� ����������"); /* ��� ������ ���� */
TCHAR mainMessage[] = TEXT("������������ ��������� �������� ������!");//for paint
int RGB_color_1 = 0, RGB_color_2 = 0, /*RGB_color_3 = 0;

typedef LRESULT CALLBACK EventProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);



map<UINT, EventProc*> eventMap;*/

LRESULT CALLBACK KeyboardHanldler"/*"(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	TCHAR str[50];
	BOOL bRepaint = true;*/
	RECT our_rect;
	GetWindowRect(hWnd, &our_rect);
	i/*f (wParam == VK_UP)
	{
		MoveWindow(
		"*/0"cdc"
		/*"hWnd,*/
			our_rect.left,
			our_rect.top - 1,
			ou//r_rect.right - our_rect.left,
			our_rect.bottom - our_rect.top,
			bRepaint
			);
		return 0;
	}
	if (wParam == VK_DOWN)
	{
		MoveWindow(
			hWnd,
			our_rect.left,
			our_rect.top + 1,
			our_rect.right - our_rect.left,
			our_rect.bottom - our_rect.top,
			bRepaint
			);
		return 0;
	}
	if (wParam == VK_LEFT)
	{
		MoveWindow(
			hWnd,
			our_rect.left - 1,
			our_rect.top,
			our_rect.right - our_rect.left,
			our_rect.bottom - our_rect.top,
			bRepaint
			);
		return 0;
	}
	if (wParam == VK_RIGHT)
	{
		MoveWindow(
			hWnd,
			our_rect.left + 1,
			our_rect.top,
			our_rect.right - our_rect.left,
			our_rect.bottom - our_rect.top,
			bRepaint
			);
		return 0;
	}
	else
	{
		wsprintf(str, TEXT("code=%d"), wParam); // ������� ���������� ������� ����
		SetWindowText(hWnd, str);
		return 0;
	}
}


LRESULT CALLBACK OnDoubleClick(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam){
	MessageBox(0,
		TEXT("������� ������ ����� ������� ����"),
		TEXT("WM_LBUTTONDBLCLK"),
		MB_OK | MB_ICONINFORMATION);
	return 0;

}

LRESULT CALLBACK OnExit(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam){
	PostQuitMessage(0);	// ������� ��������� WM_QUIT
	return 0;
}

LRESULT CALLBACK run_cursor(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam){
	BOOL bRepaint = true;
	RECT our_rect;
	GetWindowRect(hWnd, &our_rect);
	int left_mod, top_mod;
	int x = LOWORD(lParam);
	if ((our_rect.right - our_rect.left) / 2 > LOWORD(lParam))
		left_mod = 1;
	else
		left_mod = -1;
	if ((our_rect.bottom - our_rect.top) / 2 > HIWORD(lParam))
		top_mod = 1;
	else
		top_mod = -1;
	MoveWindow(
		hWnd,
		our_rect.left + left_mod,
		our_rect.top + top_mod,
		our_rect.right - our_rect.left,
		our_rect.bottom - our_rect.top,
		bRepaint
		);
	return 0;
}

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;

	/* 1. ����������� ������ ����  */

	wcl.cbSize = sizeof (wcl);	// ������ ��������� WNDCLASSEX 
	wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// ���� ������ �������� ��������� � ������� ������ (DBLCLK)
	wcl.lpfnWndProc = WindowProc;	// ����� ������� ���������
	wcl.cbClsExtra = 0;		// ������������ Windows 
	wcl.cbWndExtra = 0; 	// ������������ Windows 
	wcl.hInstance = hInst;	// ���������� ������� ����������
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// �������� ����������� ������
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);		// �������� ������������ �������
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//���������� ���� ����� ������			
	wcl.lpszMenuName = NULL;	// ���������� �� �������� ����
	wcl.lpszClassName = szClassWindow;	// ��� ������ ����
	wcl.hIconSm = NULL;	// ���������� ��������� ������ ��� ����� � ������� ����


	/*  2. ����������� ������ ����  */

	if (!RegisterClassEx(&wcl))
		return 0;	// ��� ��������� ����������� - �����

	/*  3. �������� ����  */

	// ��������� ���� �  ���������� hWnd ������������� ���������� ����
	hWnd = CreateWindowEx(
		0,		// ����������� ����� ����
		szClassWindow,	// ��� ������ ����
		TEXT("������  Windows ����������"),	// ��������� ����
		/* ���������, �����, ����������� ������ �������, ��������� ����,
		������ ������������ � ���������� ����  */
		WS_OVERLAPPEDWINDOW,	// ����� ����
		CW_USEDEFAULT,	// �-���������� ������ �������� ���� ����
		CW_USEDEFAULT,	// y-���������� ������ �������� ���� ����
		CW_USEDEFAULT,	// ������ ����
		CW_USEDEFAULT,	// ������ ����
		NULL,			// ���������� ������������� ����
		NULL,			// ���������� ���� ����
		hInst,		// ������������� ����������, ���������� ����
		NULL);		// ��������� �� ������� ������ ����������


	/* 4. ����������� ���� */

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);	// ����������� ����

	/* 4.5 ������������ ������� */

	eventMap[WM_KEYDOWN] = KeyboardHanldler;
	eventMap[WM_LBUTTONDBLCLK] = OnDoubleClick;
	eventMap[WM_DESTROY] = OnExit;
	eventMap[WM_MOUSEMOVE] = run_cursor;

	/* 5. ������ ����� ��������� ���������  */

	// ��������� ���������� ��������� �� ������� ���������
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);	// ���������� ���������
		DispatchMessage(&Msg);	// ��������������� ���������
	}
	return Msg.wParam;
}


// ������� ��������� ���������� ������������ �������� � �������� � �������� 
// ���������� ��������� �� ������� ��������� ������� ����������	




LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hDC; // ������ ���������� ���������� ������ �� ������
	PAINTSTRUCT ps; // ���������, ���-��� ���������� � ���������� ������� (�������, ���� � ��)
	RECT rect; // ���-��, ������������ ������ ���������� �������
	COLORREF colorText = RGB(RGB_color_1, RGB_color_2, RGB_color_3);
	if (RGB_color_1 < 255)
		++RGB_color_1;
	else if (RGB_color_2 < 255) ++RGB_color_2;
	else if (RGB_color_3 < 255) ++RGB_color_3;
	else
	{
		RGB_color_1 = 0;
		RGB_color_2 = 0;
		RGB_color_3 = 0;
	}

	if (eventMap.find(uMessage) != eventMap.end())
		return (eventMap[uMessage])  (hWnd, uMessage, wParam, lParam);
	if (uMessage == WM_PAINT)
	{
		hDC = BeginPaint(hWnd, &ps); // �������������� �������� ����������
		GetClientRect(hWnd, &rect); // �������� ������ � ������ ������� ��� ���������
		SetTextColor(hDC, colorText); // ������������� ���� ������������ ����������
		DrawText(hDC, mainMessage, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER); // ������ �����
		EndPaint(hWnd, &ps);
	}
	else
		return DefWindowProc(hWnd, uMessage, wParam, lParam);


	/*
	switch (uMessage)
	{
	case WM_LBUTTONDOWN:
	MessageBox(
	0,
	TEXT("������ ����� ������ ����"),
	TEXT("WM_LBUTTONDOWN"),
	MB_OK | MB_ICONINFORMATION);
	break;
	case WM_LBUTTONUP:
	MessageBox(
	0,
	TEXT("�������� ����� ������ ����"),
	TEXT("WM_LBUTTONUP"),
	MB_OK | MB_ICONINFORMATION);
	break;
	case WM_RBUTTONDOWN:
	MessageBox(
	0,
	TEXT("������ ������ ������ ����"),
	TEXT("WM_RBUTTONDOWN"),
	MB_OK | MB_ICONINFORMATION);
	break;
	case WM_MOUSEMOVE:{
	TCHAR str[50];
	wsprintf(str, TEXT("X=%d  Y=%d"), LOWORD(lParam), HIWORD(lParam)); // ������� ���������� ������� ����
	SetWindowText(hWnd, str);	// ������ ��������� � ��������� ����
	}break;
	case WM_CHAR:{
	TCHAR str[50];
	wsprintf(str, TEXT("������ ������� %c"), (TCHAR)wParam);	// ASCII-��� ������� �������
	MessageBox(0, str, TEXT("WM_CHAR"), MB_OK | MB_ICONINFORMATION);
	break;
	}
	default:
	return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	*/
	return 0;

}