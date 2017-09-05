/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 387 - First Unique Character in a String
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
    int firstUniqChar(string s) {
        int count[26] = {0};
        for(char c : s) count[c-'a']++;
        for(int i = 0; i < s.length(); i++)
            if (count[s[i]-'a'] == 1) return i;
        return -1;
    }
};

int main() {
	return 0;
}
