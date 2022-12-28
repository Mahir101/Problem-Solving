class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> temp = nums;
        int cur = nums[0];
        int sz = nums.size();
        for(int i=1; i<sz; i++) {
            cur += nums[i];
            nums[i] = cur;
        }

        int desired_index = -1;
        for(int i=0; i<sz; i++) {
            if(i==0) {
                if(nums[sz-1]-temp[i]==0) {
                    desired_index = i;
                    break;
                }
            }
            else if(sz-1==i) {
                if(nums[sz-2]==0) {
                    desired_index = i;
                    break;
                }
                
            } else {
                int left_val = nums[i]-temp[i];
                int right_val = cur-nums[i];
                if(left_val == right_val) {
                    desired_index = i;
                    break;
                }
            }
        }

        return desired_index;
        
    }
};
