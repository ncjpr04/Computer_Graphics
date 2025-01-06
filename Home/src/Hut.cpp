#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main() {
    int gm, x, y, gd = DETECT, i;
    int stangle = 45, endangle = 50;
    int radius = 50;

    initgraph(&gd, &gm, NULL);
    x = getmaxx();
    y = getmaxy();
    cleardevice();

    // Draw hut
    line(200, 150, 350, 150);
    line(140, 200, 200, 150);
    line(140, 330, 140, 200);
    line(250, 200, 140, 200);
    line(200, 150, 250, 200);
    circle(196, 180, 15);
    setfillstyle(2, 14);
    floodfill(196, 180, WHITE);
    setfillstyle(1, 2);
    floodfill(210, 180, WHITE);
    line(350, 150, 400, 200);
    line(400, 200, 400, 330);
    line(140, 330, 400, 330);
    line(250, 200, 250, 330);
    line(250, 200, 400, 200);

    setfillstyle(5, 7);
    floodfill(260, 180, WHITE);
    line(170, 260, 170, 330);
    line(170, 260, 210, 260);
    setfillstyle(10, 9);
    floodfill(180, 250, WHITE);
    line(210, 260, 210, 330);
    setfillstyle(9, 9);
    floodfill(210, 250, WHITE);
    line(290, 110, 290, 150);
    line(310, 110, 310, 150);
    ellipse(300, 110, 0, 360, 10, 3);

    setfillstyle(6, 8);
    floodfill(300, 120, WHITE);
    line(300, 250, 350, 250);
    line(300, 280, 350, 280);
    line(300, 250, 350, 280);
    line(300, 280, 300, 250);
    line(350, 280, 350, 250);

    setfillstyle(9, 9);
    floodfill(252, 300, WHITE);
    setfillstyle(8, 9);
    floodfill(342, 270, WHITE);

    // Draw arc
    setcolor(3);
    arc(30, 300, stangle, endangle, radius);

    // Draw base line
    setcolor(7);
    line(5, 330, 600, 330);

    // Display text animation
    for (i = 0; i < 650; i += 10) {
        setcolor(4);
        settextstyle(7, 0, 5);
        char stringData1[] = "Home Sweet Home";
        outtextxy(0 + i, 390, stringData1);
        delay(100);
        setcolor(0);
        outtextxy(0 + i, 390, stringData1);
    }

    getch();
    closegraph();

    return 0;
}
