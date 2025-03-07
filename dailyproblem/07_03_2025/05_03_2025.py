from typing import List

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        # Define the upper bound for sieve
        MAX = 10**6 + 1
        is_prime = [True] * MAX
        is_prime[0] = is_prime[1] = False  # 0 and 1 are not prime
        
        # Optimized Sieve of Eratosthenes
        for i in range(2, int(MAX ** 0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, MAX, i):
                    is_prime[j] = False

        # Find the closest primes in range [left, right]
        prev_prime = -1
        min_diff = float("inf")
        result = [-1, -1]

        for num in range(left, right + 1):
            if is_prime[num]:
                if prev_prime != -1:
                    diff = num - prev_prime
                    if diff < min_diff:
                        min_diff = diff
                        result = [prev_prime, num]
                    # **Optimization**: Break early if minimum prime gap (2) is found
                    if diff == 2:
                        return result
                prev_prime = num

        return result
