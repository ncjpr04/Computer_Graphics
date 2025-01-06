#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawShape(int x[], int y[], int n) {
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]); // Draw the shape
    }
}

void compositeTransform(int x[], int y[], int n, float tx, float ty, float angle, float sx, float sy) {
    // Apply translation
    for (int i = 0; i < n; i++) {
        x[i] += tx;
        y[i] += ty;
    }

    // Apply rotation
    float rad = angle * (M_PI / 180); // Convert angle to radians
    for (int i = 0; i < n; i++) {
        float tempX = x[i];
        x[i] = (tempX * cos(rad)) - (y[i] * sin(rad));
        y[i] = (tempX * sin(rad)) + (y[i] * cos(rad));
    }

    // Apply scaling
    for (int i = 0; i < n; i++) {
        x[i] *= sx;
        y[i] *= sy;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set background color
    setbkcolor(BLACK);
    cleardevice();

    // Define a square shape
    int n = 4; // Number of vertices
    int x[] = {200, 300, 300, 200};
    int y[] = {200, 200, 300, 300};

    // Draw original shape
    setcolor(WHITE);
    drawShape(x, y, n);
    outtextxy(220, 320, "Original Shape");

    // Apply composite transformations
    compositeTransform(x, y, n, 100, 50, 45, 1.5, 1.5); // Translate, Rotate, Scale
    setcolor(RED);
    drawShape(x, y, n);
    outtextxy(320, 320, "Composite Transformed Shape");

    // Wait for user input
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(50, 500, "Press any key to exit...");
    
    getch();
    closegraph();
    return 0;
} 