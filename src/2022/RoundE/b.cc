#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  multiset<int> st;
  for (auto x : a) st.insert(x);
  for (auto x : a) {
    st.erase(st.find(x));
    auto it = st.upper_bound(2 * x);
    if (it == st.begin()) {
      cout << "-1 ";
    } else {
      cout << *prev(it) << " ";
    }
    st.insert(x);
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