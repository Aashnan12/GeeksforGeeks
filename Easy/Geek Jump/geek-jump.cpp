//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int t[100001];
    int solve(int n,vector<int>& height){
        if(n == 0){
            return 0;
        }
        
        if(t[n] != -1){
            return t[n];
        }
        
        int cost = INT_MAX;
        cost = min(cost,solve(n-1,height) + abs(height[n] - height[n-1]));
        if(n>1)
        cost = min(cost,solve(n-2,height) + abs(height[n] - height[n-2]));
        
        return t[n] = cost;
        
    }
    int minimumEnergy(vector<int>& height, int n) {
        memset(t,-1,sizeof(t));
        return solve(n-1,height);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends