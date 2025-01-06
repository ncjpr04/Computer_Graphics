#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void drawEllipse(int xc, int yc, int a, int b) {
    int x = 0, y = b;
    int d1 = (b * b) - (a * a * b) + (0.25 * a * a);
    int d2 = (b * b) * (x + 1) * (x + 1) + (a * a) * (y - 1) * (y - 1) - (a * a * b * b);

    // Draw the ellipse using the midpoint algorithm
    while ((a * a * y) > (b * b * x)) {
        // Plot the points in all four quadrants
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        // Decision parameter for region 1
        if (d1 < 0) {
            d1 += (2 * b * b * x) + (b * b);
        } else {
            y--;
            d1 += (2 * b * b * x) + (b * b) - (2 * a * a * y);
        }
        x++;
    }

    // Decision parameter for region 2
    while (y >= 0) {
        // Plot the points in all four quadrants
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (d2 > 0) {
            d2 += (a * a) - (2 * a * a * y);
        } else {
            x++;
            d2 += (2 * b * b * x) - (2 * a * a * y) + (a * a);
        }
        y--;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set background color
    setbkcolor(BLACK);
    cleardevice();

    // Draw an ellipse using the Midpoint Ellipse Algorithm
    int xc = 300, yc = 300; // Center of the ellipse
    int a = 150, b = 100;   // Semi-major and semi-minor axes
    drawEllipse(xc, yc, a, b);

    // Display information
    outtextxy(200, 450, "Ellipse drawn using Mid-Point Ellipse Algorithm");

    // Wait for user input
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(50, 400, "Press any key to exit...");
    
    getch();
    closegraph();
    return 0;
} 