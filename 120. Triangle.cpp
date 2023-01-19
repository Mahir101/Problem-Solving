class Solution {
public:
    int dp[205][205];
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        for(int i=0; i<205; i++) 
            for(int j=0; j<205; j++)
                dp[i][j] = INT_MAX;
    
        return recur(triangle,0,0);
    }
    
    int recur(vector<vector<int> >& triangle, int row, int idx) {
        if(dp[row][idx]!=INT_MAX) return dp[row][idx];
        int path = triangle[row][idx];
        if(row< triangle.size()-1)
            path += min(recur(triangle, row+1, idx), recur(triangle, row+1, idx+1));        
        return dp[row][idx] = path;
        
    }
    
    // 2
    // 3 4
    // 6 5 1
    // 4 1 8 3
};
