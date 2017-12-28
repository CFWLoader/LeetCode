"""
TLE Solution.
Greedy Strategy.
"""


class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        numberOfElement = len(nums)

        if numberOfElement < 2:
            return

        # Only compare two adjacent element. If they are equals, search the suitable element in this slot in the unordered elements.
        for idx in range(1, numberOfElement):

            if idx % 2 != 0 and nums[idx] <= nums[idx - 1] or idx % 2 == 0 and nums[idx] >= nums[idx - 1]:
                nums[idx], nums[idx - 1] = nums[idx - 1], nums[idx]

            if nums[idx] == nums[idx - 1]:
                self.nextDifference(nums, idx, idx % 2 != 0)

    def nextDifference(self, nums, startIndex, larger):

        if larger:
            for idx in range(startIndex + 1, len(nums)):
                if nums[idx] > nums[startIndex]:
                    nums[idx], nums[startIndex] = nums[startIndex], nums[idx]
                    return
        else:
            for idx in range(startIndex + 1, len(nums)):
                if nums[idx] < nums[startIndex]:
                    nums[idx], nums[startIndex] = nums[startIndex], nums[idx]
                    return


if __name__ == "__main__":

    arr = [1, 5, 1, 1, 6, 4]

    sol = Solution()

    sol.wiggleSort(arr)

    for ele in arr:
        print(ele, end=' ')

    print("\n")

    arr = [1, 3, 2, 2, 3, 1]

    sol.wiggleSort(arr)

    for ele in arr:
        print(ele, end=' ')

    print("\n")

    arr = [4, 5, 5, 6]

    sol.wiggleSort(arr)

    for ele in arr:
        print(ele, end=' ')

    print("\n")
