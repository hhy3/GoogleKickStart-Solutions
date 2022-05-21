#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, X; cin >> n >> X;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  int ans = 0;
  for (auto x : a) if (X >= x) X -= x, ans++;
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