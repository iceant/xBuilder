#ifndef INCLUDED_XBUILDER_MAINFRAME_RC_H
#include <xBuilder_MainFrame_RC.h>
#endif /*INCLUDED_XBUILDER_MAINFRAME_RC_H*/


static void xBuilder_MainFrame_OnCommand(HWND hwnd, int Id, HWND hwndCtrl, UINT codeNotify)
{
    switch (Id) {
        case CM_ABOUT:
            MessageBoxA(hwnd, "About Content", "About", MB_OK);
            break;
        case CM_PROJECT_NEW:
            MessageBoxA(hwnd, "Project New", "Project", MB_OK);
            break;
    }
}