#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k, p; cin >> n >> k >> p;
  vector<int> f(p+1);
  for (int i = 1; i <= n; ++i) {
    vector<int> a(k+1);
    for (int j = 1; j <= k; ++j) cin >> a[j], a[j] += a[j-1];
    vector<int> g(f);
    for (int j = min(p, i*k); j >= 0; --j) {
      for (int t = 0; t <= min(j, k); ++t) {
        g[j] = max(g[j], g[j-t] + a[t]);
      }
    }
    f = move(g);
  }
  cout << f[p] << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}