/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 405 - Convert a Number to Hexadecimal
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
    string toHex(int num) {
        const string HEX = "0123456789abcdef";
        if (num == 0) return "0";
        string result;
        for(int i = 0; i < 8; i++) {
            result.push_back(HEX[num & 0xf]);
            num >>= 4;
            if (num == 0) break;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
	int x = -223232124;
	bitset<32> b(x);
	cout << b << endl;
	x >>= 4;
	bitset<32> c(x);
	cout << c << endl;
	cout << x << endl;
	return 0;
}
