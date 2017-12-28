__author__ = 'cfwloader'

class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for target in range(1, len(nums)):

            existFlag = False

            for checkingElement in nums:

                if target == checkingElement:
                    if existFlag:
                        return target
                    else:
                        existFlag = True