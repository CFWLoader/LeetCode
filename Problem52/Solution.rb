# @param {Integer} n
# @return {String[][]}
def solve_n_queens(n)

  get_solutions n

end

def get_solutions(n)

  coordinates = Array.new n, -1

  placed = 0

  solution_count = 0

  while placed > -1

    coordinates[placed] += 1

    while placed < n and not is_valid coordinates, placed
      coordinates[placed] += 1
    end

    if placed == n - 1 and coordinates[placed] < n
      solution_count += 1
    elsif placed < n and coordinates[placed] < n
      placed += 1
      coordinates[placed] = -1
    else
      coordinates[placed] = -1
      placed -= 1
    end

  end

  solution_count

end

def is_valid(coordinates, target)

  0.upto(target - 1) { |row|
    if coordinates[target] == coordinates[row] || (target - row).abs == (coordinates[target] - coordinates[row]).abs
      return false
    end
  }

  true

end

puts solve_n_queens 4