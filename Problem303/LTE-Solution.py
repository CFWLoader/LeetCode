class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.hundredSum = [0] * len(nums)

        self.nums = nums

        for hundredIndex in (0, int(len(nums)/100)):

            if hundredIndex + 1 >= int(len(nums) / 100):
                break

            self.hundredSum[hundredIndex] = 0

            for index in (hundredIndex * 100, (hundredIndex + 1) * 100):
                self.hundredSum[hundredIndex] += nums[index]

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """

        if i >= j:
            return 0

        if i < 0:
            i = 0

        if j > len(self.nums):
            j = len(self.nums) - 1

        sum = 0

        hundredStart = int(i / 100)

        hundredEnd = int(j / 100)

        for hundredIndex in range(hundredStart, hundredEnd + 1):
            sum += self.hundredSum[hundredIndex]

        for index in range(hundredStart, i, 1):
            sum -= self.nums[index]

        for index in range(hundredEnd, j + 1, 1):
            sum += self.nums[index]

        return sum

# Your NumArray object will be instantiated and called as such:
# numArray = NumArray(nums)
# numArray.sumRange(0, 1)
# numArray.sumRange(1, 2)

if __name__ == '__main__':
    numArray = NumArray([-2, 0, 3, -5, 2, -1])
    print(numArray.sumRange(0, 2))
    print(numArray.sumRange(2, 5))
    print(numArray.sumRange(0, 5))