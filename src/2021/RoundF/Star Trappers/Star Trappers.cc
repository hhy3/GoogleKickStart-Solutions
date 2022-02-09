#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) cin >> x >> y;
  int x0, y0; cin >> x0 >> y0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}