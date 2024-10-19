#ifndef INCLUDED_UITOOLKIT_VIEW_H
#define INCLUDED_UITOOLKIT_VIEW_H

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

#ifndef INCLUDED_UITOOLKIT_TYPES_H
#include <uiToolkit_Types.h>
#endif /*INCLUDED_UITOOLKIT_TYPES_H*/


/* -------------------------------------------------------------------------------------------------------------- */
/*  */

uiSize_T* uiToolkit_GetScreenMetrics(uiSize_T* size);

uiRect_T * uiToolkit_GetWindowRect(void* windowHandle, uiRect_T * position);

void uiToolkit_MoveWindowToScreenCenter(void* windowHandle);

#endif /*INCLUDED_UITOOLKIT_VIEW_H*/
