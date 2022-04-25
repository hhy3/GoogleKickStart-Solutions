#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

void solve() {
  int r, a, b; cin >> r >> a >> b;
  double ans = 0.0;
  for (int i = 0; r > 0; i++, r /= 2) {
    ans += PI * r * r;
    if (i % 2 == 0) r *= a;
    else r /= b;
  }
  cout << fixed << setprecision(10) << ans << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}