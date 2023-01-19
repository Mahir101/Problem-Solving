
// Accepted Solution
class Solution {
public:
    void dfsCountAndUpdate(int node, int prevNode, vector<vector<int>>& adjVec,
                           string& labels, vector<int>& solution, vector<int>& freqMap) {
        // Maintain a count of freq till now.
        int prevCount = freqMap[labels[node] - 'a'];

        freqMap[labels[node] - 'a'] += 1;
        // Count the no. of chars in all the child subtrees.
        for (int nextNode : adjVec[node]) {
            if (prevNode == nextNode) continue;
            dfsCountAndUpdate(nextNode, node, adjVec, labels, solution, freqMap);
        }

        solution[node] = freqMap[labels[node] - 'a'] - prevCount;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjVec(n, vector<int>());

        for (vector<int>& edge : edges) {
            adjVec[edge[0]].push_back(edge[1]);
            adjVec[edge[1]].push_back(edge[0]);
        }

        vector<int> solution(n, 0);
        vector<int> freqMap = vector<int>(26, 0);
        dfsCountAndUpdate(0, 0, adjVec, labels, solution, freqMap);

        return solution;
    }
};

// MY TLE SOLUTION

class Solution {
private:
    vector<int> ans;
public:
    Solution() : ans(100005,0) {}
public:
    map<char, int > vec;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjList(n);
        for(auto x: edges) {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }


        dfs(0, -1, adjList, labels);

        return {ans.begin(), ans.begin()+n};
        
    }

    void dfs(int child, int par, vector<vector<int>> adjList, string labels) {
        for(int x: adjList[child]) {  
            if(x==par) {
                continue;
            }
            dfs(x, child, adjList, labels);
        }
        vec[labels[child]]++;

    
        ans[child]+= vec[labels[child]];
  

        cout<<child<<" "<<par<<endl;
        for(auto x: vec) {
            cout<<x.first<<" "<<x.second;
        }
        cout<<endl;
        
        if(par==0) {
            ans[0] += vec[labels[0]];
            vec.clear();
        }
    
    }
};
