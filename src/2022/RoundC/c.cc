#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, L; cin >> n >> L;
  vector<vector<int>> a(n);
  vector<int> b, c;
  int lft = 0;
  for (int i = 0; i < n; ++i) {
    int p, d; cin >> p >> d;
    a[i] = {p, i};
    if (d==0) lft++, b.push_back(p);
    else c.push_back(L - p);
  }
  sort(b.begin(), b.end());
  sort(c.rbegin(), c.rend());
  sort(a.begin(), a.end());
  int m1 = 0, m2 = 0;
  for (int i = 0; i < n; ++i) {
    if (i < lft) a[i].push_back(b[m1++]);
    else a[i].push_back(c[m2++]);
  }

  sort(a.begin(), a.end(), [&] (auto& e1, auto& e2) {
    return e1[2] < e2[2] || (e1[2] == e2[2] && e1[1] < e2[1]);
  });

  for (int i = 0; i < n; ++i) {
    cout << a[i][1] + 1 << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}