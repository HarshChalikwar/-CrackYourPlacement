//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isValid(int i,int j,int n)
    {
        if(i<n and j<n and i>= 0 and j>=0 ) return true;
        return false;
    }
    void dfs(vector<vector<int>>& m,vector<string>& k,string& s,int i,int j)
    {
        if(i == m.size()-1 and j == m.size()-1)
        {
            k.push_back(s);
            return;
        }
        m[i][j] = 2;
        int x[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        string y = "RLDU";
        for(int t = 0;t<4;t++)
        {
            int x1 = x[t][0] + i;
            int x2 = x[t][1] + j;
            if(isValid(x1,x2,m.size()))
            {
                if(m[x1][x2] == 1)
                {
                    s.push_back(y[t]);
                    dfs(m,k,s,x1,x2);
                    s.pop_back();
                }
            }
        }
        m[i][j] = 1;
        
    }
    vector<string> findPath(vector<vector<int>> &m) {
        // Your code goes here
        int n = m.size();
        vector<string> k;
        if(m[n-1][n-1] == 0 or m[0][0] == 0) return k;
        string s = "";
        dfs(m,k,s,0,0);
        return k;
    }
};

    



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends