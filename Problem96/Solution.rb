# @param {Integer} n
# @return {Integer}
def num_trees(n)

  if n < 2
    return 1
  end

  dp = Array.new n + 1, 0

  dp[0] = 1

  dp[1] = 1

  2.upto(n) {|i|

    1.upto(i) {|j|

      dp[i] += dp[j - 1] * dp[i - j]

    }

  }

  dp[n]

end

puts i_trees 5