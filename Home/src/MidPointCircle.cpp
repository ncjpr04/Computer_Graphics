#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 1 - r; // Decision parameter

    // Draw the initial points
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);

    // Mid-point circle drawing algorithm
    while (x < y) {
        x++;
        if (d < 0) {
            d += 2 * x + 1; // Move to the next point
        } else {
            y--;
            d += 2 * (x - y) + 1; // Move to the next point
        }

        // Draw the points in all octants
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set background color
    setbkcolor(BLACK);
    cleardevice();

    // Draw a circle using the Mid-Point Circle Algorithm
    int xc = 300, yc = 300, r = 100; // Center and radius
    drawCircle(xc, yc, r);

    // Display information
    outtextxy(200, 450, "Circle drawn using Mid-Point Circle Algorithm");

    // Wait for user input
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(50, 400, "Press any key to exit...");
    
    getch();
    closegraph();
    return 0;
} 