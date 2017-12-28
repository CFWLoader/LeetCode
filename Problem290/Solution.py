__author__ = 'cfwloader'


class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """

        if pattern == '':
            return False

        patternMap = {}

        patternMarkedFlag = {}

        for element in pattern:
            if element not in patternMap:
                patternMap[element] = ''

        strVector = str.split(' ')

        if len(pattern) != len(strVector):
            return False;

        patternIterator = iter(pattern) # python 2 grammer.
        # patternIterator = pattern.__iter__() # python 3 grammer.

        for element in strVector:
            if element not in patternMarkedFlag:
                patternMarkedFlag[element] = False;

        for strElement in strVector:

            ch = next(patternIterator)

            if ch == None:
                return False

            if patternMap[ch] == '':

                if patternMarkedFlag[strElement] == True:
                    return False;

                patternMap[ch] = strElement
            elif patternMap[ch] != strElement:
                # print('%c %s' % ch, strElement)
                return False

            patternMarkedFlag[strElement] = True;

        return True


pattern = "abba"

str = "dog cat cat dog"

solution = Solution()

print(solution.wordPattern(pattern, str))

pattern = "abba"
str = "dog cat cat fish"

print(solution.wordPattern(pattern, str))
