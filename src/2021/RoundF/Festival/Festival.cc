#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  unordered_map<int, vector<int>> st, ed;
  for (int i = 0; i < m; ++i) {
    int h, s, e; cin >> h >> s >> e;
    st[s].push_back(h);
    ed[e + 1].push_back(h);
  }
  int64_t ans = 0, sum = 0;
  multiset<int> s1, s2;
  for (int i = 1; i <= n; ++i) {
    // cout << "TEST " << i << ' ' << s1.size() << ' ' << s2.size() << endl;
    for (auto h : st[i]) {
      if (s1.size() == k) {
        if (*s1.begin() < h) {
          sum += h - *s1.begin();
          s2.insert(*s1.begin());
          s1.erase(s1.begin());
          s1.insert(h);
        } else {
          s2.insert(h);
        }
      } else {
        sum += h;
        s1.insert(h);
      }
    }

    for (auto h : ed[i]) {
      if (s1.count(h)) {
        s1.erase(s1.find(h));
        sum -= h;
        if (s2.size()) {
          int x = *s2.rbegin();
          sum += x;
          s2.erase(s2.find(x));
          s1.insert(x);
        }
      } else {
        s2.erase(s2.find(h));
      }
    }
    ans = max(ans, sum);
    // cout << "TEST " << i << endl;
    // for (auto x : s1) cout << x << ' ';
    // cout << endl;
    // for (auto x : s2) cout << x << ' ';
    // cout << endl;
    
  }

  cout << ans << endl;

}

int main() {
  
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}