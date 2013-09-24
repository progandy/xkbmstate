/**
 * Copyright (c) 2013 Andreas Bosch [code AT progandy DOT de]
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**/

#include <X11/XKBlib.h>
#include <X11/extensions/XKB.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
   Display *dpy;
   int res;
   XkbStateRec state;
   
   dpy = XOpenDisplay(NULL);
   if (!dpy) {fputs("Can't open display\n", stderr); exit(1);}

   res = XkbQueryExtension(dpy, NULL, NULL, NULL, NULL, NULL);
   if (!res) {fputs("Can't init XKB\n", stderr); exit(1);}

   XkbGetState(dpy, XkbUseCoreKbd, &state);
   if ( ShiftMask & state.mods )   fputs("+Shift", stdout);
   if ( LockMask & state.mods )    fputs("+Lock", stdout);
   if ( ControlMask & state.mods ) fputs("+Control", stdout);
   if ( Mod1Mask & state.mods )    fputs("+Mod1", stdout);
   if ( Mod2Mask & state.mods )    fputs("+Mod2", stdout);
   if ( Mod3Mask & state.mods )    fputs("+Mod3", stdout);
   if ( Mod4Mask & state.mods )    fputs("+Mod4", stdout);
   if ( Mod5Mask & state.mods )    fputs("+Mod5", stdout);
   
   XCloseDisplay(dpy);
   return 0;
}

