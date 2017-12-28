# @param {String} a
# @param {String} b
# @return {String}
def add_binary(a, b)

  if a.nil? or a.size < 1
    return b
  end

  if b.nil? or b.size < 1
    return a
  end

  result = ''

  current = false

  aIndex = a.size - 1; bIndex = b.size - 1

  while aIndex > -1 and bIndex > -1

    aIndex -= 1

    bIndex -= 1
  end
end