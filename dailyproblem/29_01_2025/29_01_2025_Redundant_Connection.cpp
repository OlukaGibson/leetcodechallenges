class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);  // DSU parent array
        vector<int> rank(n + 1, 0); // Rank optimization
        
        // Initialize each node as its own parent (self-loop)
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Find function with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);  // Path compression
            }
            return parent[x];
        };

        // Union function with rank optimization
        auto unite = [&](int x, int y) {
            int rootX = find(x), rootY = find(y);
            if (rootX == rootY) return false; // Cycle detected
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        };

        // Process edges
        for (auto& edge : edges) {
            if (!unite(edge[0], edge[1])) {
                return edge;  // Found redundant edge
            }
        }

        return {}; // Should never reach here as per problem constraints
    }
};
