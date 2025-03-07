class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<int> primes;
            for (int i = left; i <= right; i++){
                if i%1 ==0 && i%2 == 1 && i%3 == 1 && i%i == 0 && i != 1 && i != 2 && i != 3{
                    primes.push_back(i);
                }
                else if (i == 2 || i == 3)
                {
                    primes.push_back(i);
                }
                
            }
            int min_diff = INT_MAX;
            vector<int> res;
            for (int i = 0; i < primes.size() - 1; i++){
                if (primes[i + 1] - primes[i] < min_diff){
                    min_diff = primes[i + 1] - primes[i];
                    res = {primes[i], primes[i + 1]};
                }
            }
        }
        return res;
    };

    // class Solution {
    //     public:
    //         vector<int> closestPrimes(int left, int right) {
    //             // Define an upper bound for primes (Sieve of Eratosthenes)
    //             const int MAX = 1e6 + 1;
    //             vector<bool> isPrime(MAX, true);
    //             isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
        
    //             // Optimized Sieve of Eratosthenes
    //             for (int i = 2; i * i < MAX; i++) {
    //                 if (isPrime[i]) {
    //                     for (int j = i * i; j < MAX; j += i) {
    //                         isPrime[j] = false;
    //                     }
    //                 }
    //             }
        
    //             // Find first prime within range [left, right]
    //             int prevPrime = -1, minDiff = INT_MAX;
    //             vector<int> result = {-1, -1};
        
    //             for (int i = left; i <= right; i++) {
    //                 if (isPrime[i]) {
    //                     if (prevPrime != -1) {
    //                         int diff = i - prevPrime;
    //                         if (diff < minDiff) {
    //                             minDiff = diff;
    //                             result = {prevPrime, i};
    //                         }
    //                         // **Optimization**: If the difference is 2, it's the smallest possible prime gap, so we can stop early.
    //                         if (diff == 2) return result;
    //                     }
    //                     prevPrime = i;
    //                 }
    //             }
        
    //             return result;
    //         }
    //     };
        