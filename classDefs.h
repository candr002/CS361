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
#include <list>
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
    surface()
    {
        x2yFlag = false;
        x2zFlag = false;
        y2zFlag = false;
    }
    surface(point x, point y, point z)
        {
            xPoint = x;
            yPoint = y;
            zPoint = z;
            cent = centroid(xPoint,yPoint,zPoint);
            x2yFlag = false;
            x2zFlag = false;
            y2zFlag = false;
        }

    void setX(point x){xPoint = x;}
    void setY(point x){yPoint = x;}
    void setZ(point x){zPoint = x;}
    void setC(point x){cent = x;}
    void setx2y(list<surface>::iterator x){x2y = x; x2yFlag = true;}
    void setx2z(list<surface>::iterator x){x2z = x; x2zFlag = true;}
    void sety2z(list<surface>::iterator x){y2z = x; y2zFlag = true;}

    point getX(){return xPoint;}
    point getY(){return yPoint;}
    point getZ(){return zPoint;}
    point getC(){return cent;}
    list<surface>::iterator getx2y(){return x2y;}
    list<surface>::iterator getx2z(){return x2z;}
    list<surface>::iterator gety2z(){return y2z;}
    bool getx2yFlag(){return x2yFlag;}
    bool getx2zFlag(){return x2zFlag;}
    bool gety2zFlag(){return y2zFlag;}

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
    list<surface>::iterator x2y, x2z, y2z;
    bool x2yFlag, x2zFlag, y2zFlag;
};


///=======================================================================
///=======================================================================
///=======================================================================
///=======================================================================

point centroid(point x, point y, point z)
    {
        double xval, yval, zval, shiftVal, tempVal;
        point center;


        xval = abs(trunc((x.getX()+y.getX()+z.getX())/3));
        yval = abs(trunc((x.getY()+y.getY()+z.getY())/3));
        zval = abs(trunc((x.getZ()+y.getZ()+z.getZ())/3));

        shiftVal = trunc((xval + yval + zval)/3);
        default_random_engine gen(time(NULL));
        uniform_real_distribution<double> rando (-(shiftVal/3),((shiftVal/2)));
        tempVal = (rando(gen) + xval);
        center.setX(tempVal);
        tempVal = (rando(gen) + yval);
        center.setY(tempVal);
        tempVal = (rando(gen) + zval);
        center.setZ(tempVal);
        return center;
    }
void displayPoint(point x)
    {
        cout << "\nX val: " << trunc(x.getX()) << "\nY val: " << trunc(x.getY()) << "\nZ val: " << trunc(x.getZ()) << endl;
    }

///=======================================================================

point centroid(point x, point y)
    {
        double xval, yval, zval, shiftVal, tempVal;
        point center;


        xval = trunc((x.getX()+y.getX())/2);
        yval = trunc((x.getY()+y.getY())/2);
        zval = trunc((x.getZ()+y.getZ())/2);

        shiftVal = trunc((xval + yval + zval)/3);
        default_random_engine gen(time(NULL));
        uniform_real_distribution<double> rando (-(shiftVal/2),(shiftVal/2));
        tempVal = (rando(gen) + xval);
        center.setX(tempVal);
        tempVal = (rando(gen) + yval);
        center.setY(tempVal);
        tempVal = (rando(gen) + zval);
        center.setZ(tempVal);
        return center;
    }
