class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """

        statistic = {}

        quantity = len(nums)

        # Do statistic for finding medium.
        for element in nums:
            if element not in statistic.keys():
                statistic[element] = 1
            else:
                statistic[element] += 1

        # Core Algorithm.
        for idx in range(0, len(nums)):

            # Even index means this slot should be filled with 'lesser number'.
            # Otherwise, find the 'greater number'.
            if idx % 2 == 0:
                nums[idx] = self.findMiddle(statistic, quantity)
            else:
                nums[idx] = self.findNext(statistic, nums[idx - 1])

            # Update the statistic.
            statistic[nums[idx]] -= 1

            if statistic[nums[idx]] == 0:
                statistic.pop(nums[idx])

            quantity -= 1

        statistic.clear()

    # This function is to find the 'lesser number'.
    def findMiddle(self, elementMap, quantity):

        # We choose the lesser one if the dictionary contains two element or less.
        if len(elementMap) <= 2:
            for ele in elementMap.keys():
                return ele

        # Calculate the medium number index.
        targetIndex = int(quantity / 2)

        rangeStart = 0

        for ele in elementMap.keys():
            # Quantity of 'lesser number' equals to 'greater number's.
            # Choose the left one of the medium number.
            if quantity % 2 == 0 and rangeStart + elementMap[ele] == quantity / 2:
                return ele

            # The target number's index is in this number's index range.
            if rangeStart <= targetIndex < (rangeStart + elementMap[ele]):
                return ele

            rangeStart += elementMap[ele]

    def findNext(self, elementMap, referenceValue):

        if len(elementMap) == 1:
            for ele in elementMap.keys():
                return ele

        for ele in elementMap.keys():

            if ele > referenceValue:
                return ele


if __name__ == "__main__":

    sol = Solution()

    arr = [1, 5, 1, 1, 6, 4]

    sol.wiggleSort(arr)

    for ele in arr:
        print(ele, end=' ')

    print("\n")

    arr = [1, 3, 2, 2, 3, 1]

    sol.wiggleSort(arr)

    for ele in arr:
        print(ele, end=' ')

    print("\n")

    arr = [1, 2, 2, 1, 2, 1, 1, 1, 1, 2, 2, 2]

    sol.wiggleSort(arr)

    for ele in arr:
        print(ele, end=' ')

    print("\n")

    arr = [1, 3, 2, 2, 2, 1, 1, 3, 1, 1, 2]

    sol.wiggleSort(arr)

    for ele in arr:
        print(ele, end=' ')

    print("\n")

    arr = [3, 1, 2, 3]

    sol.wiggleSort(arr)

    for ele in arr:
        print(ele, end=' ')

    print("\n")

    arr = [1, 2, 3, 2, 3, 3]

    sol.wiggleSort(arr)

    for ele in arr:
        print(ele, end=' ')

    print("\n")

    arr = [4, 5, 5, 6]

    sol.wiggleSort(arr)

    for ele in arr:
        print(ele, end=' ')

    print("\n")
