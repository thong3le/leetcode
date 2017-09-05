class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0; 
        for(int i = 0, cur = 0, pre = 0; i < nums.size(); i++){
            if (i == 0 || nums[i] == nums[i-1])
                cur++;
            else {
                pre = (nums[i]-nums[i-1] == 1) ? cur : 0;
                cur = 1;
            }
            if (cur && pre) ans = max(ans, cur + pre);
        }
        return ans;
    }
};