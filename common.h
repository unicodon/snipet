#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <list>
#include <deque>
#include <queue>
#include <iomanip>
#include <set>
#include <stack>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <string.h>
#include <functional>

using namespace std;

#define REP(i,n) for (decltype(n) i = 0; i < n; i++)
#define THE_MOD 1'000'000'007

using ll = long long;
using ivec = vector<int>;
using lvec = vector<long>;
using ipair = pair<int, int>;
using llvec = vector<ll>;
using llpair = pair<ll, ll>;

#define umap unordered_map
#define uset unordered_set

template<typename T> ostream& operator <<(ostream& os, const vector<T> &v) { auto n = v.size(); REP(i,n) os << (i ? " " : "") << v[i]; return os; }
template<typename T> istream& operator >>(istream& is, vector<T> &v) { for(auto &e : v) is >> e; return is; }
template<typename T, typename U> ostream& operator <<(ostream& os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
template<typename T, typename U> istream& operator >>(istream& is, pair<T, U> &p) { is >> p.first >> p.second; return is; }

void in() {} template <typename T, typename... Args> void in(T& t, Args& ...args) { cin >> t; in(args...); }
void out() { cout << endl; } template <typename T, typename... Args> void out(const T& t, const Args& ...args) { cout << t; if (sizeof...(args)) cout << " "; out(args...); }

constexpr ll LLINF = numeric_limits<ll>::max();

template<class T> void sort(T& v) {	sort(v.begin(), v.end()); }
template<class T> void rsort(T& v) { sort(v.begin(), v.end(), greater<typename T::value_type>()); }

void YN(bool b) {	cout << (b ? "Yes" : "No") << endl; }
