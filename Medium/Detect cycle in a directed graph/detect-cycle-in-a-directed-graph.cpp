//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> indegree(V,0);
        
        // Step 1 -> fill up Indegree Array
        for(int i=0;i<V;i++){
            for(int &v : adj[i]){
                indegree[v]++;
            }
        }
        
        // Step 2 -> Pushing Indegree 0 Nodes into queue;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // Step 3 -> Simple bfs / Kanh's Algo
        
        int count = 0;
        while(!q.empty()){
            int u = q.front();
            count++;
            q.pop();
            
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return count == V ? false : true;
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