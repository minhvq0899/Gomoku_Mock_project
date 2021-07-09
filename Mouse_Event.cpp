#include"Mouse_Event.h"


mouseData Mouse_Event::clickEventHandling()
{
    mouseData mdata;
    while (!ismouseclick(WM_LBUTTONDOWN)) {

    }
    getmouseclick(WM_LBUTTONDOWN, mdata.x, mdata.y);
    return mdata;
}


