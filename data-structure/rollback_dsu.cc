// copy from tourist: https://codeforces.com/contest/2222/submission/372507408

class dsu {
 public:
  vector<int> p;
  int n;
 
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
 
class dsu_rollback {
 public:
  vector<int> p;
  vector<int> sz;
  vector<int> idx;
  int n;
  vector<tuple<int, int, int>> ops;
 
  dsu_rollback(int _n) : n(_n) {
    p.resize(n);
    sz.resize(n);
    iota(p.begin(), p.end(), 0);
    fill(sz.begin(), sz.end(), 1);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : get(p[x]));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      if (sz[x] > sz[y]) {
        swap(x, y);
      }
      ops.emplace_back(0, x, p[x]);
      ops.emplace_back(1, y, sz[y]);
      ops.emplace_back(2, y, idx[y]);
      p[x] = y;
      sz[y] += sz[x];
      idx[y] = (idx[y] != -1 ? idx[y] : idx[x]);
      return true;
    }
    return false;
  }
 
  void rollback(int T) {
    assert(int(ops.size()) >= T);
    while (int(ops.size()) > T) {
      auto [a, b, c] = ops.back();
      if (a == 0) p[b] = c;
      if (a == 1) sz[b] = c;
      if (a == 2) idx[b] = c;
      ops.pop_back();
    }
  }
};