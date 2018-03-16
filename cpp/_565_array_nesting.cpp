class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 1, count;
        for(int i = 0; i < nums.size(); i++){
            count = 0;
            while (i != nums[i]){
                swap(i, nums[i]);
                count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};