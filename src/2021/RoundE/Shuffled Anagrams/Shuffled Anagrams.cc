#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  int cnt[26] {};
  for (auto c : s) {
    if (++cnt[c-'a'] > n/2) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }
  vector<pair<char, int>> a(n);
  for (int i = 0; i < n; ++i) a[i] = {s[i], i};
  sort(a.begin(), a.end());
  string ans(n, '0');
  string b(n, '0');
  for (int i = 0; i < n; ++i) b[(i+n/2)%n] = a[i].first;
  for (int i = 0; i < n; ++i) ans[a[i].second] = b[i];
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
