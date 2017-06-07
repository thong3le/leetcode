/* 
*    Author: Thong Le
*    Date: May 2, 2017
*   
*    LeetCode 344 - Reverse String
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
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};


int main() {
	return 0;
}
