class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        bool flag = false;
        
        if(nums1.size()<nums2.size()) {
            flag = true;
        }
        
        map<int, int> mp;
        vector<int> ans;

        if(!flag) {
            for(int i=0; i<nums1.size(); i++) {
                mp[nums1[i]]++;
            }
            for(int i=0; i<nums2.size(); i++) {
                if(mp[nums2[i]]) {
                    mp[nums2[i]]--;
                    ans.push_back(nums2[i]);
                }
            }
        } else {
            for(int i=0; i<nums2.size(); i++) {
                mp[nums2[i]]++;
            }
            for(int i=0; i<nums1.size(); i++) {
                if(mp[nums1[i]]) {
                    mp[nums1[i]]--;
                    ans.push_back(nums1[i]);
                }
            }
        }
        

        return ans;
        
    }
};
