#include <bits/stdc++.h>
using namespace std;

int f(const vector<int> &a, int n) {
  vector<int> b(n), dp(n, 1);
  for (int i = 1; i < n; ++i) {
    b[i] = a[i] - a[i - 1];
    if (i > 1 && b[i] == b[i - 1]) dp[i] += dp[i - 1];
  }
  int ans = 1;
  for (int i = 2; i < n; ++i) {
    ans = max(ans, dp[i]);
    ans = max(ans, dp[i - 1] + 1);
    int j = i - dp[i];
    if (j >= 2) {
      if (b[j] + b[j - 1] == 2 * b[i]) {
        ans = max(ans, dp[i] + 2);
        if (j >= 3 && b[j - 2] == b[i]) {
          ans = max(ans, dp[i] + dp[j - 2] + 2);
        }
      }
    }
  }
  return ans + 1;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  cout << max(f(a, n), f(vector<int>(a.rbegin(), a.rend()), n)) << endl;
}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
