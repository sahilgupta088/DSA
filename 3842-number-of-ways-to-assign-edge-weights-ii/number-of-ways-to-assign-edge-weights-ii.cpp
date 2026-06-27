#include <bits/stdc++.h>
using namespace std;

class BinaryLifting {
private:
    int n;
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;

    void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
        up[u][0] = p;
        depth[u] = d;

        for (auto& it : adj[u]) {
            if (it != p) {
                dfs(it, u, d + 1, adj);
            }
        }
    }

public:
    BinaryLifting(int nodesCount, int root,
                  const vector<vector<int>>& adj) {
        n = nodesCount;
        LOG = ceil(log2(n)) + 1;

        up.assign(n, vector<int>(LOG, 0));
        depth.assign(n, 0);

        dfs(root, root, 0, adj);

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if ((diff >> j) & 1) {
                u = up[u][j];
            }
        }

        if (u == v) {
            return u;
        }

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    int getDistance(int u, int v) {
        int lca = getLCA(u, v);
        return depth[u] + depth[v] - 2 * depth[lca];
    }
};

class Solution {
private:
    static constexpr int MOD = 1e9 + 7;
    vector<int> ans;

public:
    int countWays(int depth) {
        if(depth<0)return 0;
        long long base = 2;
        long long ans = 1;

        while (depth > 0) {
            if (depth & 1) {
                ans = (ans * base) % MOD;
            }

            base = (base * base) % MOD;
            depth >>= 1;
        }

        return (int)ans;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int nodeCount = edges.size() + 1;

        vector<vector<int>> adj(nodeCount + 1);

        for (auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        BinaryLifting bt(nodeCount + 1, 1, adj);

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            int depth = bt.getDistance(u, v);
            int ways = countWays(depth-1);

            ans.push_back(ways);
        }

        return ans;
    }
};