__author__ = 'cfwloader'

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        left1 = 0
        right1 = len(nums1) - 1
        # mid1 = left1 + int((right1 - left1) / 2)

        left2 = 0
        right2 = len(nums2) - 1
        # mid2 = left2 + int((right2 - left2) / 2)

        k = (len(nums1) + len(nums2) - 1) / 2
        """
        if (len(nums1) + len(nums2) - 1) % 2 != 0 :
            print('flt k: %f' % (k))
        else:
            print('int k: %d' % (k))
        """

        if (len(nums1) + len(nums2) - 1) % 2 != 0 :
            print('flt k: %f' % (k))

            print('%d %d' % (int(k) + 1, int(k) + 2))

            mid1 = self.findKth(nums1, nums2, left1, right1, left2, right2, int(k) + 1)
            mid2 = self.findKth(nums1, nums2, left1, right1, left2, right2, int(k) + 2)

            result = (mid1 + mid2) / 2

            print('mid1: %f  mid2: %f  result: %f' % (mid1, mid2, result))

            return result
        else:
            print('int k: %d' % (k))
            return float(self.findKth(nums1, nums2, left1, right1, left2, right2, int(k) + 1))


    def findKth(self, nums1, nums2, left1, right1, left2, right2, k):

        mid1 = int(float(right1 / (right1 + right2)) * (k - 1))
        mid2 = (k-1) - mid1

        nums1LeftBoundReached = False if mid1 > left1 else True
        nums1RightBoundReached = False if mid1 <= right1 else True
        nums2LeftBoundReached = False if mid2 > left2 else True
        nums2RightBoundReached = False if mid2 <= right2 else True




if __name__ == '__main__':

    nums1 = [2, 3, 4]
    nums2 = [1]

    solution = Solution()

    # print(solution.findMedianSortedArrays(nums1, nums2))
    # print (solution.findKth(nums1, nums2, 0, len(nums1) - 1, 0, len(nums2) - 2, 2))