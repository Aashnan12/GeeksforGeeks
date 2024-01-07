//{ Driver Code Starts
//Initial Template for C++

// C++ implementation to rearrange the array 
// elements after modification 
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        void modifyAndRearrangeArr(int arr[], int n) 
    { 
    	// Complete the function
    	for(int i=1;i<n;i++)
    	{
    	    if(arr[i-1] == arr[i])
    	    {
    	        arr[i-1] = arr[i] * 2;
    	        arr[i] = 0;
    	    }
    	}
    	int i=0;
    	
    	for(int index = 0;index<n;index++)
    	{
    	    if(arr[index] != 0)
    	    {
    	        swap(arr[index],arr[i]);
    	        i++;
    	    }
    	}
    }
}; 


//{ Driver Code Starts.
// Driver program to test above 
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        ob.modifyAndRearrangeArr(arr, n);
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << endl;
        
    }

	return 0; 
} 

// } Driver Code Ends