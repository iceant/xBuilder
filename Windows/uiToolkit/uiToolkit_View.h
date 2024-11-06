#ifndef INCLUDED_UITOOLKIT_VIEW_H
#define INCLUDED_UITOOLKIT_VIEW_H

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

#ifndef INCLUDED_UITOOLKIT_TYPES_H
#include <uiToolkit_Types.h>
#endif /*INCLUDED_UITOOLKIT_TYPES_H*/

#ifndef INCLUDED_WINDOWS_H
#define INCLUDED_WINDOWS_H
#include <windows.h>
#endif /*INCLUDED_WINDOWS_H*/


/* -------------------------------------------------------------------------------------------------------------- */
/*  */

uiSize_T* uiToolkit_GetScreenMetrics(uiSize_T* size);

uiRect_T * uiToolkit_GetWindowRect(void* windowHandle, uiRect_T * position);

void uiToolkit_MoveWindowToScreenCenter(void* windowHandle);

void uiToolkit_FitParent(HWND hwnd, HWND parent);

#endif /*INCLUDED_UITOOLKIT_VIEW_H*/
