/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 409 - Longest Palindrome
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
    int longestPalindrome(string s) {
        int count[256] = {0};
        for (char c : s) count[c]++;
        int odds = 0;
        for(int i = 0; i < 256; i++)
            if (count[i] % 2) odds++;
        return s.length() - odds + (odds>0);
    }
};


int main() {
	return 0;
}
