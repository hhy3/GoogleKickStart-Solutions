#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int x = 1, y = 1, z = 1, t = 1;
  for (auto c : s) {
    if (c >= 'A' && c <= 'Z') x=0;
    else if (c >= 'a' && c <= 'z') y=0;
    else if (c >= '0' && c <= '9') z=0;
    else t = 0;
  }
  if (x) s += 'A';
  if (y) s += 'a';
  if (z) s += '0';
  if (t) s += '@';
  while (s.size() < 7) s += '0';
  cout << s << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}