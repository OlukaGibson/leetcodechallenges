class Solution {
    bool isVowel(char c){
        return c == 'a' or c == 'e'
        or c == 'i' or c == 'o'
        or c == 'u';
    }
    bool ok(map<char, int> &mappa, int myK, int k){
        return mappa['a'] and mappa['e']
        and mappa['i'] and mappa['o']
        and mappa['u'] and myK >= k;
    }
    long long greaterThanOrEqualToK(string word, int k) {
        if(k < 0)
            return 0;
        long long res = 0;
        map<char, int> mappa;
        int i = 0, j = 0, n = word.size(), myK = 0;
        while(j < n){
            if(isVowel(word[j]))
                mappa[word[j]]++;
            else
                myK++;
            while(ok(mappa, myK, k)){
                res += n - j;
                if(isVowel(word[i]))
                    mappa[word[i]]--;
                else
                    myK--;
                i++;
            }
            j++;
        }
        return res;
    }
public:
    long long countOfSubstrings(string word, int k){
        return greaterThanOrEqualToK(word, k) - greaterThanOrEqualToK(word, k+1);
    }
};