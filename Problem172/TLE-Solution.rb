# @param {Integer} n
# @return {Integer}
=begin
This problem occurred in my interview of the QiHu 360, so I have a strong memory of it.
I failed to give a solution in the interview. I learnt a solution after asking a friend.
This solution is that one and seems it's not the perfect solution(TLE).
The idea of this solution: count the number of 5 in the n! formula.
=end
def trailing_zeroes(n)

  total_of_five = 0

  (1..n).each do |num|

    if num % 5 == 0

      puts num

      fives = num

      while fives > 4

        total_of_five += 1

        fives /= 5

      end

    end

  end

  total_of_five

end