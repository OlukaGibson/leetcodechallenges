from collections import Counter

class Solution(object):
    def numOfUnplacedFruits(self, fruits, baskets):
        """
        :type fruits: List[int]
        :type baskets: List[int]
        :rtype: int
        """
        fruit_count = Counter(fruits)
        basket_count = Counter(baskets)
        
        unplaced = 0

        for fruit_type, count in fruit_count.items():
            if fruit_type in basket_count:
                # Place as many as the number of matching baskets
                placed = min(count, basket_count[fruit_type])
                unplaced += (count - placed)
            else:
                # No basket accepts this fruit
                unplaced += count

        return unplaced
