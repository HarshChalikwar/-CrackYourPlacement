#include <bits/stdc++.h>

using namespace std;

bool isPossible(int mid, int c, vector<int>& v) {
    c--; 
    int prev = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] - v[prev] >= mid) {
            prev = i;
            c--;
        }
        if (c == 0) return true; 
    }
    return c == 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int l = 0;
        int h = v[n-1] - v[0];  
        int result = 0;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (isPossible(mid, c, v)) {
                result = mid;  
                l = mid + 1;   
            } else {
                h = mid - 1;  
            }
        }
        cout << result << "\n";
    }
    return 0;
}
