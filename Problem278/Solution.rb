# The is_bad_version API is already defined for you.
# @param {Integer} version
# @return {boolean} whether the version is bad
# def is_bad_version(version):

# @param {Integer} n
# @return {Integer}
def first_bad_version(n)

  left = 1; right = n

  while left < right

    mid = left + Integer((right - left) / 2)

    if is_bad_version mid
      right = mid
    else
      left = mid + 1
    end

  end

  left
end


def is_bad_version(version)

  if version == 4
    return true
  end

  false
end

puts first_bad_version 1

puts first_bad_version 1

puts first_bad_version 1