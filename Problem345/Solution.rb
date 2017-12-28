# @param {String} s
# @return {String}
def reverse_vowels(s)

  if s.nil? or s.size < 2
    return s
  end

  left = 0; right = s.size - 1

  vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

  while left < right

    while left < right and !vowels.include? s[left]
      left += 1
    end

    while left < right and !vowels.include? s[right]
      right -= 1
    end

    unless left < right
      break
    end

    if s[left] != s[right]
      s[left], s[right] = s[right], s[left]
    end

    left += 1

    right -= 1

  end

  s
end

puts reverse_vowels 'hello'

puts reverse_vowels 'leetcode'

puts reverse_vowels 'aA'