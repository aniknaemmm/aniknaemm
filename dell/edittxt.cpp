

#include <windows.h>
#include <tchar.h>
#include <map>
using namespace std;


LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение"); 
TCHAR mainMessage[] = TEXT("Демонстрация отрисовки цветного текста!");
int RGB_color_1 = 0, RGB_color_2 = 0, 

LRESULT CALLBACK KeyboardHanldler"/*"(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam) {
	TCHAR str[50];
	BOOL bRepaint = true;*/
	RECT our_rect;
	GetWindowRect(hWnd, &our_rect);
	i0"cdc"
