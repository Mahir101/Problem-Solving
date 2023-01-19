class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gas = 0;
        int total_cost = 0;
        int cur = 0;
        int idx = 0;
        for(int i=0; i<n; i++) {
            total_gas+=gas[i];
            total_cost+=cost[i];

            cur+=gas[i]-cost[i];
            if(cur<0) {
                cur = 0;
                idx = i+1;
            }
        }
        if(total_gas<total_cost) {
            return -1;
        }
        return idx;
    }
};
