template <int base>
int digit_sum(int n)
{
	int sum = 0;
	while (n > 0) {
		sum += n % base;
		n /= base;
	}
	return sum;
}

ll gcd(ll a, ll b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

ll gcd(llvec::iterator begin, llvec::iterator end)
{
	auto inner = [&](auto& inner, ll a, llvec::iterator it) -> ll {
		if (it == end)
			return a;
		a = gcd(a, *it++);
		return inner(inner, a, it);
	};
	auto it = begin;
	return inner(inner, *begin, ++it);
}

ll extgcd(ll a, ll b, ll &x, ll &y)
{
/*
a = pb*q; // p = a / b, q = a % b

ax + by
 = pbx + qx + by
 = b(px + y) + qx
 = bY + qX // Y = px + y, X = x ->  y = Y - px
*/

	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll d = extgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

ll lcm(llvec::iterator begin, llvec::iterator end)
{
	auto inner = [&](auto& inner, ll a, llvec::iterator it) -> ll {
		if (it == end)
			return a;
		a = lcm(a, *it++);
		return inner(inner, a, it);
	};
	auto it = begin;
	return inner(inner, *begin, ++it);
}

bool isprim(long long A)
{
	if (A == 1) return false;
	if (A == 2) return true;
	if (A % 2 == 0) return false;
	if (A % 3 == 0) return false;
	if (A % 5 == 0) return false;
	float sq = sqrt(A);
	long long n = 3;
	while (n < sq) {
		if (!(A % n))
			return false;
		n += 2;
	}
	return true;
}


template<typename T> bool chmax(T& a, const T& b)
{
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T> bool chmin(T& a, const T& b)
{
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

void answer(bool b)
{
	cout << (b ? "Yes" : "No") << endl;
}

using irange = ipair;
irange intersection(const irange& a, const irange& b)
{
	auto first = max(a.first, b.first);
	auto second = min(a.second, b.second);
	return irange(first, second);
}

bool intersects(const irange& a, const irange& b)
{
	auto x = intersection(a, b);
	return x.first < x.second;
}

void soinsu_inner(ll n, llvec& v, ll m = 2)
{
	if (n == 1) return;
	if (n != m && n < m * m) {
		v.push_back(n);
		return;
	}

	while (n >= m && (n % m) == 0) {
		v.push_back(m);
		n /= m;
	}
	soinsu_inner(n, v, m + 1);
}

vector<llpair> soinsu(ll n)
{
	llvec v;
	soinsu_inner(n, v);
	ll x = 1;
	vector<llpair> u;
	for (auto& e : v) {
		if (e > x) {
			x = e;
			u.emplace_back(e, 0);
		}
		u.back().second++;
	}
	return u;
}
