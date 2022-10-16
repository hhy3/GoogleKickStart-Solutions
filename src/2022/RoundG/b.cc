#include <bits/stdc++.h>
using namespace std;

void solve() {
  int64_t rs, rh; cin >> rs >> rh;
  int64_t R = (rs + rh) * (rs + rh);
  int n; cin >> n;
  vector<int64_t> a;
  for (int i = 0; i < n; ++i) {
    int64_t x, y; cin >> x >> y;
    int64_t d = x * x + y * y;
    if (d <= R) a.push_back(d);
  }
  int m; cin >> m;
  vector<int64_t> b;
  for (int i = 0; i < m; ++i) {
    int64_t x, y; cin >> x >> y;
    int64_t d = x * x + y * y;
    if (d <= R) b.push_back(d);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (!a.size() || !b.size()) {
    cout << a.size() << " " << b.size() << "\n";
    return;
  }
  int X = 0, Y = 0;
  while (X < a.size() && a[X] <= b[0]) X++;
  while (Y < b.size() && b[Y] <= a[0]) Y++;
  cout << X << " " << Y << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
