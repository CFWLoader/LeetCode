# @param {Character[][]} board
# @return {Boolean}
def is_valid_sudoku(board)

  # Valid the matrix.
  if board.nil? or board.size != 9
    return false
  end

  board.each { |row| if row.nil? or row.size != 9 then return false end }

  presented = Array.new(10, false)

  board.each do |row|
    row.each_char do |cell|
      if cell != '.'
        if presented[cell.to_i]
        end
      end
    end
  end
end

'0123456789'.each_char do |ch|
  print ch.to_i.class
end