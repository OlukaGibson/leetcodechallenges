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