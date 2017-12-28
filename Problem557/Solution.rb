# @param {String} s
# @return {String}
def reverse_words(s)

  ret_val = ''

  end_idx = -1

  back_idx = 0

  iter_idx = 0

  iter_end = s.size

  while iter_idx != iter_end

    if s[iter_idx] == ' '

      back_idx = iter_idx - 1

      while back_idx > end_idx

        ret_val << s[back_idx]

        back_idx -= 1

      end

      ret_val << s[iter_idx]

      end_idx = iter_idx

    end

    iter_idx += 1

  end

  back_idx = iter_idx - 1

  while back_idx > end_idx

    ret_val << s[back_idx]

    back_idx -= 1

  end

  ret_val

end


if $0 == __FILE__

  testCase = 'Let\'s take LeetCode contest'

  p reverse_words testCase

end