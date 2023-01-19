class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int> > ans;
        for(vector<int> ivl: intervals) {
            if (newInterval[0] > ivl[1]) {
                ans.push_back(ivl);
            } else if(newInterval[1] < ivl[0]) {
                ans.push_back(newInterval);
                newInterval = ivl;
            } else {
                newInterval[0] = min(newInterval[0],ivl[0]);
                newInterval[1] = max(newInterval[1],ivl[1]);
            }
        }
            
        ans.push_back(newInterval);
        return ans;

    }
};
