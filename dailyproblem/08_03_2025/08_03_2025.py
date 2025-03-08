class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        min_operations = k  # Maximum possible recolors needed
        white_count = blocks[:k].count('W')  # Count 'W' in the first window
        
        min_operations = white_count
        
        # Sliding window
        for i in range(k, len(blocks)):
            if blocks[i] == 'W':
                white_count += 1
            if blocks[i - k] == 'W':
                white_count -= 1

            min_operations = min(min_operations, white_count)

        return min_operations
