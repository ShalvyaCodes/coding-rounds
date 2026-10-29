#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, sz;
    vector<int> val; // Bitmask value for each node
    vector<int> tree; // Segment tree array
    int cur_pos;

    // First DFS to compute subtree sizes, parent, depth, and heavy child
    int dfs1(int u, int p, int d) {
        parent[u] = p;
        depth[u] = d;
        sz[u] = 1;
        int max_sub = 0;
        heavy[u] = -1;
        for (int v : adj[u]) {
            if (v != p) {
                int sub = dfs1(v, u, d + 1);
                sz[u] += sub;
                if (sub > max_sub) {
                    max_sub = sub;
                    heavy[u] = v;
                }
            }
        }
        return sz[u];
    }

    // Second DFS to set chain heads and positions for HLD
    void dfs2(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) {
            dfs2(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs2(v, v);
            }
        }
    }

    // Segment tree update for point position
    void update_tree(int node, int start, int end, int idx, int val_diff) {
        if (start == end) {
            tree[node] ^= val_diff;
            return;
        }
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
            update_tree(2 * node, start, mid, idx, val_diff);
        else
            update_tree(2 * node + 1, mid + 1, end, idx, val_diff);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    // Segment tree range query for XOR sum
    int query_tree(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query_tree(2 * node, start, mid, l, r) ^ query_tree(2 * node + 1, mid + 1, end, l, r);
    }

    // Query path XOR sum between u and v
    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                res ^= query_tree(1, 0, n - 1, pos[head[u]], pos[u]);
                u = parent[head[u]];
            } else {
                res ^= query_tree(1, 0, n - 1, pos[head[v]], pos[v]);
                v = parent[head[v]];
            }
        }
        if (depth[u] > depth[v]) {
            res ^= query_tree(1, 0, n - 1, pos[v], pos[u]);
        } else {
            res ^= query_tree(1, 0, n - 1, pos[u], pos[v]);
        }
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.resize(n);
        depth.resize(n);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        sz.resize(n);
        val.resize(n);
        tree.assign(4 * n, 0);
        cur_pos = 0;

        dfs1(0, -1, 0);
        dfs2(0, 0);

        for (int i = 0; i < n; ++i) {
            val[i] = (1 << (s[i] - 'a'));
            update_tree(1, 0, n - 1, pos[i], val[i]);
        }

        vector<bool> answer;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int new_val = (1 << (c - 'a'));
                int diff = val[u] ^ new_val;
                val[u] = new_val;
                update_tree(1, 0, n - 1, pos[u], diff);
            } else if (type == "query") {
                int u, v;
                ss >> u >> v;
                int path_xor = query_path(u, v);
                // A path can form a palindrome if at most one bit is set (path_xor is 0 or a power of 2)
                bool is_palindrome = (path_xor == 0) || ((path_xor & (path_xor - 1)) == 0);
                answer.push_back(is_palindrome);
            }
        }

        return answer;
    }
};