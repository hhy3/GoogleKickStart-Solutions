#include <bits/stdc++.h>
using namespace std;

struct Manacher {
  // d1[i] = max_j s.t. s[i-j:i+j] is palindromic.
  // d2[i] = max_j s.t. s[i-j+1:i+j] is palindromic.
  std::vector<int> d1, d2;
  Manacher(std::string_view s) {
    int n = (int)s.size();
    d1.assign(n, 0), d2.assign(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; ++i) {
      if (i <= r) d1[i] = std::min(d1[l + r - i], r - i);
      while (i - d1[i] - 1 >= 0 && i + d1[i] + 1 < n && s[i - d1[i] - 1] == s[i + d1[i] + 1]) d1[i]++;
      if (i + d1[i] > r) l = i - d1[i], r = i + d1[i];
    }
    for (int i = 0, l = 0, r = -1; i < n; ++i) {
      if (i < r) d2[i] = std::min(d2[l + r - i - 1], r - i);
      while (i - d2[i] >= 0 && i + d2[i] + 1 < n && s[i - d2[i]] == s[i + d2[i] + 1]) d2[i]++;
      if (i + d2[i] > r) l = i - d2[i] + 1, r = i + d2[i];
    }
  }
  int len_odd(int i) { return d1[i] * 2 + 1; }
  int len_even(int i) { return d2[i] * 2; }
  bool is_palindromic(int L, int R) {
    int len = R - L + 1;
    if (len % 2) return 2 * d1[(R + L) / 2] + 1 == len;
    else return 2 * d2[(R + L) / 2] == len;
  }
};
void solve() {
  int n; cin >> n;
  string s; cin >> s;
  Manacher man(s);
  for (int i = 1; i < n; ++i) {
    if (man.is_palindromic(0, i-1) && man.is_palindromic(i, n-1)) {
      cout << s.substr(0, i) << "\n";
      return;
    }
  }
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