#include <bits/stdc++.h>
using namespace std;

const int N = 510;
array<int, 3> edges[N * N];
int a[N][N], b[N][N], p[N * 2], tot = 0;

int find(int u) {
  return u == p[u]? u : p[u] = find(p[u]);
}

void solve() {
  tot = 0;
  int n; cin >> n;
  iota(p, p + 2 * n + 1, 0);
  int x, ans = 0;
  for (auto arr: {a, b}) { 
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
      cin >> arr[i][j];
      if (arr == b && a[i][j] == -1) 
        edges[tot++] = {b[i][j], i, j + n}, ans += b[i][j];
    }
  }
  for (int i = 0; i < 2 * n; ++i) cin >> x;

  sort(edges, edges + tot);
  reverse(edges, edges + tot);
  for (int i = 0; i < tot; ++i) {
    auto [w, u, v] = edges[i];
    if (int pu = find(u), pv = find(v); pu != pv) {
      p[pu] = pv, ans -= w;
    }
  }
  cout << ans << endl;

}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
