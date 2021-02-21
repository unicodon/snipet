struct Range {
	ll x;
	ll y;
	Range(ll x, ll y) : x(x), y(y)
	{
		if (y > x) swap(x,y);
	}

	struct Iterator {
		using difference_type   = ptrdiff_t;
		using value_type        = ll;
		using pointer           = ll*;
		using reference         = ll&;
		using iterator_category = std::random_access_iterator_tag;
		Iterator() = default;
		Iterator(ll n) : n(n) {}
		ll n;
		bool operator!=(const Iterator&rhs) const { return n != rhs.n; }
		bool operator==(const Iterator&rhs) const { return n == rhs.n; }
		Iterator& operator++() { n++; return *this; }
		Iterator& operator--() { n--; return *this; }
		Iterator& operator+=(ll x) { n+=x; return *this; }
		ll operator*() const { return n; }
		ptrdiff_t operator-(const Iterator&rhs) const { return n - rhs.n; }
	};

	Iterator begin() { return Iterator(x); }
	Iterator end() { return Iterator(y); }
};
