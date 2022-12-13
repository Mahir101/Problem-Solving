class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) {
            return x;
        }
        double hi = x*1.0;
        double lo = 0.0;
        int iter = 300;
        double ans = 0.0;
        while(iter--) {
            double mid = lo+(hi-lo)/2.0;
            cout<<mid<<endl;
            if(abs(x-mid*mid)<0.000001) {
                ans = mid;
                break;
            }
            if(mid*mid<x) {
                lo = mid;
            }else {
                hi = mid;
            } 
            
        } 
     return (int)ans;
    }
};
