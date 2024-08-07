//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(n < m) return -1;
        int h = 0;int l = 0;
        for(int i = 0;i<n;i++)
        {
            h += arr[i];
            l = max(l,arr[i]);
        }
        while(l<h)
        {
            int mid = l + (h-l)/2;
            int sum = 0;
            int cnt = 1;
            for(int i = 0;i<n;i++)
            {
                sum += arr[i];
                if(sum > mid)
                {
                    cnt++;
                    sum = arr[i];
                }
            }
            if(cnt > m)
            {
                l = mid + 1;
            }
            else if(cnt <= m)
            {
                h = mid;
            }
        }
        return h;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends