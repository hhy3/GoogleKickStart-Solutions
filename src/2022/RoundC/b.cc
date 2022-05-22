#include <bits/stdc++.h>
using namespace std;

void solve() {
  int64_t n, X, Y; cin >> n >> X >> Y;
  int64_t sum = n * (n + 1) / 2;
  if (sum * X % (X + Y)) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  int64_t s1 = sum * X / (X + Y); 
  vector<int> a;
  for (int i = n; i >= 1; --i) {
    if (s1 >= i) s1 -= i, a.push_back(i);
  }
  if (s1) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  cout << "POSSIBLE\n";
  cout << a.size() << "\n";
  for (auto x : a) cout << x << " ";
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