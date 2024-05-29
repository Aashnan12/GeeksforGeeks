//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int n;
    unordered_map<int,vector<int>> map;
    
    void dfs(int i,vector<bool> &vis){
        vis[i] = true;
        for(int &u : map[i]){
            if(!vis[u]){
                dfs(u,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        n = V;
        map.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && adj[i][j] == 1){
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }
        int pro = 0;
        
        vector<bool> vis(n+1,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                pro++;
                dfs(i,vis);
            }
        }
        return pro;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends