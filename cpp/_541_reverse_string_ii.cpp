/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 541 - Reverse String II
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
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.length(); i+=2*k)
            if (i + k <= s.length())
                reverse(s.begin() + i, s.begin() + i + k);
            else 
                reverse(s.begin() + i, s.end());
        return s;
    }
};

int main() {
	return 0;
}
