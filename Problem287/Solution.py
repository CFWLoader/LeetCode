__author__ = 'cfwloader'

class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        minIndex = 0
        maxIndex = len(nums) - 1

        while minIndex <= maxIndex:

            middleIndex = minIndex + int((maxIndex - minIndex) / 2)

            counter = 0                                             # Counting the number less than middleIndex's value.

            for element in nums:

                if element <= middleIndex:

                    counter += 1

            if counter > middleIndex:

                maxIndex = middleIndex - 1

            else:

                minIndex = middleIndex + 1

        return minIndex


if __name__ == '__main__':

    solution = Solution()

    print(solution.findDuplicate([4, 3, 5, 2, 1, 3, 6, 3]))