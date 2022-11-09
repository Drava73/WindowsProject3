#include <Windows.h>
#include <tchar.h>
int count_lbutton = 0;  
int count_rbutton = 0;  
int cout_mbutton = 0;  
char info[4096];  
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine,
    int nCmdShow)
{

    HWND hWnd;
    MSG lpMsg;
    WNDCLASSEX wcl;
     
    wcl.cbSize = sizeof(wcl); 
    wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS; 
    wcl.lpfnWndProc = WindowProc;
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
    wcl.hInstance = hInst;
    wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcl.hCursor = LoadCursor(NULL, IDC_HAND);
    wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcl.lpszMenuName = NULL;
    wcl.lpszClassName = szClassWindow;
    wcl.hIconSm = NULL;
    
    if (!RegisterClassEx(&wcl))
        return 0;
      
    hWnd = CreateWindowEx(
        0,
        szClassWindow,
        TEXT("Каркас приложение Windows"),
        WS_OVERLAPPEDWINDOW,
        200,
        200,
        500,
        500,
        NULL,
        NULL,
        hInst,
        NULL);
    
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&lpMsg, NULL, 0, 0))
    {
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
    switch (uMessage)
    {
    case WM_LBUTTONDOWN:
        count_lbutton++;  
        MessageBox(0, TEXT("Нажата левая кнопка мыши"), TEXT("WM_LBUTTON"), MB_OK | MB_ICONINFORMATION);
        sprintf(info, "lbutton: %d rbutton: %d mbutton: %d", count_lbutton, count_rbutton, cout_mbutton);  
        SetWindowText(hWnd, info);  

        break;
    case WM_RBUTTONDOWN:
        count_rbutton++;
        MessageBox(0, TEXT("нажата правая кнопка мыши"), TEXT("WM_RBUTTON"), MB_OK | MB_ICONINFORMATION);
        sprintf(info, "lbutton: %d rbutton: %d mbutton: %d", count_lbutton, count_rbutton, cout_mbutton);
        SetWindowText(hWnd, info);
        break;
    case WM_MBUTTONDOWN:
        cout_mbutton++;
        MessageBox(0, TEXT("Нажата средняя кнопка мыши"), TEXT("WM_MBUTTON"), MB_OK | MB_ICONINFORMATION);
        sprintf(info, "lbutton: %d rbutton: %d mbutton: %d", count_lbutton, count_rbutton, cout_mbutton);
        SetWindowText(hWnd, info);
        break;
    case WM_DESTROY:
        sprintf(info, "lbutton: %d rbutton: %d mbutton: %d", count_lbutton, count_rbutton, cout_mbutton);
        MessageBox(0, info, "LOG", 0);  
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, uMessage, wParam, lParam);
    }
    return 0;
}