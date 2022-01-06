#include <bits/stdc++.h>
using namespace std;

void solve() {
  int64_t G; cin >> G;
  int ans = 1;
  for (int64_t i = 2; i <= G / i; ++i) {
    if (G % i == 0) {
      int cnt = 1;
      G /= i;
      while (G % i == 0)
        cnt++, G /= i;
      if (i > 2) ans *= (cnt + 1);
    }
  }
  if (G > 1) ans *= 2;
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
