class Solution {
public:
    int mod = 1e9+7;
    int increase(int n, int m) {
        vector<long long> prev(m+1, 1), curr(m+1, 0);
        for (int pos = 2; pos <= n; pos++) {
            int dir = (pos % 2 == 0 ? 1 : -1);
            vector<long long> pref(m+1, 0);
            for (int i = 1; i <= m; i++) 
                pref[i] = (pref[i-1] + prev[i]) % mod;
            if (dir == 1) { 
                for (int v = 1; v <= m; v++) 
                    curr[v] = pref[v-1];
            } else { 
                for (int v = 1; v <= m; v++) 
                    curr[v] = (pref[m] - pref[v] + mod) % mod;
            }
            prev = curr;
            fill(curr.begin(), curr.end(), 0);
        }
        long long total = 0;
        for (int v = 1; v <= m; v++) total = (total + prev[v]) % mod;
        return (int)total;
    }
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int ans = increase(n, m);
        return (2 * ans) % mod;
    }
};