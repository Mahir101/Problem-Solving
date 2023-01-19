class Solution {
public:
    vector<int> child[100001];
    int ans;
    int dfs(string &s, int node) {
        if(child[node].empty())
            return 1;

        int mx1 = 0, mx2 =0;
        for(auto child_node : child[node]) {
            int len = dfs(s, child_node);
            // cout <<"len->"<< len << endl;
            ans = max(ans, len);

            // cout<<"ans->"<<ans<<endl;
            // cout<<s[node]<<" "<<s[child_node]<<endl;

            if(s[node] == s[child_node]) {
                continue;
            }

            if(len > mx1) {
                mx2 = mx1;
                mx1 = len;
            }
            else { 
                mx2 = max(mx2 , len);
            }
        }
        ans = max(ans, 1 + mx1 + mx2);
        return 1 + mx1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        for(int i=1; i<n; i++) {
            child[parent[i]].push_back(i);
        }
        ans = 1;
        dfs(s,0);
        return ans;
    }
};

// I couldn't catch this problem tbh [brain not so sharp i guess]
