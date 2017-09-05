/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 326 - Power of Three
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
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n%3 == 0) n /= 3;
        return n==1;
    }
};


int main() {
	return 0;
}
