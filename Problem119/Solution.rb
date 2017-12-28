# @param {Integer} row_index
# @return {Integer[]}
def get_row(row_index)

  if row_index < 0
    return []
  end

  if row_index < 1
    return [1]
  end

  row_size = row_index + 1

  result = Array.new(row_index)

  result[0] = 1

  index = 1

  while index < row_size

    result[index] = result[index - 1] * (row_index - index + 1)

    result[index] = result[index] / index

    index += 1
  end

  result
end


print get_row 1
puts


print get_row 2
puts

print get_row 3
puts

print get_row 4
puts
