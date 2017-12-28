# @param {String} s
# @return {Boolean}
def is_palindrome(s)

  if s.nil?
    return false
  end

  if s == ''
    return true
  end

  formattedStr = s.downcase

  left = 0; right = formattedStr.size - 1

  while left < right

    unless (formattedStr[left] >= 'a' and formattedStr[left] <= 'z') or (formattedStr[left] >= '0' and formattedStr[left] <= '9')
      left += 1

      next
    end

    unless (formattedStr[right] >= 'a' and formattedStr[right] <= 'z') or (formattedStr[right] >= '0' and formattedStr[right] <= '9')
      right -= 1

      next
    end

    # print "L_index: #{left}, L_value: #{formattedStr[left]}; R_index: #{right}, R_value: #{formattedStr[right]}.\n"

    if formattedStr[left] != formattedStr[right]
      return false
    end

    left += 1

    right -= 1

  end

  true
end

puts is_palindrome 'A man, a plan, a canal: Panama'

puts is_palindrome 'race a car'

puts is_palindrome 'ab'