#include <xBuilder_Main.h>
#include <windows.h>
#include <MainFrame.h>
#include <assert.h>
#include <ProjectView.h>
/* -------------------------------------------------------------------------------------------------------------- */
/*  */

HWND MainFrame_HWND;
HWND ProjectView_HWND;

static BOOL Register(HINSTANCE hInstance){
    BOOL ret =  MainFrame_Register(hInstance);
    if(!ret) return ret;
    ret = ProjectView_Register(hInstance);
    if(!ret) return ret;
    return TRUE;
}
/* -------------------------------------------------------------------------------------------------------------- */
/*  */

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow){
    MSG Msg;
    
    if(!hPrevInstance){
        if(!Register(hInstance)){
            return FALSE;
        }
    }
    
    MainFrame_HWND = CreateWindow(MainFrame_GetClassName(), "MainFrame"
                                , WS_OVERLAPPEDWINDOW
                                , CW_USEDEFAULT, CW_USEDEFAULT
                                , CW_USEDEFAULT, CW_USEDEFAULT
                                , NULL, NULL, hInstance, NULL);
    if(!MainFrame_HWND){
        return FALSE;
    }
    
    MainFrame_Show(MainFrame_HWND, nCmdShow);
    
    while(GetMessage(&Msg, NULL, 0, 0)){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}
