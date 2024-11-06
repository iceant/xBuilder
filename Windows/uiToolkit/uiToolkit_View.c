#include <uiToolkit_View.h>
#include <windows.h>
#include <assert.h>

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

uiSize_T* uiToolkit_GetScreenMetrics(uiSize_T* size){
    assert(size);
    size->width = GetSystemMetrics(SM_CXSCREEN);
    size->height = GetSystemMetrics(SM_CYSCREEN);
    return size;
}

uiRect_T * uiToolkit_GetWindowRect(void* windowHandle, uiRect_T * position)
{
    assert(windowHandle);
    assert(position);
    RECT rect;
    GetWindowRect(windowHandle, &rect);

    position->right = rect.right;
    position->bottom = rect.bottom;
    position->left = rect.left;
    position->top = rect.top;

    return position;
}

void uiToolkit_MoveWindowToScreenCenter(void* windowHandle){
    uiRect_T windowPosition;
    uiSize_T screenSize;
    uiPoint_T point;

    memset(&windowPosition, 0, sizeof(windowPosition));
    memset(&screenSize, 0, sizeof(screenSize));
    memset(&point, 0, sizeof(point));


    uiToolkit_GetScreenMetrics(&screenSize);
    uiToolkit_GetWindowRect(windowHandle, &windowPosition);

    point.x = (screenSize.width - (windowPosition.right - windowPosition.left))/2;
    point.y = (screenSize.height - (windowPosition.bottom - windowPosition.top))/2;
//    windowPosition.left = point.x;
//    windowPosition.right += point.x;
//    windowPosition.top = point.y;
//    windowPosition.bottom += point.y;

    MoveWindow(windowHandle, point.x, point.y, windowPosition.right-windowPosition.left
        , windowPosition.bottom - windowPosition.top, TRUE);
}

void uiToolkit_FitParent(HWND hwnd, HWND parent){
    RECT pRect;
    RECT Rect;
    
    GetClientRect(parent, &pRect);
    GetWindowRect(hwnd, &Rect);
    
    int width = pRect.right - pRect.left - 5;
    int height = pRect.bottom - pRect.top - 5;
    
    SetWindowPos(hwnd, 0, 1, 1, width, height, SWP_SHOWWINDOW);
    UpdateWindow(hwnd);
}
