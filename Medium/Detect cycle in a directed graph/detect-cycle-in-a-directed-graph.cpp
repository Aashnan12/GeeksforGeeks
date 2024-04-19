//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool isCycleDfs(vector<int> adj[],int u,vector<bool> &vis , vector<bool> &inrecurr) {
        vis[u] = true;
        inrecurr[u] = true;
        
        for(int &v : adj[u]){
            if(vis[v]== false && isCycleDfs(adj,v,vis,inrecurr)) return true;
            else if(inrecurr[v]){
                return true;
            }
        }
        inrecurr[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,false);
        vector<bool> inrecurr(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] && isCycleDfs(adj,i,vis,inrecurr)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends