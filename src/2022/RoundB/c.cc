#include <bits/stdc++.h>
using namespace std;

constexpr int N = 410;
int64_t a[N];
int64_t f[N][N][N];

void solve() {
  int n, D; cin >> n >> D;

  auto dist = [&] (int64_t x, int64_t y) {
    if (x > y) swap(x, y);
    return min(y - x, x + D - y);
  };

  for (int i = 1; i <= n; ++i) cin >> a[i];
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      f[i][i][j] = dist(a[i], a[j]);
    } 
  }

  for (int len = 2; len <= n; ++len) {
    for (int i = 1; i + len - 1 <= n; ++i) {
      int j = i + len - 1;
      for (int k = 0; k <= n; ++k) {
        if (a[i] == a[j]) {
          f[i][j][k] = f[i+1][j-1][i] + dist(a[i], a[k]);
        } else {
          f[i][j][k] = min(
            f[i+1][j][i] + dist(a[i], a[k]),
            f[i][j-1][j] + dist(a[j], a[k])
          );
        }
      }
    }
  }

  cout << f[1][n][0] << endl;

}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}