# @param {Integer[]} nums1
# @param {Integer} m
# @param {Integer[]} nums2
# @param {Integer} n
# @return {Void} Do not return anything, modify nums1 in-place instead.
def merge(nums1, m, nums2, n)
  if nums2.nil? or n < 1
    return
  end

  maxSize = m + n

  index = maxSize - 1

  index1 = m - 1; index2 = n - 1

  while index1 > -1 and index2 > -1

    if nums1[index1] > nums2[index2]
      nums1[index] = nums1[index1]

      index1 -= 1
    else
      nums1[index] = nums2[index2]

      index2 -= 1
    end

    index -= 1
  end

  if index2 > -1
    while index2 > -1
      nums1[index] = nums2[index2]

      index2 -= 1

      index -= 1
    end
  elsif index1 > -1
    while index1 > -1

      nums1[index] = nums1[index1]

      index1 -= 1

      index -= 1
    end
  end

end

nums1 = [1, 3, 5, 7, 0, 0, 0]

nums2 = [2, 4, 6]

merge nums1, 4, nums2, 3

print nums1

puts