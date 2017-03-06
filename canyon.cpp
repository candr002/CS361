#include "classDefs.h"
#include <list>
bool checker(list<surface>::iterator itr);



int main()
{   default_random_engine coin(time(NULL));
    uniform_int_distribution<int> flipa(0,1);
    uniform_int_distribution<int> tossa(1,3);
    bool checkVal;

    int coinVal, d3val;
    double tempVal;
    list<surface> plane;
    list<surface>::iterator planeItr = plane.begin();
    list<surface>::iterator planeDelete = plane.begin();
    list<surface>::iterator ptr1, ptr2, ptr3;

    point tempPoint1, tempPoint2, tempPoint3, tempPoint4, tempPoint5, tempPoint6;
    ofstream outfile;
    ofstream outdat;
    outfile.open ("command.txt");
    outdat.open ("data.txt");

    tempPoint1.setX(0);
    tempPoint1.setY(0);
    tempPoint1.setZ(0);

    tempPoint2.setX(1000);
    tempPoint2.setY(0);
    tempPoint2.setZ(0);

    tempPoint3.setX(1000);
    tempPoint3.setY(0);
    tempPoint3.setZ(2000);

    tempPoint4.setX(2000);
    tempPoint4.setY(0);
    tempPoint4.setZ(2000);

    tempPoint5.setX(0);
    tempPoint5.setY(0);
    tempPoint5.setZ(2000);

    tempPoint6.setX(3000);
    tempPoint6.setY(0);
    tempPoint6.setZ(2000);

    plane.push_front(surface(tempPoint1,tempPoint2,tempPoint5));
    ptr1 = plane.begin();

    plane.push_front(surface(tempPoint5,tempPoint2,tempPoint3));
    ptr2 = plane.begin();

    plane.push_front(surface(tempPoint2,tempPoint4,tempPoint3));
    ptr3 = plane.begin();


    planeItr->setx2y(ptr2);
    planeItr++;
    planeItr->sety2z(ptr3);
    planeItr->setx2z(ptr1);
    planeItr++;
    planeItr->sety2z(ptr2);

    planeItr = plane.begin();
    checkVal = checker(planeItr);
    while (planeItr != plane.end())
    {


        while (checkVal != false)
       {

        flipa(coin);
        switch (coinVal)
        {
        case 1:
        {
            tempPoint1 = planeItr->getX();
            tempPoint2 = planeItr->getY();
            tempPoint3 = planeItr->getZ();
            tempPoint4 = planeItr->getC();
            plane.push_back(surface(tempPoint1, tempPoint2, tempPoint4));
            ptr3 = plane.end();
            ptr3--;
            plane.push_back(surface(tempPoint4, tempPoint2, tempPoint3));
            ptr2 = plane.end();
            ptr2--;
            plane.push_back(surface(tempPoint1, tempPoint4, tempPoint3));
            ptr1  = plane.end();
            ptr1--;

            ptr3->setx2y(planeItr->getx2y());
            ptr3->setx2z(ptr1);
            ptr3->sety2z(ptr2);

            ptr2->sety2z(planeItr->gety2z());
            ptr2->setx2y(ptr3);
            ptr2->setx2z(ptr1);

            ptr1->setx2z(planeItr->getx2z());
            ptr1->setx2y(ptr3);
            ptr1->sety2z(ptr2);

            planeDelete = planeItr;
            planeItr++;
            planeDelete = plane.erase(planeDelete);
            checkVal = checker(planeItr);
        }
        default:
        {
            d3val = tossa(coin);
            switch (d3val)
            {
            case 1:
                {
                    if (planeItr->getx2zFlag() == false)
                        d3val++;
                    else
                    {
                        ptr1 = planeItr->getx2z();
                        tempPoint1 = ptr1->getX();
                        tempPoint2 = ptr1->getZ();
                        tempPoint3 = ptr1->getY();
                        tempPoint4 = planeItr->getY();
                        tempVal = ((tempPoint2.getX()+tempPoint3.getX())/2);
                        tempPoint5.setX(tempVal);
                        tempVal = ((tempPoint2.getY()+tempPoint3.getY())/2);
                        tempPoint5.setY(tempVal);
                        tempVal = ((tempPoint2.getZ()+tempPoint3.getZ())/2);
                        tempPoint5.setZ(tempVal);
                        tempPoint5 = centroid(tempPoint2,tempPoint3);
                        plane.push_back(surface(tempPoint1,tempPoint3,tempPoint5));
                        plane.push_back(surface(tempPoint1,tempPoint5,tempPoint2));
                        plane.push_back(surface(tempPoint3,tempPoint4,tempPoint5));
                        plane.push_back(surface(tempPoint5,tempPoint4,tempPoint2));
                        ptr1 = plane.erase(ptr1);
                        planeDelete = planeItr;
                        planeItr++;
                        planeDelete = plane.erase(planeDelete);
                        checkVal = checker(planeItr);

                    }
                    break;

                }
            case 2:
                {
                    if (planeItr->getx2yFlag() == false)
                        d3val++;
                    else
                    {

                    break;
                    }
                }
            case 3:
                {
                    if (planeItr->gety2zFlag() == false)
                        break;
                    else
                    {

                    }
                    break;
                }
            }

        }
        }
        checkVal = checker(planeItr);
    }
    planeItr++;
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
        outdat << trunc(tempPoint1.getX()) << " " << trunc(tempPoint1.getY()) << " " << trunc(tempPoint1.getZ()) << endl << endl;;

        planeItr++;
    }


    outfile << "clear" << endl ;
    outfile << "reset" << endl ;
   /// outfile << "set hidden3d" << endl;
    outfile << "set xrange [-1000:2000]" << endl;
    outfile << "set yrange [-1000:2000]" << endl;
    outfile << "set zrange [-1000:2000]" << endl;
    outfile << "splot \"data.txt\" with lines" << endl;
    outfile << "pause -1";


    outfile.close();
    outdat.close();

    system("gnuplot command.txt ");
    plane.clear();
    return 0;
}





bool checker(list<surface>::iterator itr)
{
    double xVal,yVal,zVal, val, maxVal =500;
    point X,Y,Z,C;

    X= itr->getX();
    Y= itr->getY();
    Z= itr->getZ();
    C= itr->getC();

    xVal = abs(trunc(sqrt(((pow(X.getX() - C.getX(), 2))+(pow(X.getY() - C.getY(), 2))+(pow(X.getZ() - C.getZ(), 2))))));
    yVal = abs(trunc(sqrt(((pow(Y.getX() - C.getX(), 2))+(pow(Y.getY() - C.getY(), 2))+(pow(Y.getZ() - C.getZ(), 2))))));
    zVal = abs(trunc(sqrt(((pow(Z.getX() - C.getX(), 2))+(pow(Z.getY() - C.getY(), 2))+(pow(Z.getZ() - C.getZ(), 2))))));

    if ((xVal <= maxVal) || (yVal <= maxVal) || (zVal <= maxVal))
        return false;
    else
        return true;
}

