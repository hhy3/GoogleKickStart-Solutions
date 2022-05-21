#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long double p[N], f[N];

void init() {
  p[0] = f[0] = 0.0;
  for (int i = 1; i < N; ++i) {
    p[i] = p[i-1] + log((long double)2.0);
    f[i] = f[i-1] + log((long double)i);
  } 
  
}

long double comb(int n, int m) {
  return f[n] - f[m] - f[n-m];
}

long double P(int dx, int dy) {
  return exp(comb(dx + dy, dx) - p[dx + dy]);
}

void solve() {
  long double ans = 0.0;
  int m, n; cin >> m >> n;
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  
  if (x2 < m) {
    for (int j = 1; j < y1; ++j) {
      ans += 0.5 * P(x2-1, j-1);
    }
  }
  if (y2 < n) {
    for (int i = 1; i < x1; ++i) {
      ans += 0.5 * P(i-1, y2-1);
    }
  }
  cout << fixed << setprecision(7) << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  init();
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}