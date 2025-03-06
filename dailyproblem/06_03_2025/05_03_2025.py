class Solution:
    def findMissingAndRepeatedValues(self, grid):
        n = len(grid)
        num_set = set()
        repeated = -1
        total_sum = 0
        expected_sum = (n * n * (n * n + 1)) // 2  # Sum of numbers 1 to n^2

        for i in range(n):
            for j in range(n):
                val = grid[i][j]
                total_sum += val
                if val in num_set:
                    repeated = val  # Found the repeated number
                num_set.add(val)

        missing = expected_sum - (total_sum - repeated)  # Correct the sum by subtracting duplicate
        return [repeated, missing]
