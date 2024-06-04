//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
   int N;
   int t[1001];
    int solve(int len,int price[]){
        if(t[len] != -1){
            return t[len];
        }
        int ans = 0;
        for(int len_cut=1;len_cut<=N;len_cut++){
            if(len - len_cut >= 0){
                ans = max(ans,solve(len-len_cut,price) + price[len_cut - 1]); 
            }
        }
        return t[len]=ans;
    }
    int cutRod(int price[], int n) {
        memset(t,-1,sizeof(t));
        N = n;
        return solve(n,price);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends