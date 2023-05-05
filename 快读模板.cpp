#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e6 + 10;

template <typename T>
void in(T &x) {
  char ch = getchar();
  bool flag = 0;
  x = 0;
  while (ch < '0' || ch > '9') flag |= (ch == '-'), ch = getchar();
  while (ch <= '9' && ch >= '0')
    x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  if (flag) x = -x;
  return;
}

int main() {
  std::string str_dec = "2001, A Space Odyssey";

  string::size_type sz;

  ll a = 10;

  int i_dec = std::stoll(str_dec, &sz, (long long)a);
  std::cout << str_dec << ": " << i_dec << "\n";

  std::cout << atoi(str_dec.c_str());
  return 0;
}
