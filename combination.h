class Combination1 {
public:
	Combination1(ll P, ll N) : P(P), N(N), comb(N+1), inv(N+1) /*, fact_inv(N+1)*/ {
		inv[0] = inv[1] = 1;
		// fact_inv[1] = fact_inv[1] = 1;
		for (ll i = 2; i < N; i++) {
			inv[i] = P - inv[P % i] * (P / i) % P;
			// fact_inv[i] = fact_inv[i - 1] * inv[i] % P;
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
//	llvec fact_inv;
};
