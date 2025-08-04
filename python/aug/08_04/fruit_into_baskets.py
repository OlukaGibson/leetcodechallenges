class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        from collections import defaultdict

        basket = defaultdict(int)
        left = 0
        max_fruits = 0

        for right in range(len(fruits)):
            basket[fruits[right]] += 1

            # If we have more than 2 types of fruit, shrink the window
            while len(basket) > 2:
                basket[fruits[left]] -= 1
                if basket[fruits[left]] == 0:
                    del basket[fruits[left]]
                left += 1

            # Update max_fruits with current window size
            max_fruits = max(max_fruits, right - left + 1)

        return max_fruits
