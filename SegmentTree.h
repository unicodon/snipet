template <typename T, T InitValue>
class SegmentTree {
public:
	using Func = std::function<T(T, T)>;
	SegmentTree(long long n, Func&& func) : func(std::move(func)) {
		N = 2; // FIXME:
		while (n > 0) {
			N <<= 1;
			n >>= 1;
		}
		values = std::vector<T>(N, InitValue);
	}

	void update(long long i, T value) {
		auto node = N / 2 - 1 + i;
		values[node] = func(values[node], value);
		while (true) {
			if (node == 0) return;
			node = (node - 1) / 2;
			values[node] = func(values[node * 2 + 1], values[node * 2 + 2]);
		}
	}

	T query(long long begin, long long end) {
		return queryInternal(begin, end, 0, 0, N / 2);
	}

	T queryInternal(long long begin, long long end, long long node, long long left, long long right) {
		if (right <= begin || end <= left) return InitValue;
		if (begin <= left && right <= end) return values[node];
		return func(
			queryInternal(begin, end, node * 2 + 1, left, (left + right) / 2),
			queryInternal(begin, end, node * 2 + 2, (left + right) / 2, right)
		);
	}

	std::vector<T> values;
	Func func;
	long long N;
};
