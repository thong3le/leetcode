/* 
*    Author: Thong Le
*    Date: May 2, 2017
*   
*    LeetCode 371 - Sum of Two Integers
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
    int getSum(int a, int b) {
        return b==0 ? a : getSum(a^b, (a&b)<<1); 
    }
};


int main() {
	return 0;
}
