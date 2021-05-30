#ifndef POINT_H
#define POINT_H

struct Point {
    unsigned int x;
    unsigned int y;
    Point();
    Point(unsigned int x, unsigned int y);
    bool operator==(Point point);
};

#endif
