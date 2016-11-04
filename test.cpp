/**
 * test.cpp
 *
 * EECS 183, Fall 2016
 * Assignment 4
 *
 * Francis Fiore
 * ffiore
 *
 * tests class Point and all its member functions
 */

#include <iostream>
#include <fstream>
using namespace std;

//so member functions of point can be used and so DIMENSION can be used
#include "Point.h"
#include "utility.h"

void test_point();

int main() {
    test_point();

    return 0;
}

void test_point() {
    //tests constructor #1
    Point pt1;
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (0, 0)" << endl;
    
    //Tests setX and setY with a variety of valid and invalid values
    pt1.setX(15);
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (15, 0)" << endl;
    
    pt1.setY(25);
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (15, 25)" << endl;
    
    pt1.setX(-3);
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (0, 25)" << endl;
    
    pt1.setY(-6);
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (0, 0)" << endl;
    
    pt1.setX(DIMENSION);
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (" << DIMENSION - 1 << ", 0)" << endl;
    
    pt1.setX(0);
    pt1.setY(DIMENSION);
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (0, " << DIMENSION - 1 << ")" << endl;
    
    pt1.setY(0);
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (0, 0)" << endl;
    
    
    cout << "---" << endl;
    
    
    //tests read member functions with valid and valid x and y values
    ifstream input_file;
    input_file.open("data1.txt");
    pt1.read(input_file);
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (42, 5)" << endl;
    
    pt1.read(input_file);
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (50, 0)" << endl;
    
    pt1.read(input_file);
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (99, 0)" << endl;
    
    pt1.read(input_file);
    cout << "pt1 is:    " << pt1 << endl;
    cout << "should be: (0, 0)" << endl;
    
    input_file.close();
    
    
    cout << "---" << endl;
    
    
    //tests constructor with given x,y inputs
    Point pt2(15, 25);
    cout << "pt2 is:    " << pt2 << endl;
    cout << "should be: (15, 25)" << endl;
    
    //tests getX and getY member functions
    cout << "x is:      " << pt2.getX() << endl;
    cout << "should be: 15" << endl;
    
    cout << "y is:      " << pt2.getY() << endl;
    cout << "should be: 25" << endl;

    
    return;
}
