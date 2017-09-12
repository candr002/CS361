#include "probabilities.h"


void displayText(list<cypherchar>::iterator itr1, list<cypherchar>::iterator itr2)
{
    cout <<"\n\n\n\n";

    list<cypherchar>::iterator newitr = itr1;
    list<cypherchar>::iterator cypheritr = newitr;
    list<cypherchar>::iterator plainitr = newitr;
    while (cypheritr != itr2)
    {
        for (int loop = 0; loop < 39; loop++)
        {
            if (cypheritr != itr2)
            {   cout << cypheritr->getcychar();
                cypheritr++;
            }
        }
        cout << endl;
        for (int loop = 0; loop < 39; loop++)
            {
                if(plainitr != itr2)
                {
                    cout << plainitr->getplchar();
                    plainitr++;
                }
            }
        cout << endl << endl;

    }
    cout <<"\n\n\n\n";
}
///==============================================================================


