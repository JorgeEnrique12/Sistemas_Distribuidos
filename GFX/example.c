/*
A simple example of using the gfx library.
CSE 20211
9/7/2011
by Prof. Thain
*/

#include <stdio.h>
#include "gfx.h"
#include <unistd.h>

int main()
{
	int ysize = 600;
	int xsize = 600;

	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	// Set the current drawing color to green.
	gfx_color(0,200,100);

	// Draw a triangle on the screen.


    int i = 1;
	while(1) {
        
		gfx_line(100,100+i,200,100);
        gfx_flush();
        i+=10;
        sleep(1);
	}

	return 0;
}
