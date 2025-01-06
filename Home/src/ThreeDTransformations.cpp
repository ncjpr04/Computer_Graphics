#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point3D {
    float x, y, z;
};

void draw3DShape(Point3D* points, int n) {
    for (int i = 0; i < n; i++) {
        // Project 3D points to 2D for display
        int x1 = (int)(points[i].x);
        int y1 = (int)(points[i].y);
        int x2 = (int)(points[(i + 1) % n].x);
        int y2 = (int)(points[(i + 1) % n].y);
        line(x1 + 300, 300 - y1, x2 + 300, 300 - y2); // Adjust for center
    }
}

void translate(Point3D* points, int n, float tx, float ty, float tz) {
    for (int i = 0; i < n; i++) {
        points[i].x += tx;
        points[i].y += ty;
        points[i].z += tz;
    }
}

void rotate(Point3D* points, int n, float angleX, float angleY, float angleZ) {
    float radX = angleX * (M_PI / 180);
    float radY = angleY * (M_PI / 180);
    float radZ = angleZ * (M_PI / 180);

    for (int i = 0; i < n; i++) {
        // Rotation around X-axis
        float y = points[i].y * cos(radX) - points[i].z * sin(radX);
        float z = points[i].y * sin(radX) + points[i].z * cos(radX);
        points[i].y = y;
        points[i].z = z;

        // Rotation around Y-axis
        float x = points[i].x * cos(radY) + points[i].z * sin(radY);
        z = -points[i].x * sin(radY) + points[i].z * cos(radY);
        points[i].x = x;
        points[i].z = z;

        // Rotation around Z-axis
        x = points[i].x * cos(radZ) - points[i].y * sin(radZ);
        y = points[i].x * sin(radZ) + points[i].y * cos(radZ);
        points[i].x = x;
        points[i].y = y;
    }
}

void scale(Point3D* points, int n, float sx, float sy, float sz) {
    for (int i = 0; i < n; i++) {
        points[i].x *= sx;
        points[i].y *= sy;
        points[i].z *= sz;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set background color
    setbkcolor(BLACK);
    cleardevice();

    // Define a 3D shape (a square pyramid)
    int n = 5; // Number of vertices
    Point3D points[5] = {
        {0, 0, 0},   // Base vertex 1
        {100, 0, 0}, // Base vertex 2
        {100, 100, 0}, // Base vertex 3
        {0, 100, 0}, // Base vertex 4
        {50, 50, 100} // Apex vertex
    };

    // Draw original shape
    setcolor(WHITE);
    draw3DShape(points, 4); // Draw base
    line(points[0].x + 300, 300 - points[0].y, points[4].x + 300, 300 - points[4].y);
    line(points[1].x + 300, 300 - points[1].y, points[4].x + 300, 300 - points[4].y);
    line(points[2].x + 300, 300 - points[2].y, points[4].x + 300, 300 - points[4].y);
    line(points[3].x + 300, 300 - points[3].y, points[4].x + 300, 300 - points[4].y);

    // Apply transformations
    translate(points, n, 50, 50, 0); // Translate
    setcolor(RED);
    draw3DShape(points, 4); // Draw base after translation
    line(points[0].x + 300, 300 - points[0].y, points[4].x + 300, 300 - points[4].y);
    line(points[1].x + 300, 300 - points[1].y, points[4].x + 300, 300 - points[4].y);
    line(points[2].x + 300, 300 - points[2].y, points[4].x + 300, 300 - points[4].y);
    line(points[3].x + 300, 300 - points[3].y, points[4].x + 300, 300 - points[4].y);

    rotate(points, n, 45, 0, 0); // Rotate around X-axis
    setcolor(GREEN);
    draw3DShape(points, 4); // Draw base after rotation
    line(points[0].x + 300, 300 - points[0].y, points[4].x + 300, 300 - points[4].y);
    line(points[1].x + 300, 300 - points[1].y, points[4].x + 300, 300 - points[4].y);
    line(points[2].x + 300, 300 - points[2].y, points[4].x + 300, 300 - points[4].y);
    line(points[3].x + 300, 300 - points[3].y, points[4].x + 300, 300 - points[4].y);

    scale(points, n, 1.5, 1.5, 1.5); // Scale
    setcolor(BLUE);
    draw3DShape(points, 4); // Draw base after scaling
    line(points[0].x + 300, 300 - points[0].y, points[4].x + 300, 300 - points[4].y);
    line(points[1].x + 300, 300 - points[1].y, points[4].x + 300, 300 - points[4].y);
    line(points[2].x + 300, 300 - points[2].y, points[4].x + 300, 300 - points[4].y);
    line(points[3].x + 300, 300 - points[3].y, points[4].x + 300, 300 - points[4].y);

    // Wait for user input
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(50, 500, "Press any key to exit...");
    
    getch();
    closegraph();
    return 0;
} 