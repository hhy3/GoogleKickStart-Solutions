#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int a[N][N], U[N][N], L[N][N], D[N][N], R[N][N];
void solve() {
  for (auto X : {U, L, D, R}) {
    memset(X, 0, sizeof U);
  }
  int m, n; cin >> m >> n;
  for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
    cin >> a[i][j];
    if (a[i][j]) U[i][j] = 1 + U[i - 1][j], L[i][j] = 1 + L[i][j - 1];
  }
  for (int i = m; i >= 1; --i) for (int j = n; j >= 1; --j) {
    if (a[i][j]) D[i][j] = 1 + D[i + 1][j], R[i][j] = 1 + R[i][j + 1];
  }
  int ans = 0;
  
  for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
    for (auto H : {U, D}) for (auto V : {L, R}) {
      ans += max(0, min((H[i][j] - 2) / 2, V[i][j] - 1));
      ans += max(0, min((V[i][j] - 2) / 2, H[i][j] - 1));
    }
  }
  cout << ans << endl;

}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
