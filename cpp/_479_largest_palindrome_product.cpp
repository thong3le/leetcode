class Solution {
public:
    int largestPalindrome(int n) {
        if (n==1) return 9;
        int upper = (int)pow(10, n) - 1, lower = upper/10, half = upper;
        long p;
        while (half-- >= lower) {
            p = createPalindrome(half);
            for(long i = upper; i >= lower; i--){
                if (p/i > upper || i*i < p) break;
                if (p%i == 0) return (int)(p % 1337);
            }
        }
        return -1;
    }
    
    long createPalindrome(int half) {
        string s1 = to_string(half), s2(s1);
        reverse(s2.begin(), s2.end());
        return stol(s1 + s2);
    }
};