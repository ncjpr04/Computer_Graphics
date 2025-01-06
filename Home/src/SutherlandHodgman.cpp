#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

struct Point {
    float x, y;
};

// Function to check if a point is inside the clipping window
bool inside(Point p, float xMin, float yMin, float xMax, float yMax) {
    return (p.x >= xMin && p.x <= xMax && p.y >= yMin && p.y <= yMax);
}

// Function to compute the intersection point of two lines
Point computeIntersection(Point p1, Point p2, float xMin, float yMin, float xMax, float yMax) {
    Point intersection;
    float slope = (p2.y - p1.y) / (p2.x - p1.x);
    if (p1.x < xMin) { // Clipping against left edge
        intersection.x = xMin;
        intersection.y = p1.y + slope * (xMin - p1.x);
    } else if (p1.x > xMax) { // Clipping against right edge
        intersection.x = xMax;
        intersection.y = p1.y + slope * (xMax - p1.x);
    } else if (p1.y < yMin) { // Clipping against bottom edge
        intersection.y = yMin;
        intersection.x = p1.x + (1 / slope) * (yMin - p1.y);
    } else if (p1.y > yMax) { // Clipping against top edge
        intersection.y = yMax;
        intersection.x = p1.x + (1 / slope) * (yMax - p1.y);
    }
    return intersection;
}

// Sutherland-Hodgman polygon clipping algorithm
void sutherlandHodgmanClip(Point* polygon, int* n, float xMin, float yMin, float xMax, float yMax) {
    Point output[10]; // Output polygon
    int outCount = 0;

    for (int edge = 0; edge < 4; edge++) {
        Point p1 = polygon[*n - 1]; // Previous vertex
        outCount = 0;

        for (int i = 0; i < *n; i++) {
            Point p2 = polygon[i]; // Current vertex

            if (inside(p2, xMin, yMin, xMax, yMax)) {
                if (!inside(p1, xMin, yMin, xMax, yMax)) {
                    output[outCount++] = computeIntersection(p1, p2, xMin, yMin, xMax, yMax);
                }
                output[outCount++] = p2; // Add current vertex
            } else if (inside(p1, xMin, yMin, xMax, yMax)) {
                output[outCount++] = computeIntersection(p1, p2, xMin, yMin, xMax, yMax);
            }
            p1 = p2; // Move to the next vertex
        }
        *n = outCount; // Update the number of vertices
        for (int j = 0; j < outCount; j++) {
            polygon[j] = output[j]; // Update the polygon
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set background color
    setbkcolor(BLACK);
    cleardevice();

    // Define clipping window
    float xMin = 150, yMin = 150, xMax = 400, yMax = 300;
    rectangle(xMin, yMin, xMax, yMax); // Draw the clipping window

    // Define a polygon
    Point polygon[10] = {{100, 100}, {200, 50}, {300, 150}, {250, 250}, {150, 200}};
    int n = 5; // Number of vertices

    // Draw the original polygon
    setcolor(WHITE);
    for (int i = 0; i < n; i++) {
        line(polygon[i].x, polygon[i].y, polygon[(i + 1) % n].x, polygon[(i + 1) % n].y);
    }

    // Clip the polygon
    sutherlandHodgmanClip(polygon, &n, xMin, yMin, xMax, yMax);

    // Draw the clipped polygon
    setcolor(YELLOW);
    for (int i = 0; i < n; i++) {
        line(polygon[i].x, polygon[i].y, polygon[(i + 1) % n].x, polygon[(i + 1) % n].y);
    }

    // Display information
    outtextxy(150, 350, "Sutherland-Hodgman Polygon Clipping");

    // Wait for user input
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(50, 400, "Press any key to exit...");

    getch();
    closegraph();
    return 0;
} 