//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isPossibleSoln(int arr[], int n, int m,int mid){
        int pagesum = 0;
        int studentcount = 1;
        for(int i=0;i<n;i++) {
            if(pagesum + arr[i] <= mid){
                pagesum += arr[i];
            }
            else {
                studentcount++;
                if(studentcount>m || arr[i] > mid)return false;
                pagesum = arr[i];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m>n){
            return -1;
        }
        int start = 0;
        int end = 0;
        
        for(int i=0;i<n;i++){
            end = end + arr[i];
        }
        int ans = -1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(isPossibleSoln(arr,n,m,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends