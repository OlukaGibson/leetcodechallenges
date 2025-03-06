class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            unordered_set<int> seen;
            int repeated = -1;
            long long totalSum = 0;
            long long expectedSum = (long long)(n * n) * (n * n + 1) / 2; // Sum of 1 to n^2
    
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int val = grid[i][j];
                    totalSum += val;
                    if (seen.count(val)) {
                        repeated = val;  // Found duplicate
                    }
                    seen.insert(val);
                }
            }
    
            int missing = expectedSum - (totalSum - repeated);
            return {repeated, missing};
        }
    };
    