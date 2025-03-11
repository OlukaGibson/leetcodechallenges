class Solution {
    public:
        int numberOfSubstrings(string s) {
            vector<int> count(3, 0); // To track occurrences of 'a', 'b', 'c'
            int left = 0, total = 0;
            
            for (int right = 0; right < s.size(); ++right) {
                count[s[right] - 'a']++; // Increment count for the current character
                
                // While window contains at least one 'a', 'b', and 'c'
                while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                    total += s.size() - right; // Add all substrings ending at `right`
                    count[s[left] - 'a']--; // Shrink the window from the left
                    left++;
                }
            }
            
            return total;
        }
    };
    