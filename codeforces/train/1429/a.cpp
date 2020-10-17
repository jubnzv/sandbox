// https://codeforces.com/contest/1429/problem/0
//
// A. 123-последовательность
// Задана последовательность целых чисел a1,a2,…,an, в которой каждое число от 1
// до 3 включительно. Требуется заменить в ней наименьшее количество чисел так,
// чтобы все числа в последовательности оказались равны между собой.
//
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define vi vector<int>
#define mii map<int, int>

int main() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  int t;
  mii m;
  m[1] = 0;
  m[2] = 0;
  m[3] = 0;
  for (int i = 0; i < n; i++) {
    switch (v[i]) {
    case 1:
      m[1]++;
      break;
    case 2:
      m[2]++;
      break;
    case 3:
      m[3]++;
      break;
    }
  }

  vi res = {m[2] + m[3], m[1] + m[3], m[1] + m[2]};
  cout << *std::min_element(res.begin(), res.end());
}
