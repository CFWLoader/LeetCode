# @param {String} haystack
# @param {String} needle
# @return {Integer}
def str_str(haystack, needle)

  if haystack.nil? or needle.nil? or haystack.size < needle.size
    return -1
  end

  if needle.size < 1
    return 0
  end

  nextVector = makeNextVector needle

  hsSize = haystack.size; nSize = needle.size

  hayStackIndex = 0; needleIndex = 0

  while hayStackIndex < hsSize

    while needleIndex > 0 and needle[needleIndex] != haystack[hayStackIndex]
      needleIndex = nextVector[needleIndex - 1]
    end

    if needle[needleIndex] == haystack[hayStackIndex]
      needleIndex += 1
    end

    if needleIndex == nSize
      return hayStackIndex - nSize + 1
    end

    hayStackIndex += 1
  end

  return -1
end

def makeNextVector(patternStr)

  if patternStr.size < 2
    return [0]
  end

  patternSize = patternStr.size

  nextVector = Array.new(patternSize)

  nextVector[0] = 0

  index = 1; k = 0

  while index < patternSize

    while k > 0 and patternStr[k] != patternStr[index]
      k = nextVector[k - 1]
    end

    if patternStr[k] == patternStr[index]
      k += 1
    end

    nextVector[index] = k

    index += 1
  end

  nextVector
end

# puts str_str '', ''

puts str_str 'babba', 'bbb'

puts str_str 'a', ''

# puts ''.nil?