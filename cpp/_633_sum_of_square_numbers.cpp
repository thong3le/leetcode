class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) return true;
        int a = 0, b = (int)sqrt(c), sum;
        while (a <= b) {
            sum = a*a + b*b;
            if (sum == c) return true;
            else if (sum < c) a++;
            else b--;
        }
        return false;
    }
};