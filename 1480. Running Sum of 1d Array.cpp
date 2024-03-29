class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int cur = nums[0];
        for(int i=1; i<nums.size(); i++) {
            cur += nums[i];
            nums[i] = cur;
        }
        return nums;
    }
};
