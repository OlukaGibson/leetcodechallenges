class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return ""; // If the string is empty
        int start = 0, maxLength = 0;

        // Helper function to expand around the center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // Length of the palindrome
        };

        for (int i = 0; i < s.length(); i++) {
            // Expand around a single character (odd-length palindromes)
            int len1 = expandAroundCenter(i, i);
            // Expand around two characters (even-length palindromes)
            int len2 = expandAroundCenter(i, i + 1);
            // Find the maximum length palindrome for this center
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2; // Calculate starting index of palindrome
            }
        }

        // Return the longest palindromic substring
        return s.substr(start, maxLength); 
    }
};
