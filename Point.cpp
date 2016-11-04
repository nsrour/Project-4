/**
 * Point.cpp
 *
 * EECS 183, Fall 2016
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

//constructor with no initial x,y inputs
Point::Point() {
    x = 0;
    y = 0;
}

//constructor with initial x,y inputs
Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

void Point::setX(int xVal) {
    x = checkRange(xVal);
}

void Point::setY(int yVal) {
    y = checkRange(yVal);
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

//reads next line in file and sets x and y as given
void Point::read(istream& ins) {
    char throwaway;
    
    ins >> throwaway;
    ins >> x;
    ins >> throwaway;
    ins >> y;
    ins >> throwaway;
    
    x = checkRange(x);
    y = checkRange(y);
}

//clears file and writes the point to it
void Point::write(ostream& outs) {
    outs << '(' << x << ", " << y << ')';
}

//makes sure the value entered is within the correct range of values
int Point::checkRange(int val) {
    
    //if the value is within the given domain, return it
    if (val >= 0 && val < DIMENSION) {
        return val;
        
        //if value is not inside domain, return closest point in domain
    } else if (val < 0) {
        return 0;
    } else {
        return DIMENSION - 1;
    }
    
}


istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}

