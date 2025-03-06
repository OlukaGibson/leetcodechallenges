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

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int XOR_all = 0, XOR_grid = 0;
        for (int num = 1; num <= n * n; ++num) {
            XOR_all ^= num;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                XOR_grid ^= grid[i][j];
            }
        }
        int XOR_diff = XOR_all ^ XOR_grid;
        int bit = XOR_diff & -XOR_diff;
        int missing = 0, repeated = 0;
        for (int num = 1; num <= n * n; ++num) {
            if (num & bit)
                missing ^= num;
            else
                repeated ^= num;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] & bit)
                    missing ^= grid[i][j];
                else
                    repeated ^= grid[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == missing) swap(missing, repeated);
            }
        }

        return {repeated, missing};
    }
};
