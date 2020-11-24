class Combination1 {
public:
	Combination1(ll P, ll N) : P(P), N(N), comb(N+1), inv(N+1) /*, fact_inv(N+1)*/ {
		inv[0] = inv[1] = 1;
		for (ll i = 2; i < N; i++) {
			inv[i] = P - inv[P % i] * (P / i) % P;
		}
		comb[0] = 1;
		for (ll i = 1; i < N; i++) {
			comb[i] = comb[i - 1] * ((N - i + 1) * inv[i] % P) % P;
		}
		comb[N] = 1;
	}

	ll operator[](ll k)
	{
		return comb[k];
	}

private:
	ll P;
	ll N;
	llvec comb;
	llvec inv;
};

template<ll P>
class Combination {
public:
	Combination() {
		m_fact.resize(16);
		m_inv.resize(16);
		m_fact_inv.resize(16);
		m_fact[0] = m_fact[1] = 1;
		m_inv[0] = m_inv[1] = 1;
		m_fact_inv[0] = m_fact_inv[1] = 1;
	}

	ll fact(ll x)
	{
		if (m_fact.size() < x + 1) m_fact.resize(x + 1);
		if (m_fact[x]) return m_fact[x];
		return m_fact[x] = mod(x * fact(x-1));
	}

	ll inv(ll x)
	{
		if (m_inv.size() < x + 1) m_inv.resize(x + 1);
		if (m_inv[x]) return m_inv[x];
		return m_inv[x] = P - inv(P % x) * (P / x) % P;
	}

	ll fact_inv(ll x)
	{
		if (m_fact_inv.size() < x + 1) m_fact_inv.resize(x + 1);
		if (m_fact_inv[x]) return m_fact_inv[x];
		return m_fact_inv[x] = mod(fact_inv(x - 1) * inv(x));
	}

	ll mod(ll x)
	{
		return x % P;
	}

	ll operator()(ll n, ll r)
	{
		return mod(fact(n) * mod(fact_inv(r) * fact_inv(n - r)));
	}

private:
	llvec m_fact;
	llvec m_inv;
	llvec m_fact_inv;
};
