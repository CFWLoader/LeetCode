#include <assert.h>

bool isMatch(char* s, char* p) {

    assert(s && p);

    if(*p == '\0') return *s == '\0';

    // Next char is not '*': must match current character.
    if(*(p + 1) != '*')
    {
        assert(*p != '*');

        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
    }

    // Next char is '*': Do a brute force exhaustive matching first. If failed, Do greedily match as many as characters in current pattern character.
    while((*p == *s) || (*p == '.' && *s != '\0'))
    {
        if(isMatch(s, p + 2)) return true;

        s++;
    }

    return isMatch(s, p + 2);
}