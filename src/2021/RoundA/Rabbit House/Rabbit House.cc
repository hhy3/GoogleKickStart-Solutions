#include <bits/stdc++.h>
using namespace std;

const int N = 310;
int a[N][N];
unordered_set<int> buckets[2 * N];

int encode(int x, int y) {
  return x * N + y;
}

pair<int, int> decode(int c) {
  return {c / N, c % N};
}

void solve() {
  int m, n; cin >> m >> n;
  int mx = 0;
  for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
    cin >> a[i][j];
    mx = max(mx, a[i][j]);
  }
  int mi = mx - n - m + 2;
  int64_t ans = 0;
  unordered_map<int, unordered_set<int>> buckets;
  for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
    if (a[i][j] < mi) {
      ans += mi - a[i][j];
      a[i][j] = mi;
    }
    a[i][j] -= mi;
    buckets[a[i][j]].insert(encode(i, j));
  }

  for (int k = mx - mi; k >= 0; --k) {
    for (auto c : buckets[k]) {
      auto [i, j] = decode(c);
      for (auto [dx, dy] : vector<array<int, 2>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
        int x = i + dx, y = j + dy;
        if (x >= 1 && x <= m && y >= 1 && y <= n && a[x][y] < a[i][j] - 1) {
          buckets[a[x][y]].erase(encode(x, y));
          ans += a[i][j] - 1 - a[x][y];
          a[x][y] = a[i][j] - 1;
          buckets[a[x][y]].insert(encode(x, y));
        }
      }
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