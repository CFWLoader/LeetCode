# @param {Integer} num
# @return {Boolean}
def is_ugly(num)

  if num <= 0
    return false
  end

  if num == 1
    return true
  end

  while num >= 2 and num % 2 == 0 do num /= 2 end
  while num >= 3 and num % 3 == 0 do num /= 3 end
  while num >= 5 and num % 5 == 0 do num /= 5 end

  return num == 1

end