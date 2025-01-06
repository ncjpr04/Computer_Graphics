#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

#define TOP 1
#define BOTTOM 2
#define RIGHT 4
#define LEFT 8

// Function to compute the region code for a point
int computeCode(float x, float y, float xMin, float yMin, float xMax, float yMax) {
    int code = 0;
    if (x < xMin) code |= LEFT;    // to the left of the window
    else if (x > xMax) code |= RIGHT; // to the right of the window
    if (y < yMin) code |= BOTTOM;  // below the window
    else if (y > yMax) code |= TOP; // above the window
    return code;
}

// Cohen-Sutherland line clipping algorithm
void cohenSutherlandClip(float x1, float y1, float x2, float y2, float xMin, float yMin, float xMax, float yMax) {
    int code1 = computeCode(x1, y1, xMin, yMin, xMax, yMax);
    int code2 = computeCode(x2, y2, xMin, yMin, xMax, yMax);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) {
            // Both points inside the rectangle
            accept = true;
            break;
        } else if (code1 & code2) {
            // Both points outside the rectangle
            break;
        } else {
            // At least one point is outside the rectangle
            int codeOut = code1 ? code1 : code2;
            float x, y;

            // Find the intersection point
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            // Replace outside point with intersection point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xMin, yMin, xMax, yMax);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, xMin, yMin, xMax, yMax);
            }
        }
    }

    if (accept) {
        // Draw the accepted line
        setcolor(WHITE);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set background color
    setbkcolor(BLACK);
    cleardevice();

    // Define clipping window
    float xMin = 100, yMin = 100, xMax = 400, yMax = 300;
    rectangle(xMin, yMin, xMax, yMax); // Draw the clipping window

    // Define line coordinates
    float x1 = 50, y1 = 150, x2 = 450, y2 = 200; // Line outside the window
    cohenSutherlandClip(x1, y1, x2, y2, xMin, yMin, xMax, yMax);

    // Display information
    outtextxy(150, 350, "Cohen-Sutherland Line Clipping");

    // Wait for user input
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(50, 400, "Press any key to exit...");

    getch();
    closegraph();
    return 0;
} 