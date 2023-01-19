class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sz = nums.size();
        int sum = 0;
        int mx = nums[0];
        for(int i=0; i<sz; i++) {
            sum+=nums[i];
            if(sum<0 ) 
                sum=0;
            // mx=max(mx,nums[i]);
            mx=max(mx, sum);
        }

        int mnSum = 0;
        int mn = nums[0];      
        sum = 0;
        int maxInMin = nums[0];
        int mnc = 0;
        for(int i=0; i<sz; i++) {
            sum+=nums[i];
            mnSum+=nums[i];

            maxInMin = max(maxInMin, nums[i]);
            if(nums[i]<0) {
                mnc++;
            }

            if(mnSum>0) {
                mnSum = 0;
            }
    
            mn=min(mn, mnSum);
        }
        if(mnc==sz) {
            return maxInMin;
        }
        // if(sum==mnSum) {
        //     return maxInMin;
        // }
        return max(mx, sum-mn);

     
    }
};
