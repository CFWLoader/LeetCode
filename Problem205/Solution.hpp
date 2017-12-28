#include <string>
#include <string.h>

using std::string;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int sSize = s.size();

        int tSize = t.size();

        if(sSize != tSize)
        {
        	return false;
        }

        char charMap[256];

        char mapped[256];

        memset(charMap, '\0', sizeof(charMap));

        memset(mapped, 0, sizeof(mapped));

        for(int index = 0; index < sSize; ++index)
        {
        	if(charMap[s[index]] == '\0')
        	{
        		if(mapped[t[index]])
        		{
        			return false;
        		}

        		charMap[s[index]] = t[index];

        		mapped[t[index]] = 1;
        	}
        	else if(charMap[s[index]] != t[index])
        	{
        		return false;
        	}
        }

        return true;
    }
};