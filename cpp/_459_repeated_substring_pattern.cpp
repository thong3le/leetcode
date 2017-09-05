/* 
*    Author: Thong Le
*    Date: 
*   
*    LeetCode 459 - Repeated Substring Pattern
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
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if (n <= 1) return false;
        vector<int> lps(n,0);
        int i = 1, j = 0;
        while (i < n) {
            if (s[i] == s[j]) lps[i++] = ++j;
            else if (j == 0) lps[i++] = 0;
            else j = lps[j-1];
        }
        return lps[n-1] && n % (n - lps[n-1]) == 0;
    }
    
    bool repeatedSubstringPattern2(string s) {
        if (s.length() <= 1) return false;
        string t = s.substr(1) + s.substr(0, s.length()-1);
        return t.find(s) != string::npos;
    }
};


// find the longest common proper prefix and suffix of input string
vector<int> kmp(string s) {
	int n = s.length();
	vector<int> lps(n, 0);
	int i = 1, j = 0;
	while (i < n) {
		if (s[i] == s[j]) lps[i++] = ++j;
		else if (j == 0) i++;
		else j = lps[j-1];
	}
	return lps;
}

int main() {
	string s = "abababcaba";
	vector<int> lps = kmp(s);
	cout << s << endl;
	for(int i = 0; i < lps.size(); i++) 
		cout << "lps[" << i << "] = " << lps[i] << endl;
	cout << endl;

	return 0;
}
