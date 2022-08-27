#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, P, M, x0, y0; cin >> n >> P >> M >> x0 >> y0;

  auto gen_func = [&] (string s, int x) -> function<int64_t(int64_t)> {
    if (s == "+") {
      return [x] (int64_t c) {
        return c + x;
      };
    } else if (s == "-") {
      return [x] (int64_t c) {
        return c - x;
      };
    } else if (s == "*") {
      return [x] (int64_t c) {
        return c * x;
      };
    } else {
      return [x] (int64_t c) {
        int64_t ret = c / x;
        if (c < 0 && c % x) ret--;
        return ret;
      };
    }
  };
  vector<function<int64_t(int64_t)>> funcs(4);
  for (int i = 0; i < 4; ++i) {
    string op; cin >> op;
    int x; cin >> x;
    funcs[i] = gen_func(op, x);
  }
  const char dx[] = {-1, 0, 0, 1};
  const char dy[] = {0, 1, -1, 0};

  vector<array<int, 3>> a(P);
  for (auto& [x, y, c] : a) cin >> x >> y >> c;

  int64_t f[21][11][11];
  memset(f, -0x3f, sizeof f);
  f[0][x0][y0] = 0;  
  int64_t ans = 0;
  for (int t = 0; t < M; ++t) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (f[t][i][j] < -(1LL<<50)) {
          continue;
        }
        for (int k = 0; k < 4; ++k) {
          int x = i + dx[k], y = j + dy[k];
          if (x >= 1 && x <= n && y >= 1 && y <= n) {
            f[t+1][x][y] = max(f[t+1][x][y], funcs[k](f[t][i][j]));
            ans = max(ans, f[t+1][x][y]);
          }
        }

      }
    }
  } 
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}