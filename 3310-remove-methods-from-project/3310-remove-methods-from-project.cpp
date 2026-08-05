class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        for (const auto& edge : invocations) {
            if (!suspicious[edge[0]] && suspicious[edge[1]]) {
                vector<int> res(n);
                iota(res.begin(), res.end(), 0);
                return res;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};