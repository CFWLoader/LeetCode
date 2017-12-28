# @param {Integer} n
# @return {String[]}
def generate_parenthesis(n)

  if n < 1
    return []
  end

  result_set = []

  actual_generator result_set, '', n, n

  result_set

end

def actual_generator(par_set, tag, left, right)

  if left == 0 and right == 0
    par_set << tag
  end

  if left > 0
    actual_generator par_set, tag + '(', left - 1, right
  end

  if right > 0 and left < right
    actual_generator par_set, tag + ')', left, right - 1
  end

end

result_set = generate_parenthesis 4

puts result_set.size

result_set.each { |element|
  puts element
}