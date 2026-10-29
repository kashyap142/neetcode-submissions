func searchMatrix(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])

	mini, maxi := 0, m * n - 1

	for ; mini <= maxi; {
		mid := (mini + maxi) / 2

		r := mid / n
		c := mid % n

		if matrix[r][c] == target {
			return true;
		} else if matrix[r][c] > target {
			maxi = mid - 1
		} else {
			mini = mid + 1
		}
	}

	return false

}
