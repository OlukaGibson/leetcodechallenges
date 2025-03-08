class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.size();
            int min_operations = k;  // Maximum possible recolors needed
            int white_count = 0;
    
            // Count 'W' in the first window of size k
            for (int i = 0; i < k; i++) {
                if (blocks[i] == 'W') white_count++;
            }
            min_operations = white_count;
    
            // Slide the window across the string
            for (int i = k; i < n; i++) {
                if (blocks[i] == 'W') white_count++;       // Add new rightmost character
                if (blocks[i - k] == 'W') white_count--;   // Remove leftmost character
    
                min_operations = min(min_operations, white_count);
            }
    
            return min_operations;
        }
    };
    