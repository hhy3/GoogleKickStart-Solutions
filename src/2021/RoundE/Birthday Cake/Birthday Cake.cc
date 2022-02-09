#include <bits/stdc++.h>
using namespace std;

void solve() {
  int m, n, k; cin >> m >> n >> k;
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  int ans = (x2 - x1 + 1 + k - 1) / k * (y2 - y1 + 2) + (y2 - y1 + 1 + k - 1) / k * (x2 - x1 + 2);

  bool ok = false;
  if (x1 == 1) ans -= (y2 - y1 + 1 + k - 1) / k, ok = true;
  if (y1 == 1) ans -= (x2 - x1 + 1 + k - 1) / k, ok = true;
  if (x2 == m) ans -= (y2 - y1 + 1 + k - 1) / k, ok = true;
  if (y2 == n) ans -= (x2 - x1 + 1 + k - 1) / k, ok = true;
  if (!ok) {
    int min_add = INT_MAX;
    min_add = min(min_add, min((x2 + k - 1) / k, (m - x1 + 1 + k - 1) / k) - (x2 - x1 + 1 + k - 1) / k);
    min_add = min(min_add, min((y2 + k - 1) / k, (n - y1 + 1 + k - 1) / k) - (y2 - y1 + 1 + k - 1) / k);
    ans += min_add;
  }
  cout << ans << endl;
  
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}