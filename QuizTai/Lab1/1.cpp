#include <iostream>
#include <math.h>
using namespace std;


class Point
{
private:
    double x, y;

public:
    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point(double x, double y)
    {
        /*  
         * STUDENT ANSWER
         */
         this->x = x;
         this->y = y;
    }

    void setX(double x)
    {
        /*  
         * STUDENT ANSWER
         */
         this->x = x;
    }

    void setY(double y)
    {
        /*  
         * STUDENT ANSWER
         */
         this->y = y;
    }

    double getX() const
    {
        /*  
         * STUDENT ANSWER
         */
         return x;
    }

    double getY() const
    {
        /*  
         * STUDENT ANSWER
         */
         return y;
    }

    double distanceToPoint(const Point& pointA)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: calculate the distance from this point to point A in the coordinate plane
         */
         double disX = x - pointA.x;
         double disY = y - pointA.y;
         return sqrt(disX * disX + disY * disY);
    }
};