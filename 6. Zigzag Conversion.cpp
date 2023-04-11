class Solution {
public:
    string convert(string s, int numRows) {
        vector<int> v[numRows];
        int direction = 1;
        int sz = s.size();
        int rev = numRows/2;
        int revConst = rev+1;
        int track = 1;
        if(numRows==1) return s;
        if(numRows==2) {
            string ans= "";
            for(int i=0; i<sz; i+=2) {
                ans.push_back(s[i]);
            }
            for(int i=1; i<sz; i+=2) {
                ans.push_back(s[i]);
            }
            return ans;
        }
        for(int i=0; i<sz; i++) {
            if(direction==1) {
                if(track==numRows+1) {
                    direction = -1;
                    track=numRows-1;
                    v[track-1].push_back(s[i]);
                    continue;
                }
                v[track-1].push_back(s[i]);
                track++;
            } else {
                --track;
                if(track==1) {
                    v[track-1].push_back(s[i]);
                    direction = 1;
                    track++;
                    continue;
                }
                v[track-1].push_back(s[i]);
            }
        }
        string ans = "";
        for(int i=0; i<numRows; i++) {
            for(auto &x: v[i]) {
                ans.push_back(x);
            }
        }
        return ans;
        // PAYPALISHIRING

        // p h
        // asi
        // yir
        // plig
        // a n
    }
};
