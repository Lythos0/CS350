#ifndef CHARHASH_H
#define CHARHASH_H

#include <cctype>

class Coder 
{
    public:
    static int value(char ch)
    {
        if(isalpha(ch))
        {
            return (int)(toupper(ch) - 'A');
        }
        return -1;
    }

    static char key(int ch)
    {
        if(ch >= 0 && ch <= 25)
        {
            return (char)('A' + ch);
        }
        return '\0';
    }
};

#endif
