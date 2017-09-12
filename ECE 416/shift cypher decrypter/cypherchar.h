#include "libraries.h"

class cypherchar
{
public:

    cypherchar()
        {plaintext = '-';}

    cypherchar(char x)
        {cyphertext = x;
        plaintext = '-';}

    char getcychar()
        {return cyphertext;}
    void setcychar(char x)
        {cyphertext = x;}

    char getplchar()
        {return plaintext;}
    void setplchar(char x)
        {plaintext = x;}


private:

    char cyphertext, plaintext;

};
