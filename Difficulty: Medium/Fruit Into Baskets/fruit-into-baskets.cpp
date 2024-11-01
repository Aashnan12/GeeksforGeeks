//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int left = 0;
        int n = arr.size();
        int right = 0;
        int baskets = 2;
        unordered_map<int,int> mp;
        int maxi = 0;
        
        while(right < n){
            mp[arr[right]]++;
            while(mp.size() > baskets){
                mp[arr[left]]--;
                if(mp[arr[left]] == 0){
                    mp.erase(arr[left]);
                }
                left++;
            }
            if(mp.size() <= baskets){
                maxi = max(maxi,right-left+1);
            }
            right++;
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends