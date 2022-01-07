#include <bits/stdc++.h>
using namespace std;

int a[3][3];
void solve() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i == 1 && j == 1) continue;
      cin >> a[i][j];
    }
  }
  unordered_map<int, int> cnt;
  int ans = 0;
  if (int x = a[1][0] + a[1][2]; x % 2 == 0) cnt[x / 2]++;
  if (int x = a[0][1] + a[2][1]; x % 2 == 0) cnt[x / 2]++;
  if (int x = a[0][0] + a[2][2]; x % 2 == 0) cnt[x / 2]++;
  if (int x = a[0][2] + a[2][0]; x % 2 == 0) cnt[x / 2]++;
  for (auto [k, v] : cnt) ans = max(ans, v);
  if (a[0][0] + a[0][2] == 2 * a[0][1]) ans++;
  if (a[2][0] + a[2][2] == 2 * a[2][1]) ans++;
  if (a[0][0] + a[2][0] == 2 * a[1][0]) ans++;
  if (a[0][2] + a[2][2] == 2 * a[1][2]) ans++;
  cout << ans << endl;
}

int main() {
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";  
    solve();
  }
  return 0;
}
