//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void validPath(vector<vector<int>> &maze,int i,int j,int n,string &ans,vector<string> &result,vector<vector<bool>> &visited){
        
        if(i<0 || i>=n || j<0 || j>=n || maze[i][j]==0 || visited[i][j]==1){
            ans.pop_back();
            return;
        }
        
        if(i==n-1 && j==n-1){
            result.push_back(ans);
            ans.pop_back();
            return;
        }
        
        visited[i][j] = 1;
        
        ans += 'U';
        validPath(maze,i-1,j,n,ans,result,visited);
        
        ans += 'D';
        validPath(maze,i+1,j,n,ans,result,visited);
        
        ans += 'L';
        validPath(maze,i,j-1,n,ans,result,visited);
        
        ans += 'R';
        validPath(maze,i,j+1,n,ans,result,visited);
        
        //backtrack
        visited[i][j] = 0;
        ans.pop_back();
        return;
        
    }
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> result;
        string ans = "";
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        if(maze[0][0] != 0){
            validPath(maze,0,0,n,ans,result,visited);
        }
        return result;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends