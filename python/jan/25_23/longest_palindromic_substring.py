class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""
        
        start, max_length = 0, 0

        # Helper function to expand around the center
        def expandAroundCenter(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return right - left - 1  # Length of the palindrome

        for i in range(len(s)):
            # Odd-length palindromes (center at one character)
            len1 = expandAroundCenter(i, i)
            # Even-length palindromes (center between two characters)
            len2 = expandAroundCenter(i, i + 1)
            # Find the maximum length for the current center
            curr_length = max(len1, len2)
            if curr_length > max_length:
                max_length = curr_length
                start = i - (curr_length - 1) // 2  # Update start index of the palindrome

        # Return the longest palindromic substring
        return s[start:start + max_length]
