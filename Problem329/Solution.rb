# @param {Integer[][]} matrix
# @return {Integer}
def longest_increasing_path(matrix)

  if matrix.nil?
    return 0
  end

  rows = matrix.size

  cols = 0

  matrix.each { |arr|
    if !arr.nil? and arr.size > cols
      cols = arr.size
    end }

  cellRecords = Array.new(rows)

  rowIndex =0; colIndex = 0

  while rowIndex < rows

    cellRecords[rowIndex] = Array.new(cols)

    colIndex = 0

    while colIndex < cols

      cellRecords[rowIndex][colIndex] = [0, :N]

      colIndex += 1
    end

    rowIndex += 1
  end

  rowIndex =0; colIndex = 0

  updateRowIndex = 0; updateColIndex = 0

  maxValue = 0; direction = :N

  maxPathCount = 1

  matrix.each do |row|

    cols = row.size

    colIndex = 0

    row.each do |cell|

      # Select a max value adjacencies.
      maxValue = 0; direction = :N

      if rowIndex - 1 > -1 and matrix[rowIndex - 1][colIndex] > cell and cellRecords[rowIndex - 1][colIndex][0] > maxValue
        maxValue = cellRecords[rowIndex - 1][colIndex][0]; direction = :U
      end

      if colIndex - 1 > -1 and matrix[rowIndex][colIndex - 1] > cell and cellRecords[rowIndex][colIndex - 1][0] > maxValue
        maxValue = cellRecords[rowIndex][colIndex - 1][0]; direction = :L
      end

      if rowIndex + 1 < rows and matrix[rowIndex + 1][colIndex] > cell and cellRecords[rowIndex + 1][colIndex][0] > maxValue
        maxValue = cellRecords[rowIndex + 1][colIndex][0]; direction = :D
      end

      if colIndex + 1 < cols and matrix[rowIndex][colIndex + 1] > cell and cellRecords[rowIndex][colIndex + 1][0] > maxValue
        maxValue = cellRecords[rowIndex][colIndex + 1][0]; direction = :R
      end

      cellRecords[rowIndex][colIndex] = [maxValue + 1, direction]

      # print "(#{rowIndex}, #{colIndex}, #{cellRecords[rowIndex][colIndex]})"

      # Update Path
      updateRowIndex = rowIndex; updateColIndex = colIndex

      currentPathCount = 1

      # print "#{updateRowIndex}, #{updateColIndex}\n"

      # print "Updating Path.\n"
      until direction == :N

        # print "(#{updateRowIndex}, #{updateColIndex}, #{cellRecords[updateRowIndex][updateColIndex]})->"
        case cellRecords[updateRowIndex][updateColIndex][1]
          when :U
            cellRecords[updateRowIndex - 1][updateColIndex][0] = cellRecords[updateRowIndex][updateColIndex][0] - 1
            updateRowIndex -= 1
          when :L
            cellRecords[updateRowIndex][updateColIndex - 1][0] = cellRecords[updateRowIndex][updateColIndex][0] - 1
            updateColIndex -= 1
          when :D
            cellRecords[updateRowIndex + 1][updateColIndex][0] = cellRecords[updateRowIndex][updateColIndex][0] - 1
            updateRowIndex += 1
          when :R
            cellRecords[updateRowIndex][updateColIndex + 1][0] = cellRecords[updateRowIndex][updateColIndex][0] - 1
            updateColIndex += 1
          else
            break
        end

        direction = cellRecords[updateRowIndex][updateColIndex][1]

        currentPathCount += 1
      end

      # print "(#{updateRowIndex}, #{updateColIndex}, #{cellRecords[updateRowIndex][updateColIndex]})\nUpdate path end.\n"

      if currentPathCount > maxPathCount
        maxPathCount = currentPathCount
      end

      colIndex += 1

    end

    rowIndex += 1

  end

  cellRecords.each do |row|
    row.each do |cell|
      print "#{cell} "
    end
    puts
  end

  maxPathCount
end


puts longest_increasing_path [
                                 [9, 9, 4],
                                 [6, 6, 8],
                                 [2, 1, 1]
                             ]

puts longest_increasing_path [
                                 [3,4,5],
                                 [3,2,6],
                                 [2,2,1]
                             ]