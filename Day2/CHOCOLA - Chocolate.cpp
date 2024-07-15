#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t)
	{
		int m,n;
		cin>>m>>n;
		vector<int> v1(m-1),v2(n-1);
		for(int i = 0;i<m-1;i++)
		{
			cin>>v1[i];
		}
		for(int i = 0;i<n-1;i++)
		{
			cin>>v2[i];
		}
		sort(v1.begin(),v1.end(),greater<int>());
		sort(v2.begin(),v2.end(),greater<int>());
		int i = 0;int j = 0;
		int ans = 0;
		while(i<m-1 and j<n-1)
		{
			if(v1[i] >= v2[j])
			{
				ans += v1[i]*(j+1);
				i++;	
			}
			else
			{
				ans += v2[j]*(i+1);
				j++;
			}
		}
		while(i<m-1)
		{
			ans += v1[i]*(j+1);
			i++;	
		}
		while(j<n-1)
		{
			ans += v2[j]*(i+1);
			j++;
		}
		cout<<ans<<"\n";
		t--;
	}
	return 0;
}