#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  for (int i = 0, cur = 0; i < n; ++i) {
    if (i == 0 || s[i - 1] >= s[i]) cur = 1;
    else cur++;
    cout << cur << ' ';
  }
  cout << endl;
}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
