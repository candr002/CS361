#include "q_6.h"
#include <vector>
#include <queue>

int main()
{
    size_t charfound;
    theDataz starter;
    ifstream inFile;
    string entry;
    int priority;
    char yesNo;
    char ignoreChar = ',';
    char cat;
    bool valid = false;
    string inCat;           ///entry category
    string inEID;         ///Entry Event ID
    string inPriority;       ///Entry priority value
    string inAbstract;    ///Entry Abstract

    ///Creating vector of priority queues
    /// index 0 = Mil
    /// index 1 = Civ
    /// index 2 = Corp
    vector< priority_queue<theDataz> > dataEntry;
    dataEntry.push_back(priority_queue<theDataz>());
    dataEntry.push_back(priority_queue<theDataz>());

    while (valid == false)
    {
        cout << "\n\nYou have logged into the NSA Data logger.\n\n";
        inFile.open("log.dat");
        if (!inFile)
            cout << "Error opening file" << endl;
        if (inFile)
            valid = true;
    }
    while(inFile)
    {
        getline(inFile,entry);
        charfound = entry.find_first_of(",");
        inCat = entry.substr(0, (charfound));
        entry.erase (0, charfound+1);
        charfound = entry.find_first_of(",");
        inEID = entry.substr(0, (charfound));
        entry.erase (0, charfound+1);
        charfound = entry.find_first_of(",");
        inPriority = entry[0];
        entry.erase (0, charfound+1);


        cat = inCat[0];
        starter.setCat(cat);
        starter.setEID(inEID);
        starter.setAbstract(entry);
        starter.setPriority(inPriority);
        starter.dispAttrs();

        switch (toupper(cat))
        {
        case 'M':
            {
                dataEntry[0].push(starter);
                break;
            }
        case 'U':
            {
                dataEntry[1].push(starter);
                break;
            }
        case 'C':
            {
                dataEntry[2].push(starter);
                break;
            }
        default :
            break;
        }

    }

    for (int loop = 0; loop < 2; loop++)
    {


        while (!dataEntry[loop].empty())
        {
           starter = dataEntry[loop].top();
            starter.dispAttrs();
            dataEntry[loop].pop();
        }
    }


    cout << "\nClosing";

    return 0;
}
