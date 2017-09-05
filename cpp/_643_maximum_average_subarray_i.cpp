class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long sum = 0;
        for(int i = 0; i < k; i++) sum += nums[i];
        long ans = sum;
        for(int i = k; i < nums.size(); i++){
            sum += nums[i] - nums[i-k];
            ans = max(ans, sum);
        }
        return (double)ans/k;
    }
};