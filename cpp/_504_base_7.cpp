/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 504 - Base 7
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
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string result;
        int positive = abs(num);
        while (positive) {
            char c = '0' + (positive % 7);
            result.push_back(c);
            positive /= 7;
        }
        if (num < 0) result.push_back('-');
        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
	return 0;
}
