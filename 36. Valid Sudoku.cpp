class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, map<int, int> > rows;
        map<int, map<int, int> > cols;
        map<int, map<int, map<int, int> > > boxes;
       

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                int p = board[i][j];
                if(p=='.') continue;
                if(rows[i][p]) return false;
                if(cols[j][p]) return false;
                if(boxes[i/3][j/3][p]) return false;
                
                rows[i][p]++;
                cols[j][p]++;
                boxes[i/3][j/3][p]++;

            }
        }

        return true;
    }
};
