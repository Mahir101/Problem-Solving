class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mods(k,0);
        int cnt = 0;
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            mods[((sum%k)+k)%k]++;
            // cout<<((sum%k)+k)%k << " ";
        }
        for(int i=0; i<k; i++) {
            if(mods[i]>0) {
                cnt+=(mods[i]*(mods[i]-1))/2;
            }
        }
        
        cnt+=mods[0];
        return cnt;
    }  
};
// used to solve this things withing 7 to 30 minutes once (CF-B)
// sad life it was very easy  n*(n+1)/2  -> since n = x-1 that is why x-1*(x-1+1)/2 = x*(x-1)/2
