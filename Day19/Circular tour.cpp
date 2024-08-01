//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of p is 
struct p
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int pet = 0;
        int start = 0;
       for(int i = 0;i<n;i++)
       {
            pet += p[i].petrol;
            if(p[i].distance <= pet)
            {
                pet -= p[i].distance;
            }
            else
            {
                if(i<n-1)
                {
                start = i+1;
                pet = 0;
                }
                else return -1;
            }
       }
       for(int i = 0;i<start;i++)
       {
           pet += p[i].petrol;
            if(p[i].distance <= pet)
            {
                pet -= p[i].distance;
            }
            else
            {
                return -1;
            }
       }
       return start;
       
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends