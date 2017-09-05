/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 551 - Student Attendance Record I
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
    bool checkRecord(string s) {
        int countA = 0;
        for(int i = 0; i < s.length(); i++){
            if (s[i] == 'A') countA++;
            if (countA > 1) return false;
            if (i > 1 && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L') return false;
        }
        return true;
    }
};


int main() {
	return 0;
}
