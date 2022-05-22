#include <bits/stdc++.h>
using namespace std;
template <uint64_t M>
class modint {
  
private:

  uint64_t _x;  

public:

  modint(): modint(0) {}

  template <typename T>
  modint(T x) {
    if (std::is_signed<T>::value) {
      _x = (x % T(M) + T(M)) % T(M);
    } else {
      _x = x % M;
    }
  }

  modint(const modint& rhs)
    : _x(rhs._x) {}

  modint& operator = (const modint& rhs) {
    _x = rhs._x;
    return *this;
  }

  uint64_t val() {
    return _x;
  }

  modint& operator ++ () {
    _x = (_x + 1) % M;
    return *this;
  }

  modint operator ++ (int) {
    auto ret = *this;
    ++*this;
    return ret;
  }

  modint& operator -- () {
    _x = (_x - 1 + M) % M;
    return *this;
  }

  modint operator -- (int) {
    auto ret = *this;
    --*this;
    return ret;
  }

  modint& operator += (const modint& rhs) {
    _x = (_x + rhs._x) % M;
    return *this;
  } 

  modint& operator -= (const modint& rhs) {
    _x = (_x - rhs._x + M) % M;
    return *this;
  }

  modint& operator *= (const modint& rhs) {
    _x = _x * rhs._x % M;
    return *this;
  }

  modint& operator /= (const modint& rhs) {
    return *this *= rhs.inv();
  } 

  modint inv() const {
    assert(_x > 0);
    int64_t u, v;
    int64_t d = extgcd(int64_t(_x), int64_t(M), u, v);
    assert(d == 1);
    return modint(u);
  }

  modint pow(int b) {
    assert(b >= 0);
    modint ret = 1, tmp = *this;
    for (; b; b >>= 1) {
      if (b & 1) ret *= tmp;
      tmp *= tmp;
    }
    return ret;
  }

  friend modint operator + (const modint& lhs, const modint &rhs) {
    return modint(lhs) += rhs;
  }

  friend modint operator - (const modint& lhs, const modint &rhs) {
    return modint(lhs) -= rhs;
  }

  friend modint operator * (const modint& lhs, const modint &rhs) {
    return modint(lhs) *= rhs;
  }

  friend modint operator / (const modint& lhs, const modint &rhs) {
    return modint(lhs) /= rhs;
  }

  friend bool operator == (const modint& lhs, const modint &rhs) {
    return lhs._x == rhs._x;
  }

  friend bool operator != (const modint& lhs, const modint &rhs) {
    return lhs._x != rhs._x;
  }

  friend std::ostream& operator << (std::ostream& os, const modint& rhs) {
    os << rhs._x;
    return os;
  }

  friend std::istream& operator >> (std::istream& is, modint& rhs) {
    is >> rhs._x;
    return is;
  }

private: 

  template <typename T>
  static T extgcd(T a, T b, T& x, T& y) {
    if (b == 0) {
      x = 1, y = 0;
      return a;
    }
    T d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
  }

};

using mint = modint<int(1e9+7)>;

mint f[410][410][410], fac[410];

int init = [] () {
  fac[0] = 1;
  for (int i = 1; i < 410; ++i) fac[i] = fac[i-1] * i;
  return 0;
} ();

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<mint> cnt(n+1);
  for (int i = 0; i < n; ++i) f[i][i][0] = f[i][i][1] = 1;
  for (int i = 0; i < n - 1; ++i) f[i][i+1][0] = 1, f[i][i+1][1] = 2, f[i][i+1][2] = s[i]==s[i+1];
  for (int len = 3; len <= n; ++len) {
    for (int i = 0; i + len - 1 < n; ++i) {
      int j = i + len - 1;
      f[i][j][0] = 1;
      f[i][j][1] = len;
      for (int k = 2; k <= len; ++k) {
        f[i][j][k] = f[i+1][j][k] + f[i][j-1][k] - f[i+1][j-1][k];
        if (s[i] == s[j]) {
          f[i][j][k] += f[i+1][j-1][k-2];
        }
      }
    }
  }
  mint ans = 0;
  for (int k = 0; k < n; ++k) {
    ans += f[0][n-1][k] * fac[k] * fac[n-k];
  }
  cout << ans / fac[n] << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}