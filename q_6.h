///********************************************************///
///Author:      Chris Andrzejewski                         ///
///UIN:         01008193                                   ///
///Assignment:  "Final Question 6"                         ///
///INFO:        Header file                                ///
///********************************************************///

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <iterator>

using namespace std;


class theDataz
{
public:
    ///creates new instance based on input will also use default destructor
    theDataz(){};


    char getCat(){return cat;}
    string getEID(){return EID;}
    string getPriority(){return priority;}
    string getAbstract(){return abstract;}

    void setCat(char inCat){cat = inCat;}
    void setEID(string inEID){EID = inEID;}
    void setPriority(string inPriority){priority = inPriority;}
    void setAbstract(string inAbstract){abstract = inAbstract;}

    bool operator < (const theDataz &right)const
        {
            if (priority < right.priority)
                return true;
            else
                return false;
        }

    void dispAttrs()
        {
            cout << cat << "\t" << EID << "\t" << priority << "\t" << abstract << endl;
        }


private:
    char cat;           ///entry category
    string EID;         ///Entry Event ID
    string priority;       ///Entry priority value
    string abstract;    ///Entry Abstract
};
