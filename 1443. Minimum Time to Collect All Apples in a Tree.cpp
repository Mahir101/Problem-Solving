class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>> adjList(n);
        for(auto x: edges) {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }

        int x =  dfs(0, -1, adjList, hasApple);
        return x>0?x-2:x;

        
    }

    int dfs(int child, int par, vector<vector<int>>& adjList, vector<bool>& hasApple) {
        int ans = 0;
        // cout<<adjList[start].size()<<endl;
        for(int x: adjList[child]) {  // parent != child
            // cout<<x<<" ";
            if(x==par) {
                continue;
            }
            ans += dfs(x, child, adjList, hasApple);
            
        }

       // cout<<child<< " "<<ans<<endl;

        if(hasApple[child] || ans>0) {
            ans+=2;
        }

       // cout<<child<< " "<<ans<<endl;
       // cout<<endl;

    
        return ans;
    }
};
