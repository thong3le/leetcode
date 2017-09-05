class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int min = nums[n-1], max = nums[0], left = -1, right = -1;
        for(int i = 0; i < n; i++) {
            max = std::max(nums[i], max);
            min = std::min(nums[n-1-i], min);
            if (nums[i] < max) right = i;
            if (nums[n-1-i] > min) left = n-1-i;
        }
        return (left == -1) ? 0 : (right-left+1);
        
    }
    int findUnsortedSubarray2(vector<int>& nums) {
        int n = nums.size();
        int rank[n];
        for(int i = 0; i < n; i++) rank[i] = i;
        stable_sort(rank, rank+n, [&](int i, int j){return nums[i] < nums[j];});
        int left = 0, right = n-1;
        while (left <= right) {
            if (rank[left] == left) left++;
            else if (rank[right] == right) right--;
            else break;
        }
        return (right-left+1);
    }
};