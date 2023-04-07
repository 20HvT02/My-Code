// ControlWindow.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ControlWindow.h"

#define MAX_LOADSTRING 100
#define ID_EDITHT 1
#define ID_BTNOK 2
#define ID_BTNCLOSE 3
#define ID_BTNRESET 4
#define ID_CHKMUSIC 5
#define ID_CHKGAME 6
#define ID_TSSHOPPING 7

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hwndEditHT;
HWND hwndBtnOK;
HWND hwndBtnClose;
HWND hwndBtnReset;
HWND hwndChkMusic;
HWND hwndChkGame, hwndTSShopping;
// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CONTROLWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CONTROLWINDOW));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CONTROLWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CONTROLWINDOW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static int len, count = 0;
    static TCHAR hoten[30], kq[50];
    
    switch (message)
    {
    case WM_CLOSE:
        // SendMessage(hwndBtnClose, BM_CLICK, 0, 0);
        if (MessageBox(NULL, TEXT("Do you want to exit?"), TEXT("Yes/No?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
            PostQuitMessage(1);
        break;
    case WM_CREATE:
        hwndEditHT = CreateWindow(TEXT("edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER,
            50, 50, 300, 30, hWnd, (HMENU)ID_EDITHT, NULL, NULL);
        hwndBtnOK = CreateWindow(TEXT("button"), TEXT("OK"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            355, 50, 60, 30, hWnd, (HMENU)ID_BTNOK, NULL, NULL);
        hwndBtnReset = CreateWindow(TEXT("button"), TEXT("Reset"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
            420, 50, 60, 30, hWnd, (HMENU)ID_BTNRESET, NULL, NULL);
        hwndBtnClose = CreateWindow(TEXT("button"), TEXT("Close"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            485, 50, 60, 30, hWnd, (HMENU)ID_BTNCLOSE, NULL, NULL);
        hwndChkMusic = CreateWindow(TEXT("button"), TEXT("Music"), WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
            50, 85, 80, 30, hWnd, (HMENU)ID_CHKMUSIC, NULL, NULL);
        hwndChkGame = CreateWindow(TEXT("button"), TEXT("Game"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
            50, 120, 80, 30, hWnd, (HMENU)ID_CHKGAME, NULL, NULL);
        hwndTSShopping = CreateWindow(TEXT("button"), TEXT("Shopping"), WS_CHILD | WS_VISIBLE | BS_AUTO3STATE,
            50, 155, 80, 30, hWnd, (HMENU)ID_TSSHOPPING, NULL, NULL);

        SetFocus(hwndEditHT);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_BTNRESET:
                SendMessage(hwndChkMusic, BM_SETCHECK, 0, 0);
                SendMessage(hwndTSShopping, BM_SETCHECK, 0, 0);
                SendMessage(hwndChkGame, BM_SETCHECK, 0, 0);
                SetWindowText(hwndEditHT, TEXT(""));
                SetFocus(hwndEditHT);
                break;
            case ID_CHKMUSIC:
                if (SendMessage(hwndChkMusic, BM_GETCHECK, 0, 0) == FALSE)
                    SendMessage(hwndChkMusic, BM_SETCHECK, 1, 0);
                else 
                    SendMessage(hwndChkMusic, BM_SETCHECK, 0, 0);
                break;
            case ID_BTNCLOSE:
                SendMessage(hWnd, WM_CLOSE, 0, 0);
                break;
            case ID_BTNOK:
                count = 0;
                len = GetWindowText(hwndEditHT, hoten, 30);
                if (len == 0)
                {
                    MessageBox(NULL, TEXT("Please enter your name!"), TEXT("MS"), MB_OK);
                    SetFocus(hwndEditHT);
                    return 0;
                }
                if (SendMessage(hwndChkMusic, BM_GETCHECK, 0, 0) == TRUE)
                    count++;
                if (SendMessage(hwndChkGame, BM_GETCHECK, 0, 0) == TRUE)
                    count++;
                if (SendMessage(hwndTSShopping, BM_GETCHECK, 0, 0) == 1)
                    count++;
                if (count < 2) {
                    MessageBox(NULL, TEXT("Please check from 2 to 3 options!"), TEXT("MS"), MB_OK);
                    return 0;
                }
                wsprintfW(kq, L"%d has registered successfully", count);


                MessageBox(NULL, kq, TEXT("MS"), MB_OK);
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
