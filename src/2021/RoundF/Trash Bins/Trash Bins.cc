#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> a;
  for (int i = 0; i < n; ++i) if (s[i] == '1') a.push_back(i);
  int m = a.size();
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    int loc = lower_bound(a.begin(), a.end(), i) - a.begin();
    int cur = INT_MAX;
    if (loc < m) cur = min(cur, a[loc] - i);
    if (loc > 0) cur = min(cur, i - a[loc - 1]);
    ans += cur;
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