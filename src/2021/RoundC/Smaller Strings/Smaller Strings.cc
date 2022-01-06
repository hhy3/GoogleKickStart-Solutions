#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9 + 7;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int64_t ans = 0;
  for (int i = 0; i < (n + 1) / 2; ++i) {
    ans = ans * k + (s[i] - 'a');
    ans %= MOD;
  }
  if (string(s.rbegin() + n - n / 2, s.rend()) < s.substr(n - n / 2)) {
    ans = (ans + 1) % MOD;
  }
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
