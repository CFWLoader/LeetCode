# @param {Integer} n
# @return {String[]}
def generate_parenthesis(n)

  if n < 1
    return []
  end

  if n == 1
    return ['()']
  end

  sub_set = generate_parenthesis n - 1

  result = []

  sub_set.each {|element|

    result << '(' + element + ')'

    left_str = '()' + element

    right_str = element + '()'

    result << left_str

    if left_str != right_str
      result << right_str
    end
  }

  result

end

result_set = generate_parenthesis 4

result_set.each {|element|
  puts element
}