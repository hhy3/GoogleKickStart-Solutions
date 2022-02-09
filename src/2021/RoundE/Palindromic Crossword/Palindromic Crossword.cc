#include <bits/stdc++.h>
using namespace std;

void solve() {
  int m, n; cin >> m >> n;
  vector<string> a(m);
  for (int i = 0; i < m; ++i) cin >> a[i];
  map<pair<int, int>, pair<int, int>> mp1, mp2;
  for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (a[i][j] != '#') {
    if (j == 0 || a[i][j-1] == '#') {
      int k = j + 1; 
      while (k < n && a[i][k] != '#') k++;
      for (int t = 0; j + t < k - t - 1; ++t) 
        mp1[{i, j + t}] = {i, k - t - 1}, mp1[{i, k - t - 1}] = {i, j + t};
    }
    if (i == 0 || a[i-1][j] == '#') {
      int k = i + 1;
      while (k < m && a[k][j] != '#') k++;
      for (int t =  0; i + t < k - t - 1; ++t) 
        mp2[{i + t, j}] = {k - t - 1, j}, mp2[{k - t - 1, j}] = {i + t, j};
    }
  }
  vector<vector<bool>> vis(m, vector<bool>(n));
  queue<pair<int, int>> q;
  for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
    if (a[i][j] <= 'Z' && a[i][j] >= 'A') {
      vis[i][j] = true;
      q.push({i, j});
    }
  }
  int ans = 0;
  while (q.size()) {
    auto [i, j] = q.front(); q.pop();
    if (mp1.count({i, j})) {
      auto [x, y] = mp1[{i, j}];
      if (!vis[x][y]) {
        vis[x][y] = true;
        a[x][y] = a[i][j];
        q.push({x, y});
        ans++;
      }
      
    }
    if (mp2.count({i, j})) {
      auto [x, y] = mp2[{i, j}];
      if (!vis[x][y]) {
        vis[x][y] = true;
        a[x][y] = a[i][j];
        q.push({x, y});
        ans++;
      }
    }
  }
  cout << ans << endl;
  for (auto &s : a) cout << s << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}