class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2) {
            return n;
        }

        int ans = 0;
        int mx = 0;
        unordered_map<double, int> mp;
        for(int i=0; i<points.size(); i++) {
            mp.clear();
           
            double x1 = points[i][0];
            double y1 = points[i][1];
 
            for(int j=0; j<points.size(); j++) {
                double x2 = points[j][0];
                double y2 = points[j][1];

                if(x1==x2 && y1==y2) continue;

                double val;

                if(x2-x1 == 0) {
                    val = INT_MAX;
                } else {
                    val = (y2-y1)/(x2-x1);
                }

                mp[val]++;
                mx = max(mx, mp[val]);
            }
            
        }
        return mx+1;

    }
};
