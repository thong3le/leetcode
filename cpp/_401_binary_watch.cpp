/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 401 - Binary Watch
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
#include <bitset>

using namespace std;

class Solution {
public:
    int countones(int i){
        int cnt = 0;
        while (i){
            if (i%2) cnt++;
            i >>= 1;
        }
        return cnt;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for(int h = 0; h < 12; h++)
            for(int m = 0; m < 60; m++)
                if (countones(h) + countones(m) == num)
                    result.push_back(to_string(h) + ((m < 10) ? ":0" : ":") + to_string(m));
        return result;
    }
};


int main() {
    bitset<100> foo(123 << 10 | 124);
    cout << foo[50] << endl;
    cout << foo << endl;
	return 0;
}
