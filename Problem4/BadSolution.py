__author__ = 'cfwloader'

# It will get WA when nums1 = [2, 3, 4], nums2 [1]
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

        if left1 > right1:
            return float(nums2[left2 + k - 1])

        if left2 > right2:
            return float(nums1[left1 + k - 1])

        mid1 = left1 + int((right1 - left1) / 2)

        mid2 = left2 + int((right2 - left2) / 2)

        halfPosition = mid1 - left1 + mid2 - left2 + 2

        if nums1[mid1] < nums2[mid2]:
            if halfPosition > k:
                return self.findKth(nums1, nums2, left1, right1, left2, mid2 - 1, k)
            else:
                return self.findKth(nums1, nums2, mid1 + 1, right1, left2, right2, k - (mid1 - left1 + 1))
        else:
            if halfPosition > k:
                return self.findKth(nums1, nums2, left1, mid1 - 1, left2, mid2 - 1, k)
            else:
                return self.findKth(nums1, nums2, left1, right1, mid2 + 1, right2, k - (mid2 - left2 + 1))
