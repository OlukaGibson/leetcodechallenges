# class Solution:
#     def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
#         n = len(colors)
#         count = 0

#         for i in range(n):
#             is_alternating = True
#             for j in range(k - 1):
#                 if colors[(i + j) % n] == colors[(i + j + 1) % n]:
#                     is_alternating = False
#                     break
#             if is_alternating:
#                 count += 1
        
#         return count


from typing import List

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)
        is_alternating = [colors[i] != colors[(i + 1) % n] for i in range(n)]

        count = 0
        valid_count = sum(is_alternating[:k - 1])  # Initial window

        # Sliding window across the circular array
        for i in range(n):
            if valid_count == k - 1:
                count += 1  # Valid alternating group found

            # Slide the window
            valid_count -= is_alternating[i]
            valid_count += is_alternating[(i + k - 1) % n]

        return count
