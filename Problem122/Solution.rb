# @param {Integer[]} prices
# @return {Integer}
def max_profit(prices)

  if prices.nil? or prices.size < 1
    return 0
  end

  bound = prices.size

  profit = 0

  buy_date = 0

  prices.each_with_index { |val, idx|

    if val < prices[buy_date]
      buy_date = idx
    end

    if val > prices[buy_date] and idx + 1 < bound and val > prices[idx + 1]

      profit = profit + val - prices[buy_date]

      buy_date = idx + 1
    end

  }

  if prices[prices.size - 1] > prices[buy_date]

    profit = profit + prices[prices.size - 1] - prices[buy_date]

  end

  profit
end

puts max_profit [1, 2, 1, 2]

puts max_profit [2, 1, 4]