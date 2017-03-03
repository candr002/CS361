#include "classDefs.h"
#include <list>

bool checker(list<surface>::iterator itr);
double numberGen(list<surface>::iterator itr);


int main()
{
    bool checkVal;
    double tempVal;
    list<surface> plane;
    list<surface>::iterator planeItr = plane.begin();
    list<surface>::iterator planeStart = plane.begin();
    point tempPoint1, tempPoint2, tempPoint3, tempPoint4, tempPoint5;
    ofstream outfile;
    ofstream outdat;
    outfile.open ("command.txt");
    outdat.open ("data.txt");

    tempPoint1.setX(0);
    tempPoint1.setY(0);
    tempPoint1.setZ(0);

    tempPoint2.setX(100);
    tempPoint2.setY(0);
    tempPoint2.setZ(0);

    tempPoint3.setX(100);
    tempPoint3.setY(100);
    tempPoint3.setZ(0);

    tempPoint4.setX(0);
    tempPoint4.setY(100);
    tempPoint4.setZ(0);

    tempPoint5.setX(50);
    tempPoint5.setY(50);
    tempPoint5.setZ(200);

    plane.push_front(surface(tempPoint1,tempPoint2,tempPoint5));
    planeItr = plane.begin();



    planeItr = plane.begin();
    checkVal = checker(planeItr);

        while (checkVal == true)
       {
        tempPoint1 = planeItr->getX();
        tempPoint2 = planeItr->getY();
        tempPoint3 = planeItr->getZ();
        tempPoint4 = planeItr->getC();

        ///tempVal = tempPoint4.getX()+numberGen(planeItr);
        ///tempPoint4.setX(tempVal);

        ///tempVal = (tempPoint4.getY()+numberGen(planeItr));
        ///tempPoint4.setY(tempVal);
        ///tempVal = (tempPoint4.getZ()+numberGen(planeItr));
        ///tempPoint4.setZ(tempVal);
        plane.push_back(surface(tempPoint1, tempPoint2, tempPoint4));
        plane.push_back(surface(tempPoint4, tempPoint2, tempPoint3));
        plane.push_back(surface(tempPoint1, tempPoint4, tempPoint3));

        plane.pop_front();
        checkVal = checker(planeItr);
    }

    planeItr = plane.begin();

    while(planeItr != plane.end())
    {

        tempPoint1 = planeItr->getX();
        tempPoint2 = planeItr->getY();
        tempPoint3 = planeItr->getZ();

        outdat << trunc(tempPoint1.getX()) << " " << trunc(tempPoint1.getY()) << " " << trunc(tempPoint1.getZ()) << endl;
        outdat << trunc(tempPoint2.getX()) << " " << trunc(tempPoint2.getY()) << " " << trunc(tempPoint2.getZ()) << endl;
        outdat << trunc(tempPoint3.getX()) << " " << trunc(tempPoint3.getY()) << " " << trunc(tempPoint3.getZ()) << endl;
        outdat << trunc(tempPoint1.getX()) << " " << trunc(tempPoint1.getY()) << " " << trunc(tempPoint1.getZ()) << endl;

        planeItr++;
    }


    outfile << "clear" << endl ;
    outfile << "reset" << endl ;
    outfile << "set hidden" << endl ;
    ///outfile << "set pm3d" << endl ;
    ///outfile << "set surface" << endl ;
    //outfile << "set dgrid3d" << endl;
    outfile << "set xrange [0:200]" << endl;
    outfile << "set yrange [0:200]" << endl;
    outfile << "set zrange [0:200]" << endl;
    outfile << "splot \"data.txt\" with lines" << endl;
    outfile << "pause -1";


    outfile.close();
    outdat.close();

    system("gnuplot command.txt ");

    return 0;
}





bool checker(list<surface>::iterator itr)
{
    double xVal,yVal,zVal, val, maxVal =35;
    point X,Y,Z,C;

    X= itr->getX();
    Y= itr->getY();
    Z= itr->getZ();
    C= itr->getC();

    xVal = abs(trunc(sqrt(((pow(X.getX() - C.getX(), 2))-(pow(X.getY() - C.getY(), 2))-(pow(X.getZ() - C.getZ(), 2))))));
    yVal = abs(trunc(sqrt(((pow(Y.getX() - C.getX(), 2))-(pow(Y.getY() - C.getY(), 2))-(pow(Y.getZ() - C.getZ(), 2))))));
    zVal = abs(trunc(sqrt(((pow(Z.getX() - C.getX(), 2))-(pow(Z.getY() - C.getY(), 2))-(pow(Z.getZ() - C.getZ(), 2))))));

    if ((xVal <= maxVal) || (yVal <= maxVal) || (zVal <= maxVal))
        return false;
    else
        return true;
}


double numberGen(list<surface>::iterator itr)
{
        double xVal,yVal,zVal, val, shiftVal;
        point X,Y,Z,C;

    X= itr->getX();
    Y= itr->getY();
    Z= itr->getZ();
    C= itr->getC();

    xVal = abs(trunc(sqrt(((pow(X.getX() - C.getX(), 2))-(pow(X.getY() - C.getY(), 2))-(pow(X.getZ() - C.getZ(), 2))))));
    yVal = abs(trunc(sqrt(((pow(Y.getX() - C.getX(), 2))-(pow(Y.getY() - C.getY(), 2))-(pow(Y.getZ() - C.getZ(), 2))))));
    zVal = abs(trunc(sqrt(((pow(Z.getX() - C.getX(), 2))-(pow(Z.getY() - C.getY(), 2))-(pow(Z.getZ() - C.getZ(), 2))))));

    shiftVal = trunc(abs(xVal+yVal+zVal)/2);
    default_random_engine gen;
    uniform_real_distribution<double> rando ((-shiftVal),(shiftVal));

    return rando(gen);
}
