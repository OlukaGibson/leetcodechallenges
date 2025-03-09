// class Solution {
//     public:
//         int numberOfAlternatingGroups(vector<int>& colors, int k) {
//             int n = colors.size();
//             int count = 0;
    
//             // Check all valid windows
//             for (int i = 0; i < n; i++) {
//                 bool isAlternating = true;
//                 for (int j = 0; j < k - 1; j++) {
//                     if (colors[(i + j) % n] == colors[(i + j + 1) % n]) {
//                         isAlternating = false;
//                         break;
//                     }
//                 }
//                 if (isAlternating) count++;
//             }
    
//             return count;
//         }
//     };
    

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            vector<bool> is_alternating(n, false);
    
            // Precompute alternation check for each adjacent pair
            for (int i = 0; i < n; i++) {
                is_alternating[i] = (colors[i] != colors[(i + 1) % n]);
            }
    
            // Count valid k-length alternating groups using a sliding window
            int count = 0, valid_count = 0;
    
            // Initialize the first window
            for (int i = 0; i < k - 1; i++) {
                valid_count += is_alternating[i];
            }
    
            // Slide the window across the circular array
            for (int i = 0; i < n; i++) {
                if (valid_count == k - 1) count++;  // Valid alternating group found
                
                // Move the window forward
                valid_count -= is_alternating[i];
                valid_count += is_alternating[(i + k - 1) % n];
            }
    
            return count;
        }
    };
    