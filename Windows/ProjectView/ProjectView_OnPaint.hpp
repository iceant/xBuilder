#ifndef INCLUDED_PROJECTVIEW_ONPAINT_HPP
#define INCLUDED_PROJECTVIEW_ONPAINT_HPP

#ifndef INCLUDED_WINDOWS_H
#define INCLUDED_WINDOWS_H
#include <windows.h>
#endif /*INCLUDED_WINDOWS_H*/

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

void ProjectView_OnPaint(HWND hwnd){
    PAINTSTRUCT PaintStruct;
    RECT Rect;
    HDC PaintDC = BeginPaint(hwnd, &PaintStruct);
    SetBkColor(PaintDC, GetSysColor(COLOR_WINDOW));
    HFONT OldFont = SelectFont(PaintDC, GetStockObject(OEM_FIXED_FONT));
    GetClientRect(hwnd, &Rect);
    Rect.top = 5;
    DrawText(PaintDC, "This is ProjectView", -1, &Rect, DT_CENTER);
    SelectFont(PaintDC, OldFont);
    
    EndPaint(hwnd, &PaintStruct);
}


#endif /* INCLUDED_PROJECTVIEW_ONPAINT_HPP */
