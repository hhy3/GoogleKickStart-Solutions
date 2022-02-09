#include <bits/stdc++.h>
using namespace std;

int64_t dp[1 << 16][16];
int64_t S[1 << 16];
void solve() {
  memset(dp, 0, sizeof dp);
  memset(S, 0, sizeof S);
  int n, m, K; cin >> n >> m >> K;
  vector<vector<int>> G(n);
  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }


  for (int i = 0; i < n; ++i) dp[1 << i][i] = 1, S[1 << i] = a[i][2];
  for (int s = 1; s < 1 << n; ++s) {
    if (__builtin_popcount(s) == 1) {
      continue;
    }
    // cout << s << endl;
    int64_t sum = S[s - (s & -s)] + S[s & -s];
    // for (int i = 0; i < n; ++i) if (s >> i & 1) sum += a[i][2];
    S[s] = sum;
    for (int cur = 0; cur < n; ++cur) if (s >> cur & 1) {
      if (sum - a[cur][2] < a[cur][0] || sum - a[cur][2] > a[cur][1]) continue;
      bool ok = false;
      for (auto v : G[cur]) {
        if (s >> v & 1) {
          ok = true;
          break;
        }
      } 
      if (ok) {
        for (int i = 0; i < n; ++i) if (s >> i & 1) if (i != cur) {
          dp[s][cur] += dp[s ^ (1 << cur)][i];
        }
      }
    }
  }
  int64_t ans = 0;
  for (int s = 1; s < 1 << n; ++s) {

    if (S[s] == K) for (int i = 0; i < n; ++i) if (s >> i & 1) ans += dp[s][i];

  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}