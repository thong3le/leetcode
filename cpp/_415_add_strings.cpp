/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 415 - Add Strings
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
    string addStrings(string num1, string num2) {
        string ans;
        int carry = 0, digit;
        for(int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0 || carry; i--,j--){
            digit = carry;
            if (i >= 0) digit += (num1[i] - '0');
            if (j >= 0) digit += (num2[j] - '0');
            carry = digit/10;
            ans.push_back(digit%10 + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
	return 0;
}
