# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}
def search_matrix(matrix, target)

	rows = matrix.size

	if rows < 1

		return false

	end

	cols = matrix[0].size

	col = cols - 1
	row = 0

	while col >= 0 and row < rows

		if target == matrix[row][col]

			return true

		elsif target < matrix[row][col]

			col -= 1

		elsif target > matrix[row][col]

			row += 1

		end

	end

	false
    
end

if __FILE__ == $0

	mat = [
		  [1,   4,  7, 11, 15],
		  [2,   5,  8, 12, 19],
		  [3,   6,  9, 16, 22],
		  [10, 13, 14, 17, 24],
		  [18, 21, 23, 26, 30]
		]

	puts search_matrix mat, 5

end