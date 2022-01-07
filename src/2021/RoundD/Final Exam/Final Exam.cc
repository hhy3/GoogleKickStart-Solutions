#include <bits/stdc++.h>
using namespace std;

class c_cmp {
public:
  bool operator()(const array<int64_t, 2> &x, const array<int64_t, 2> &y) const {
    return x[1] < y[1] || x[1] == y[1] && x[0] < y[0];
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<array<int64_t, 2>> a(n);
  for (auto &[x, y] : a) cin >> x >> y;
  set<array<int64_t, 2>, c_cmp> s;
  for (auto [x, y] : a) s.insert({x, y});
  s.insert({int64_t(2e18), int64_t(2e18)});
  s.insert({int64_t(-2e18), int64_t(-2e18)});
  
  while (m--) {
    int64_t x; cin >> x;
    auto it = s.lower_bound({int64_t(2e18), x});
    auto [lo, hi] = *it;
    if (lo < x && x < hi) {
      cout << x << ' ';
      s.erase({lo, hi});
      s.insert({lo, x - 1});
      s.insert({x + 1, hi});
    } else {
      auto [l, r] = *(--it);
      if (x - r <= lo - x) {
        cout << r << ' ';
        s.erase({l, r});
        if (l <= r - 1) s.insert({l, r - 1});
      } else {
        cout << lo << ' ';
        s.erase({lo, hi});
        if (lo + 1 <= hi) s.insert({lo + 1, hi});
      }
    }
  }

  cout << endl;
}

int main() {
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";  
    solve();
  }
  return 0;
}
