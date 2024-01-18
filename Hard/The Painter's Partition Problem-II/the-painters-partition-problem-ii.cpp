//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossibleSoln(int arr[], int n, int k,long long int mid){
        int paintercount = 1;
        int boardsum = 0;
        for(int i=0;i<n;i++){
            if(boardsum + arr[i] <= mid){
                boardsum += arr[i];
            }
            else {
                paintercount++;
                if(paintercount > k || arr[i] > mid)return false;
                boardsum = arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // if(k>n){
        //     return -1;
        // }
        long long int start = 0;
        long long int end = 0;
        for(int i=0;i<n;i++){
            end += arr[i];
        }
        long long int ans = -1;
        while(start <= end){
            long long int mid = start +(end-start)/2;
            if(isPossibleSoln(arr,n,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        return ans;
        // return minimum time
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends