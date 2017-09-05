/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 383 - Ransom Note
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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (char c : magazine) map[c]++;
        for(char c: ransomNote){
            if(map.find(c) == map.end() || map[c] == 0) return false;
            map[c]--;
        }
        return true;
    }

    bool canConstruct2(string ransomNote, string magazine) {
        int count[26] = {0};
        for (char c : magazine) count[c - 'a']++;
        for(char c: ransomNote)
            if(--count[c-'a'] < 0) return false;
        return true;
    }
};


int main() {
	return 0;
}
