/* 
*    Author: Thong Le
*    Date: May 2, 2017
*   
*    LeetCode 29 - Divide Two Integers
*
*    Solution Approach: Using bit manipulation
*
*
*
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (! divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long dvd = abs((long)dividend);
        long dvs = abs((long)divisor);
        bool sign = (dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0);
        int q = 0;
        while (dvd >= dvs){
            long x = dvs;
            int c = 1;
            while (x << 1 <= dvd) {
                x = x<<1;
                c <<= 1;
            }
            dvd -= x;
            q += c;
        }
        return sign ? q : -q;   
    }
};


int main() {
	int dividend = 2321312, divisor = 2;
	Solution *sol = new Solution();
	cout << sol->divide(dividend, divisor) << endl;
	return 0;
}
