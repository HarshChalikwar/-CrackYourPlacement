//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void rec(vector<int>& arr,set<vector<int>>& ans,unordered_map<int,int>& m,vector<int>& v)
    {
        if(v.size() == arr.size())
        { 
            ans.insert(v);
            return;
        }
        for(int i = 0;i<arr.size();i++)
        {
            if(!m[i])
            {
                m[i] = 1;
                    v.push_back(arr[i]);
                    rec(arr,ans,m,v);
                    v.pop_back();
                m[i] = 0;
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>> ans;
        vector<int> v;
        unordered_map<int,int> m;
        rec(arr,ans,m,v);
        vector<vector<int>> ans1;
        for(auto vec: ans)
        {
            ans1.push_back(vec);
        }
        return ans1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends