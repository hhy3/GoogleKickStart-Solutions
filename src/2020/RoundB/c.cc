#include <bits/stdc++.h>
using namespace std;

const int64_t M = 1e9;
string s;
int n;

pair<int64_t, int64_t> calc(int i, int j) {

  if (i > j) return {0, 0};
  if (s[i] >= '2' && s[i] <= '9') {
    int k = i+2, c = 1, cnt = s[i]-'0';
    while (c > 0) {
      if (s[k] == '(') c++;
      if (s[k] == ')') c--;
      if (c==0) break;
      k++;
    }
    auto [dx, dy] = calc(i+2, k-1);
    auto [ddx, ddy] = calc(k+1, j);
    return {(cnt * dx + ddx) % M, (cnt * dy + ddy) % M};
  } else {
    auto [dx, dy] = calc(i+1, j);
    if (s[i] == 'S') return {(dx + 1) % M, dy};
    else if (s[i] == 'N') return {(dx + M - 1) % M, dy};
    else if (s[i] == 'E') return {dx, (dy + 1) % M};
    else return {dx, (dy + M - 1) % M};
  }
}

void solve() {
  cin >> s;
  n = s.size();
  auto [x, y] = calc(0, n-1);
  cout << y + 1 << " " << x + 1 << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}