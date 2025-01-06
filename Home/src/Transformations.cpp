#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawShape(int x[], int y[], int n) {
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]); // Draw the shape
    }
}

void translate(int x[], int y[], int n, int tx, int ty) {
    for (int i = 0; i < n; i++) {
        x[i] += tx;
        y[i] += ty;
    }
}

void rotate(int x[], int y[], int n, float angle) {
    float rad = angle * (M_PI / 180); // Convert angle to radians
    for (int i = 0; i < n; i++) {
        float tempX = x[i];
        x[i] = (tempX * cos(rad)) - (y[i] * sin(rad));
        y[i] = (tempX * sin(rad)) + (y[i] * cos(rad));
    }
}

void scale(int x[], int y[], int n, float sx, float sy) {
    for (int i = 0; i < n; i++) {
        x[i] *= sx;
        y[i] *= sy;
    }
}

void reflect(int x[], int y[], int n) {
    for (int i = 0; i < n; i++) {
        y[i] = -y[i]; // Reflect over the x-axis
    }
}

void shear(int x[], int y[], int n, float shx, float shy) {
    for (int i = 0; i < n; i++) {
        x[i] += shx * y[i]; // Shear in x direction
        y[i] += shy * x[i]; // Shear in y direction
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

    // Apply transformations
    // Translation
    translate(x, y, n, 100, 50);
    setcolor(RED);
    drawShape(x, y, n);
    outtextxy(320, 320, "Translated Shape");

    // Rotation
    rotate(x, y, n, 45);
    setcolor(GREEN);
    drawShape(x, y, n);
    outtextxy(320, 350, "Rotated Shape");

    // Scaling
    scale(x, y, n, 1.5, 1.5);
    setcolor(BLUE);
    drawShape(x, y, n);
    outtextxy(320, 380, "Scaled Shape");

    // Reflection
    reflect(x, y, n);
    setcolor(YELLOW);
    drawShape(x, y, n);
    outtextxy(320, 410, "Reflected Shape");

    // Shear
    shear(x, y, n, 0.5, 0);
    setcolor(CYAN);
    drawShape(x, y, n);
    outtextxy(320, 440, "Sheared Shape");

    // Wait for user input
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(50, 500, "Press any key to exit...");
    
    getch();
    closegraph();
    return 0;
} 