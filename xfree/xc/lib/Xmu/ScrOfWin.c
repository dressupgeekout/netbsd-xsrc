/* $TOG: ScrOfWin.c /main/4 1998/02/06 15:44:48 kaleb $ */

/*

Copyright 1989, 1998  The Open Group

All Rights Reserved.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

*/
/* $XFree86: xc/lib/Xmu/ScrOfWin.c,v 1.5 1998/10/03 09:06:32 dawes Exp $ */

/*
 * Author:  Jim Fulton, MIT X Consortium
 */

#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xmu/WinUtil.h>

Screen *
XmuScreenOfWindow(Display *dpy, Window w)
{
    register int i;
    Window root;
    int x, y;					/* dummy variables */
    unsigned int width, height, bw, depth;	/* dummy variables */

    if (!XGetGeometry (dpy, w, &root, &x, &y, &width, &height,
		       &bw, &depth)) {
	return NULL;
    }
    for (i = 0; i < ScreenCount (dpy); i++) {	/* find root from list */
	if (root == RootWindow (dpy, i)) {
	    return ScreenOfDisplay (dpy, i);
	}
    }
    return NULL;
}

