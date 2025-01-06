#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    // Set background color
    setbkcolor(BLACK);
    cleardevice();
    
    // Set color for the point
    setcolor(WHITE);
    
    // Plot a point at (200, 200)
    int x = 200;
    int y = 200;
    putpixel(x, y, WHITE);
    
    // Display information
    const char* message = "Point plotted at (200, 200)";
    outtextxy(150, 180, const_cast<char*>(message));
    
    // Display attributes information
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    const char* exitMessage = "Press any key to exit...";
    outtextxy(50, 400, const_cast<char*>(exitMessage));
    
    getch();
    closegraph();
    return 0;
} 