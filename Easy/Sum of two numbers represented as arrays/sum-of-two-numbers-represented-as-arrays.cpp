//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	void reverse(vector<int> &sum) {
	    int i=0;
	    int j = sum.size()-1;
	    
	    while(i<j)
	    {
	        swap(sum[i++],sum[j--]);
	    }
	}
	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    // code here
	    vector<int> sum;
	    int n = a.size();
	    int m = b.size();
	    
	    int i = n-1;
	    int j = m-1;
	    int carry = 0;
	    
	    while(i>=0 && j >= 0) {
	        int s = a[i] + b[j] + carry;
	        sum.push_back(s%10);
	        carry = s/10;
	        i--;
	        j--;
	    }
	    while(i>=0) {
	        int s = a[i] + carry;
	        sum.push_back(s%10);
	        carry = s/10;
	        i--;
	    }
	    while(j >= 0) {
	        int s =  b[j] + carry;
	        sum.push_back(s%10);
	        carry = s/10;
	        j--;
	    }
	    if(carry) {
	        sum.push_back(carry);
	    }
	    
	    reverse(sum);
	    
	    return sum;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends