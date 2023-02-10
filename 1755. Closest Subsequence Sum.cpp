class Solution {
public:
    void solve(vector<int>&arr , int idx , int limit , int total , vector<int>&sums) { // 2^n e calculate kore subset ber kore fellam all possible
        if(idx==limit)
        {
            sums.push_back(total) ; 
            return ; 
        }
        solve(arr, idx+1, limit, total, sums) ; 
        solve(arr, idx+1, limit, total+arr[idx], sums) ;
    }
// it can be done iteratively ans->1,2,3 and for x in nums just add that to temp_ans = 1+x,2+x,3+x and then  finally ans -> 1,2,3,1+x,2+x,3+x
// so forenforth
    
    void search(vector<int>&left , vector<int>&right , int &ans , int target) {
        int l = 0 ; 
        int r = right.size()-1 ; 
      //  binary search could have been applied to optimize this // two pointer techqiue diye 2 sum ber kora jei technique sheta 
        while(l < left.size() && r >= 0) {
            int ss = left[l] + right[r] ; 
            ans = min(ans , abs(target - ss)) ; 
            if(ss < target) l++ ; 
            else if(ss > target) r-- ; 
            else break ; 
        }
    }
    int minAbsDifference(vector<int>& arr, int target) {
        int n = arr.size() ; 
        int ans = INT_MAX ; 
        vector<int>left, right ; 
        solve(arr, 0, n/2+1, 0, left) ; 
        solve(arr, n/2+1, n, 0, right) ; 
        
        for(int i=0; i<left.size(); i++) {
            ans = min(ans, abs(target - left[i])) ; 
        }
        for(int i = 0; i<right.size(); i++) {
            ans = min(ans, abs(target-right[i])) ; 
        }
        
        sort(left.begin(), left.end()) ;
        sort(right.begin(), right.end()) ; 
        search(left, right, ans, target) ; 
        return ans; 
        
    }
};
