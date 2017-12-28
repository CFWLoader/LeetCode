# @param {Integer} n
# @return {Boolean}
def is_power_of_three(n)

  # The fantasy solution I searched from Internet.
  # 3^19 is 1162261467 and 3^20 will occur overflow in Integer.
  (n > 0) && (1162261467 % n == 0)

  # Alternative solution:
  # Check the result of log(n)/log(3) is a integer or not.

  # My low solution.
=begin
  left = 1, right = n

  while left != right
    middle = Integer(left / 2 + right / 2)

    if middle * middle * middle < n

    end
  end
=end
end

puts is_power_of_three 3*3*3*3