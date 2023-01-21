class Solution {
public:
    void recur(int idx, vector<int>& nums,vector<int>& cur,set<vector<int>>& ans, int n) {
        if(idx>=n) {
            if(cur.size()>=2) {
                ans.insert(cur);
            }
            return; 
        }
        if(!cur.size() || nums[idx]>=cur.back()) {
            cur.push_back(nums[idx]);
            recur(idx+1, nums, cur, ans, n);
            cur.pop_back();
        }
        recur(idx+1, nums, cur, ans, n);
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur;
        set<vector<int>> ans;

        int n = nums.size();
        recur(0, nums, cur, ans, n);
        return vector(ans.begin(), ans.end());

    }
};
