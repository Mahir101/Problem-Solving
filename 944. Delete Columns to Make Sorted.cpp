class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int sz = strs[0].size();

        int cnt = 0;
        char inHand;
        for(int i=0; i<sz; i++) {
            for(int j=0; j<strs.size(); j++) {
                // cout<<strs[j][i]<< " ";

                if(j==0) {
                    inHand = strs[j][i];
                    continue;
                } 

                if(inHand>strs[j][i]) {
                    cnt+=1;
                    break;
                } else {
                    inHand = strs[j][i];
                }
            }
            // cout<<endl;
        }
        return cnt;
    }
};
