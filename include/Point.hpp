#ifndef POINT_H
#define POINT_H

struct Point {
    int x;
    int y;
    Point();
    Point(int x, int y);
    bool operator==(Point point);
};

#endif
