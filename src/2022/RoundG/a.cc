#include <bits/stdc++.h>
using namespace std;

void solve() {
  int m, n, p; cin >> m >> n >> p, p--;
  vector<vector<int64_t>> a(m, vector<int64_t>(n));
  vector<int64_t> mx(n);
  int64_t ans = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) cin >> a[i][j], mx[j] = max(mx[j], a[i][j]);
  }
  for (int j = 0; j < n; ++j) {
    if (a[p][j] < mx[j]) ans += mx[j] - a[p][j];
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}