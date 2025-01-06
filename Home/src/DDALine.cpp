#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    // Calculate the difference between the points
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate increment in x and y for each step
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    // Start from the first point
    float x = x1;
    float y = y1;

    // Draw the line
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set background color
    setbkcolor(BLACK);
    cleardevice();

    // Draw a line using DDA algorithm
    int x1 = 100, y1 = 200, x2 = 400, y2 = 300;
    drawLineDDA(x1, y1, x2, y2);

    // Display information
    outtextxy(150, 180, "Line drawn using DDA Algorithm");

    // Wait for user input
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(50, 400, "Press any key to exit...");
    
    getch();
    closegraph();
    return 0;
} 