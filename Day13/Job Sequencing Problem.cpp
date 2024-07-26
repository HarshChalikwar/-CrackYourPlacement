//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
class dsu
{
    public:
    vector<int> par;
    dsu(int n)
    {
        par.resize(n);
        for(int i = 0;i<n;i++) par[i] = i;
    }
    int find_par(int u)
    {
        if(par[u] == u) return u;
        return par[u] = find_par(par[u]);
    }
    void union_size(int u,int v)
    {
        int u_par = find_par(u);
        int v_par = find_par(v);
        if(u_par == v_par ) return ;
        else
        {
            par[v_par]  = u_par;
        }
    }
};
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool swap(pair<int,int> a,pair<int,int> b)
    {
        if(a.first != b.second)
        {
            if(a.first > b.first) return true;
            else return false;
        }
        else
        {
            if(a.second <= b.second) return false;
            return true;
        }
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> s1;
        int max1 = 0;
        for(int i = 0;i<n;i++)
        {
            s1.push_back({arr[i].profit,arr[i].dead});
            max1 = max(max1,arr[i].dead);
        }
        sort(s1.begin(),s1.end(),swap);
        int profit = 0;
        int cnt = 0;
        vector<int> v(max1+1,-1);
        vector<int> v1(2,0);
        dsu ds(max1+1);
        for(auto i: s1)
        {
            int u_par = ds.find_par(i.second);
            if(u_par == 0) continue;
            else 
            {
                ds.union_size(u_par-1,u_par);
                v1[1] += i.first;
                v1[0]++;    
            }
        }
        return v1;
    } 
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends