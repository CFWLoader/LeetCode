# @param {String[]} strs
# @return {String}
def longest_common_prefix(strs)
  if strs.nil? or strs.length < 1
    return ''
  end

  minimumLength = strs[0].size

  resultPrefix = ''

  strs.each { |str| if str.size < minimumLength then minimumLength = str.size end }

  for i in 0 .. minimumLength - 1

    currentChar = strs[0][i]

    strs.each do |str|
      if str[i] != currentChar
        return resultPrefix
      end
    end

    resultPrefix += currentChar
  end

  resultPrefix
end

puts longest_common_prefix(['aa', 'aa'])

puts longest_common_prefix(['aa', 'ab'])