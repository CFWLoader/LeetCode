__author__ = 'cfwloader'

class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        shadow = x

        reverseNumber = int(0)

        while shadow > 0:

            reverseNumber = reverseNumber * 10 + int(shadow % 10)

            shadow = int(shadow / 10)

        if x == reverseNumber:
            return True
        else:
            return False



if __name__ == '__main__':

    sol = Solution()

    print(sol.isPalindrome(1221))

    print(sol.isPalindrome(3))

    print(sol.isPalindrome(-1331))

    print(sol.isPalindrome(1231))