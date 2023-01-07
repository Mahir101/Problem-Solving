class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int top, bottom;
        int l = 0, r = n-1;
        while(l<r) {
            for(int i=0; i<r-l; i++) {

                int topLeft = matrix[l][l+i];
                
                matrix[l][l+i] = matrix[r-i][l];
                
                matrix[r-i][l] = matrix[r][r-i];

                matrix[r][r-i] = matrix[l+i][r];
                
                matrix[l+i][r] = topLeft;

            }
            r--;
            l++;
        
        }
    }
};
