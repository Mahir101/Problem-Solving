class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        bool flag = false;
        for(int i=0; i<word.size(); i++) {
            if(word[i]<='Z' && word[i]>='A') {
                cnt++;
                if(i==0) {
                    flag = true;
                }
            }
        }

        if(flag) {
            if(cnt==1 || cnt==word.size()) {
                return true;
            } else {
                return false;
            }
        } else {
            if(cnt) {
                return false;
            } else {
                return true;
            }
        }
        
    }
};
