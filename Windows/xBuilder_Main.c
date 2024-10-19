#include <xBuilder_Main.h>
#include <windows.h>
#include <windowsx.h>
#include <xBuilder_MainFrame.h>
#include <uiToolkit_View.h>
/* -------------------------------------------------------------------------------------------------------------- */
/*  */

static HWND xBuilder_Main__MainFrame;

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow){
    MSG Msg;

    if(!hPrevInstance){
        if(!xBuilder_MainFrame_Register(hInstance)){
            return FALSE;
        }
    }


    xBuilder_Main__MainFrame = xBuilder_MainFrame_Create(hInstance, 10, 10, 600, 400);
    if(!xBuilder_Main__MainFrame){
        return FALSE;
    }

    uiToolkit_MoveWindowToScreenCenter(xBuilder_Main__MainFrame);
    xBuilder_MainFrame_Show(xBuilder_Main__MainFrame, nCmdShow);

    while(GetMessage(&Msg, NULL, 0, 0)){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}
