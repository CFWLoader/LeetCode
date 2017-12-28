# @param {Integer} n
# @return {Integer}
def integer_break(n)

  if n <= 2
    return 1
  end

  if n == 3
    return 2
  end

  dp = Array.new n + 1, 1

  dp[3] = 2

  4.upto(n) { |num|

    pivot = Integer(num / 2)

    max_val = 1

    pivot.downto(2) { |left|

      # left = Integer(num / 2)

      right = num - left

      left = left > dp[left] ? left : dp[left]

      right = right > dp[right] ? right : dp[right]

      max_val = left * right > max_val ? left * right : max_val

    }

    dp[num] = max_val
  }

  dp[n]

end

puts integer_break 2

puts integer_break 3

puts integer_break 4

puts integer_break 5

puts integer_break 6

puts integer_break 7

puts integer_break 8

puts integer_break 9

puts integer_break 10