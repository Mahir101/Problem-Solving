class Solution {
public:
    int dp[101][101];
    int uniquePaths(int m, int n) {
        
        for(int i=n-1; i>=0; i--) {
            dp[i][m-1] = 1;
        }

        for(int i=m-1; i>=0; i--) {
            dp[n-1][i] = 1;
        }
        for(int i=n-2; i>=0; i--) {
            for(int j=m-2; j>=0; j--) {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};



class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        row = [1] * n
        
        for i in range(m-1):
            newRow = [1] * n
            for j in range(n-2, -1, -1):
                newRow[j] = newRow[j+1]+row[j]
            row = newRow
        return row[0]
        
        

