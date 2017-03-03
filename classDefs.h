///***********************************************************
/// Author: Chris Andrzejewski
/// Date: 1 Mar 2016
/// Program: Class Assignment 2 (Draw a Canyon)
///***********************************************************
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <random>
#include <iterator>
using namespace std;


class point
{
public:
    point(){};
    point(double x, double y, double z)
        {
            xVal = x;
            yVal = y;
            zVal = z;
        }

    void setX(double x){xVal = x;}
    void setY(double x){yVal = x;}
    void setZ(double x){zVal = x;}

    double getX(){return xVal;}
    double getY(){return yVal;}
    double getZ(){return zVal;}

private:
    double xVal, yVal, zVal;
};
///=========================================================
///=========================================================

point centroid(point x, point y, point z);
void displayPoint(point x);


///=========================================================

class surface
{
public:
    surface(point x, point y, point z)
        {
            xPoint = x;
            yPoint = y;
            zPoint = z;
            cent = centroid(xPoint,yPoint,zPoint);
        }

    void setX(point x){xPoint = x;}
    void setY(point x){yPoint = x;}
    void setZ(point x){zPoint = x;}
    void setC(point x){cent = x;}

    point getX(){return xPoint;}
    point getY(){return yPoint;}
    point getZ(){return zPoint;}
    point getC(){return cent;}

    void displayPoints()
    {
        cout << "Point1: ";
        displayPoint(xPoint);
        cout << "Point2: ";
        displayPoint(yPoint);
        cout << "Point3: ";
        displayPoint(zPoint);
        cout << "Point4: ";
        displayPoint(cent);

    }

private:
    point xPoint, yPoint, zPoint, cent;
};


///=======================================================================
///=======================================================================
///=======================================================================
///=======================================================================

point centroid(point x, point y, point z)
    {
        double val;
        point center;

        center.setX(trunc((x.getX()+y.getX()+z.getX())/3));
        center.setY(trunc((x.getY()+y.getY()+z.getY())/3));
        center.setZ(trunc((x.getZ()+y.getZ()+z.getZ())/3));

        return center;
    }
void displayPoint(point x)
    {
        cout << "\nX val: " << trunc(x.getX()) << "\nY val: " << trunc(x.getY()) << "\nZ val: " << trunc(x.getZ()) << endl;
    }
