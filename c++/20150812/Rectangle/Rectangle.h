#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

class Shape
{
    int no;
};

class Point
{
    int x;
    int y;
};

class Rectangle: public Shape
{
    int width;
    int height;

    Point* leftUp, * rightDown;

public:
    Rectangle(int widthdth, int height, int x, int y);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    
    ~Rectangle();

};


#endif
