#include "cypherchar.h"

class probabilities
{
public:
    probabilities(char x)
        {letter = x;
        thecount = 0;}
    probabilities(char x, float n)
        {letter = x;
        probability = n;
        thecount = 0;}
    void setletter(char x)
        {letter = x;}
    char getletter()
        {return letter;}
    void setprob(float n)
        {probability = n;}
    float getprob()
        {return probability;}
    int getcount()
        {return thecount;}
    void setcount(int x)
        {thecount = x;}

    bool operator==(char x )const
        {
            if (letter == x)
                return true;
            else
                return false;
        }

    bool operator<(probabilities& thing)const
        {
            if((thecount<thing.getcount())==true)
                return false;
            else
                return true;
        }

private:
    char letter;
    float probability;
    int thecount;
};
