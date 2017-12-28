# @param {Integer[]} height
# @return {Integer}
def max_area(height)

  left = 0; right = height.size - 1

  max_area_value = 0

  while left < right

    height_value = height[left] < height[right] ? height[left] : height[right]

    area = (right - left) * height_value

    if max_area_value < area
      max_area_value = area
    end

    if height[left] < height[right]
      left += 1
    else
      right -= 1
    end

  end

  max_area_value
end