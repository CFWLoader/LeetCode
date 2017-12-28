# @param {Integer[]} nums
# @param {Integer} k
# @return {Void} Do not return anything, modify nums in-place instead.
def rotate(nums, k)

  if nums.nil? or nums.size == 1 or k % nums.size == 0
    return
  end

  array_length = nums.size

  source_index = 0

  current_buffer_value = nums[source_index]

  distance = 0

  1.upto array_length do

    target_index = (source_index + k) % array_length

    temp = nums[target_index]

    nums[target_index] = current_buffer_value

    source_index = target_index

    current_buffer_value = temp

    distance = (distance + k) % array_length

    if distance == 0
      source_index = (source_index + 1) % array_length

      current_buffer_value = nums[source_index]
    end

  end
end

# source = [1, 2, 3, 4, 5, 6, 7]
#
# rotate source, 3
#
# print source
#
# puts
#
# source = [1,2,3,4,5,6]
#
# rotate source, 2
#
# print source                # Expected: [5,6,1,2,3,4]
#
# puts

source = [1,2,3,4,5,6]

rotate source, 3

print source                # Expected: [4,5,6,1,2,3]