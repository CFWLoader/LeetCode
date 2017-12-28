#include <string>

using std::string;

class WA_Solution
{
public:
    bool isMatch(string s, string p)
    {

        int stringIndex = 0, patternIndex = 0;

        int stringBound = s.size(), patternBound = p.size();

        while (stringIndex < stringBound && patternIndex < patternBound)
        {
            // printf("stringIndex: %d, patternIndex: %d.\n", stringIndex, patternIndex);

            if (s[stringIndex] == p[patternIndex] || p[patternIndex] == '.')
            {
                ++stringIndex;

                if ((patternIndex + 1 == patternBound) || patternIndex + 1 < patternBound && p[patternIndex + 1] != '*')
                {
                    ++patternIndex;
                }
            }
            else
            {
                ++patternIndex;

                if ((patternIndex + 1 == patternBound) || patternIndex < patternBound && p[patternIndex] == '*')
                {
                    ++patternIndex;
                }
            }
        }

        bool patternFinished = false;

        if (patternIndex == patternBound || patternIndex + 2 == patternBound && p[patternIndex + 1] == '*')
        {
            patternFinished = true;

            patternIndex = patternBound;
        }

        if (stringIndex == stringBound && !patternFinished)
        {

            bool softMatched = false;

            if ((s[stringIndex - 1] == p[patternIndex] || p[patternIndex] == '.') && patternIndex + 1 < patternBound &&
                p[patternIndex + 1] == '*')
            {
                softMatched = true;
            }

            while (patternIndex < patternBound)
            {
                if (p[patternIndex] != '*')
                {
                    if (patternIndex + 2 <= patternBound && p[patternIndex + 1] == '*')
                    {
                        patternIndex += 2;
                    }
                    else if (s[stringIndex - 1] == p[patternIndex] || p[patternIndex] == '.')            // Here still has bug.
                    {
                        if (softMatched)++patternIndex;

                        break;
                    }
                    else
                    {
                        return false;
                    }

                    continue;
                }

                ++patternIndex;
            }
        }

        return stringIndex == stringBound && patternIndex == patternBound;

    }

};
