#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  cout << (n - 1) / 5 + 1 << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}