#include "functions.h"

void displayText(list<cypherchar>::iterator itr1, list<cypherchar>::iterator itr2);


int main()
{
    char charVal, cypherval, plainval;
    int totalcount;
    float probVal, lowVal, highVal;
    list<probabilities> charCount;
    list<cypherchar> cyphertext;
    list<cypherchar>::iterator cypheritr = cyphertext.begin();
    list<cypherchar>::iterator plaintextitr = cyphertext.begin();
    list<probabilities> charprobs;
    list<probabilities>::iterator probsitr = charprobs.begin();
    list<probabilities>::iterator charprobsitr = charCount.begin();

    ifstream probsIn;
    ifstream cypherIn;
    probsIn.open("charprobs.txt");
    cypherIn.open("cypher.txt");

    ///============================= Populate Probs =================================
    while(probsIn >> charVal >> probVal)
    {

        charprobs.push_back(probabilities(charVal,probVal));
    }
    probsIn.close();
    ///============================= END Populate Probs =============================


    ///=============================  Cypher Text  ==================================

    while (cypherIn >> charVal)
    {
        totalcount++;
        charprobsitr = charCount.begin();
        cyphertext.push_back(cypherchar(charVal));
        charprobsitr = find(charCount.begin(), charCount.end(), charVal);
        if (charprobsitr == charCount.end())
            charCount.push_back(charVal);
        else
            charprobsitr->setcount((charprobsitr->getcount())+1);


    }
    ///=============================  END Cypher Text  ===============================

    cypherIn.close();

    ///=============================  Display  =======================================
    list<cypherchar>::iterator textbegin = cyphertext.begin();
    list<cypherchar>::iterator textend = cyphertext.end();
    displayText(textbegin,textend);
    charCount.sort();
    charprobsitr = charCount.begin();
    while (charprobsitr != charCount.end())
    {
        cout << charprobsitr->getletter() << "\t" << charprobsitr->getcount() << endl;
        charprobsitr++;
    }


    ///=========================== END Display =====================================

    cout << "what letter do you want to change? ";
    cin >> cypherval;
    cout << "\nwhat do you want to change it to? ";
    cin >> plainval;

    cypheritr = cyphertext.begin();
    while (cypheritr != cyphertext.end())
        {
            if(cypheritr->getcychar() == toupper(cypherval))
            {cypheritr->setplchar(toupper(plainval));}
            cypheritr++;
        }
    textbegin = cyphertext.begin();
    textend = cyphertext.end();
    displayText(textbegin,textend);
    ///=========================== Populate Counts =================================


    ///=========================== END Populate Counts =============================

    return 0;
}

