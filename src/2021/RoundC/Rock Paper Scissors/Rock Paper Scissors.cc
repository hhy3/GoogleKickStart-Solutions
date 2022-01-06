#include <bits/stdc++.h>
using namespace std;

int X;

const int MAXN = 60;
// RSP
double dp[MAXN + 10][MAXN + 10][MAXN + 10];
int pre[MAXN + 10][MAXN + 10][MAXN + 10];
void solve() {
  memset(dp, 0, sizeof dp);
  memset(pre, 0, sizeof pre);
  double W, E; cin >> W >> E;
  dp[1][0][0] = dp[0][1][0] = dp[0][0][1] = W / 3 + E / 3;
  pre[1][0][0] = 0;
  pre[0][1][0] = 1;
  pre[0][0][1] = 2;
  double mx = 0;
  array<int, 3> loc;
  for (int tot = 2; tot <= MAXN; ++tot) {
    for (int i = 0; i <= tot; ++i) for (int j = 0; j <= tot - i; ++j) {
      int k = tot - i - j;
      if (i) {
        double x = dp[i - 1][j][k] + W * k / (tot - 1) + E * j / (tot - 1);
        if (x > dp[i][j][k]) {
          dp[i][j][k] = x;
          pre[i][j][k] = 0;
        }
      }
      if (j) {
        double x = dp[i][j - 1][k] + W * i / (tot - 1) + E * k / (tot - 1);
        if (x > dp[i][j][k]) {
          dp[i][j][k] = x;
          pre[i][j][k] = 1;
        }
      }
      if (k) {
        double x = dp[i][j][k - 1] + W * j / (tot - 1) + E * i / (tot - 1);
        if (x > dp[i][j][k]) {
          dp[i][j][k] = x;
          pre[i][j][k] = 2;
        }
      }
      if (tot == MAXN && dp[i][j][k] > mx) {
        mx = dp[i][j][k];
        loc = {i, j, k};
      }
    }

  }
  string ans;
  auto [i, j, k] = loc;
  while (i || j || k) {
    int nxt = pre[i][j][k];
    if (nxt == 0) --i, ans += 'R';
    else if (nxt == 1) --j, ans += 'S';
    else --k, ans += 'P';
  }
  cout << string(ans.rbegin(), ans.rend()) << endl;
  
}

int main() {
  int T; cin >> T >> X;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";  
    solve();
  }
  return 0;
}
