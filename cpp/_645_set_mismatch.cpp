class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int count[n+1] = {0};
        int sum = n*(n+1)/2, dup;
        for (int x : nums){
            if (count[x]) dup = x;
            count[x]++;
            sum -= x;
        }
        return {dup, sum + dup};
    }
};