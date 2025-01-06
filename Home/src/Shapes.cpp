#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    // Set background color
    setbkcolor(BLACK);
    cleardevice();
    
    // Draw Lines with different styles and colors
    setcolor(RED);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(50, 50, 200, 50);
    outtextxy(60, 30, "Solid Line");
    
    setcolor(GREEN);
    setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
    line(50, 100, 200, 100);
    outtextxy(60, 80, "Dotted Line");
    
    setcolor(BLUE);
    setlinestyle(DASHED_LINE, 0, NORM_WIDTH);
    line(50, 150, 200, 150);
    outtextxy(60, 130, "Dashed Line");
    
    // Draw Circles with different fill styles
    setcolor(YELLOW);
    circle(350, 100, 50);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(350, 100, YELLOW);
    outtextxy(310, 30, "Solid Fill Circle");
    
    setcolor(MAGENTA);
    circle(350, 250, 50);
    setfillstyle(HATCH_FILL, MAGENTA);
    floodfill(350, 250, MAGENTA);
    outtextxy(310, 180, "Hatch Fill Circle");
    
    // Draw Ellipses with different angles
    setcolor(CYAN);
    ellipse(100, 300, 0, 360, 70, 30);
    setfillstyle(LINE_FILL, CYAN);
    floodfill(100, 300, CYAN);
    outtextxy(60, 350, "Full Ellipse");
    
    setcolor(WHITE);
    ellipse(250, 300, 0, 180, 70, 30);
    outtextxy(210, 350, "Semi Ellipse");
    
    // Display attributes information
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(50, 400, "Press any key to exit...");
    
    getch();
    closegraph();
    return 0;
} 