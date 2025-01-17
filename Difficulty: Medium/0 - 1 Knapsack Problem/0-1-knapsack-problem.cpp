//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int t[1001][1001];
    int solve(vector<int>& wt, vector<int>& val,int W,int n) {
        if(n==0 || W==0){
            return 0;
        }
        if(t[n][W] != -1){
            return t[n][W];
        }
        if(wt[n-1] <= W){
            return t[n][W] = max(val[n-1] + solve(wt,val,W-wt[n-1],n-1) , solve(wt,val,W,n-1));
        }
        else if(wt[n-1] > W){
            return t[n][W] = solve(wt,val,W,n-1);
        }
    }
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        memset(t,-1,sizeof(t));
        return solve(wt,val,capacity,wt.size());
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends