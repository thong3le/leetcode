/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 400 - Nth Digit
*
*    Solution Approach: 
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
    int findNthDigit(int n) {
        int d = 1;
        long range = 9;
        while (n > d*range) {
            n -= (d++)*range;
            range *= 10;
        }
        int target = range/9 + (n-1)/d;
        int idx = (n-1)%d;
        while (d-- > idx+1) target = target/10;
        return target%10;
    }
};


int main() {
	int n = 1000000000;
	cout << Solution().findNthDigit(n) << endl;
	return 0;
}
