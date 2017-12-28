# @param {Integer} n
# @return {Integer}
def climb_stairs(n)
  if n < 2
    return 1
  end

  max2 = Integer(n / 2)

  c = 1

  ways = 1

  # (i to n)Σ
  while c <= max2

    combinations = 1

    # Calculate combination - C(i, n - i).
    1.upto(c) do|number|
      combinations *= (n - c - number + 1)
    end

    1.upto(c) do|number|
      combinations /= number
    end

    ways += Integer(combinations)

    c += 1
  end

  ways
end

puts climb_stairs 1

puts climb_stairs 2

puts climb_stairs 3

puts climb_stairs 4

puts climb_stairs 5

puts climb_stairs 6

puts climb_stairs 44          # Should be 1134903170.