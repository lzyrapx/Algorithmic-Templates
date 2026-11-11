#include <bits/stdc++.h>

using namespace std;

// tourist's sparse table
template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> a(n + 1);
    SparseTable<long long> smin(
        a, [&](long long i, long long j) { return min(i, j); });
    SparseTable<long long> smax(
        a, [&](long long i, lon long j) { return max(i, j); });
    int rvmin = smin.get(i + 1, n - 1);
    int rvmax = smax.get(i + 1, n - 1);
}
