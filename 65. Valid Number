class Solution {
public:
    bool isNumber(string s) {
        //exclusion -> +. -. -- ++, no alphabets
        int sz = s.size();
        int countPM = 0, countDot = 0, countE = 0, numCount = 0, countAlpha = 0;
        int indexE = -1, indexDot = -1, indexPM = -1;
        for(int i=0; i<sz; i++) {
            if(i+1<sz && ((s[i]=='+' || s[i]=='-') && (s[i+1]=='+' 
                || s[i+1]=='-' || s[i+1]=='E' || s[i+1]=='e'))) {
                return false;
            }

            if(i-1>=0 && ((s[i]=='+' || s[i]=='-') && (s[i-1]=='.' ||
                s[i-1]=='+' || s[i-1]=='-' ))) {
                return false;
            }

            if(s[i]=='+' || s[i]=='-') {
                if(i==sz-1) return false;
                if(sz==1) return false;
                
                if(i!=0 && ((s[i-1]>='0' && s[i-1]<='9') ||  (s[i-1]>='0' && s[i-1]<='9'))) {
                    return false;
                }
                countPM++;
                indexPM = i;
            }

            if(s[i]=='e' || s[i]=='E') {
                indexE = i;
                countE++;
                if(i==sz-1 || countE>1 || i==0) return false;
            }

            if(s[i]=='.') {
                indexDot = i;
                countDot++;
                if(countDot>1 || (i==0 && sz==1) )  {
                    return false;
                }
                if(sz>1 && i==sz-1) {
                    if(s[i-1]=='+' || s[i-1]=='-') return false;
                }
            }

            if((s[i]>='a' && s[i]<='z') ||  (s[i]>='A' && s[i]<='Z')) {
                countAlpha++;
            }
            // if(i+1<sz && s[i]=='.' && (s[i+1]=='e'||s[i+1]=='E' )) {
            //     return false;
            // }

            // if(i-1>=0 && s[i]=='.' && (s[i]=='e'||s[i]=='E' )) {
            //     return false;
            // }

        }
        if(countAlpha-countE>0) {
            return false;
        }
        if(indexE!=-1 && indexDot!=-1 && indexDot>indexE) {
            return false;
        }
        string x = ".e", y =".E";
        if(strstr(s.c_str(), x.c_str()) && s[0]=='.') {
            return false;
        }

        if(strstr(s.c_str(), y.c_str()) && s[0]=='.') {
            return false;
        }
        return true;
        
    }
};
