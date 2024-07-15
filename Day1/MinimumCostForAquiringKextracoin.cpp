<<<<<<< HEAD
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
=======
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
>>>>>>> 581a1ccad92424387d9a31defcfe6c6fe94ef5b6
