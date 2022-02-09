#include <bits/stdc++.h>
using namespace std;

constexpr double phi = 0.5772156649;

void solve() {
  int64_t n; cin >> n;
  double ans = 0.0;
  if (n <= int(1e7)) {
    for (int i = 1; i <= n; ++i) {
      ans += 1.0 / i;
    }
  } else {
    ans = log(n + 1) + phi;
  }
  
  cout << fixed << setprecision(8) << ans << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}