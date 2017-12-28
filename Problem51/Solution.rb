# @param {Integer} n
# @return {String[][]}
def solve_n_queens(n)

  result_set = Array.new

  get_solutions(n) { |coordinates|
    result_set << construct_chessboard(coordinates)
  }

  result_set
end

def get_solutions(n)

  coordinates = Array.new n, -1

  placed = 0

  while placed > -1

    coordinates[placed] += 1

    while placed < n and not is_valid coordinates, placed
      coordinates[placed] += 1
    end

    if placed == n - 1 and coordinates[placed] < n
      yield coordinates
    elsif placed < n and coordinates[placed] < n
      placed += 1
      coordinates[placed] = -1
    else
      coordinates[placed] = -1
      placed -= 1
    end

  end

end

def is_valid(coordinates, target)

  0.upto(target - 1) { |row|
    if coordinates[target] == coordinates[row] || (target - row).abs == (coordinates[target] - coordinates[row]).abs
      return false
    end
  }

  true

end

def construct_chessboard(coordinates)

  chessboard = Array.new coordinates.size

  coordinates.each_with_index { |col, row|

    chessboard[row] = '.' * coordinates.size

    chessboard[row][col] = 'Q'

  }

  chessboard
end

result = solve_n_queens 4

result.each { |chessboard|
  print chessboard
  puts
}