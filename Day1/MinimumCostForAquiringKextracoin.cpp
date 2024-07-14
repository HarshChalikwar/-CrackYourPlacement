#include <bits/stdc++.h>
using namespace std;
int getMinCost(vector<int> coins, int k)
{
    sort(coins.begin(), coins.end());
    int coins_req = ceil(((double)coins.size()) / (k + 1));
    int ans = 0;
    for (int i = 0; i <= coins_req - 1; i++)
    {
        ans += coins[i];
    }
    return ans;
}
