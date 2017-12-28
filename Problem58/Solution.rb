# @param {String} s
# @return {Integer}
def length_of_last_word(s)

  if s.nil? or s == ''
    return 0
  end

  length = 0

  index = s.size - 1

  while s[index] == ' ' and index > -1
    index -= 1
  end

  while s[index] != ' ' and index > -1

    length += 1

    index -= 1
  end

  length

end


puts length_of_last_word 'Hello World'