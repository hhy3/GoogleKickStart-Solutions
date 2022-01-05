#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, K; cin >> n >> K;
  string s; cin >> s;
  int k = 0;
  for (int i = 0, j = n - 1; i < j; ++i, --j) {
    k += s[i] != s[j];
  }
  cout << abs(k - K) << endl;
}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
