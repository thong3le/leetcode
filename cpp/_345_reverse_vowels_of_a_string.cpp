/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 345 - Reverse Vowels of a String
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
    string reverseVowels(string s) {
        int map[256] = {0};
        map['a'] = 1; map['e'] = 1; map['o'] = 1; map['u'] = 1; map['i'] = 1;
        map['A'] = 1; map['E'] = 1; map['O'] = 1; map['U'] = 1; map['I'] = 1;
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && map[s[i]] == 0) i++;
            while (i < j && map[s[j]] == 0) j--;
            swap(s[i], s[j]);
            i++; j--;
        }
        return s;
    }
};


int main() {
	return 0;
}
