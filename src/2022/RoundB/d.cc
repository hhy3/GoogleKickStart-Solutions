#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const char dir[] = "SENW";
bool vis[210][210];

void solve() {
  memset(vis, 0, sizeof vis);
  int m, n; cin >> m >> n;
  vector<string> a(m);
  int tot = 0;
  for (int i = 0; i < m; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
    if (a[i][j] == '*') tot++;
  }
  string ans;
  int cnt = 0;
  function<void(int, int, int)> dfs = [&] (int i, int j, int k) {
    vis[i][j] = true;
    cnt++;
    for (int of = -1; of <= 1; ++of) {
      int kk = (k + of + 4) % 4;
      int x = i + dx[kk], y = j + dy[kk];
      if (x >= 0 && x < m && y >= 0 && y < n && a[x][y] == '*' && !vis[x][y]) {
        ans += dir[kk];
        dfs(x, y, kk);
      } else {
        ans += dir[(kk+1)%4];
      }
    }
    ans += dir[(k+2)%4];
  };
  dfs(0, 0, 0);
  ans.back() = 'W';
  cout << (tot == cnt? ans : "IMPOSSIBLE") << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}