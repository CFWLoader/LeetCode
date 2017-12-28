# @param {Integer[]} candies
# @return {Integer}
def distribute_candies(candies)

  if candies.size == 0
    return 0
  end

  candies.sort!

  search_limit = candies.size / 2

  type_count = 1

  last_type = candies[0]

  candies.each {|ele|

    if type_count == search_limit then break end

    if ele != last_type

      type_count += 1

      last_type = ele

    end

  }

  type_count

end


if $0 == __FILE__

  candies = [3, 1, 2, 1]

  p distribute_candies candies

  candies = [1, 2, 3, 4, 5, 6]

  p distribute_candies candies

end