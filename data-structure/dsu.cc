/**
 * @brief 并查集 (Disjoint Set Union / Union-Find)
 */
struct dsu {
    vector<int> fa;
    dsu(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) fa[x] = y;
    }
};

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> sz;
    int components;
public:
    explicit DSU(int n) : parent(n), sz(n, 1), components(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        return parent[u] == u ? u: parent[u] = find(parent[u]);
    }
    bool unite(int u, int v) {
        int root_u = find(u), root_v = find(v);
        if (root_u == root_v) return false;
        if (sz[root_u] < sz[root_v]) {
            std::swap(root_u, root_v);
        }
        parent[root_v] = root_u;
        sz[root_u] += sz[root_v];
        components--;
        return true;
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
    int size(int u) {
        return sz[find(u)];
    }
    int count() const {
        return components;
    }
    void reset(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
        components = n;
    }
};