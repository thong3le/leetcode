/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 367 - Valid Perfect Square
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
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num <= 1) return true;
        int lo = 1, hi = num/2, mid;
        while (lo <= hi) {
            mid = (lo + hi)/2;
            cout << lo << ' ' << mid << ' ' << hi << endl;
            if (mid == (float)num/mid) return true;
            else if (mid < (float)num/mid) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
    bool isPerfectSquare2(int num) {
        if (num < 0) return false;
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};


int main() {
	Solution sol;
	cout << sol.isPerfectSquare(808201) << endl;
	return 0;
}
