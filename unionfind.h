class UnionFind {
public:
	UnionFind(int n)
	{
		parent.assign(n, 0);
		for (int i = 0; i < n; i++)
			parent[i] = i;
		rank.assign(n, 0);
	}

	bool unite(int a, int b)
	{
		a = root(a);
		b = root(b);
		if (a == b)
			return false;
		if (rank[a] > rank[b]) {
			parent[b] = a;
		} else {
			parent[a] = b;
			if (rank[a] == rank[b])
				rank[b]++;
		}
		return true;
	}

	bool same(int a, int b)	{ return root(a) == root(b); }
private:
	int root(int i) { return parent[i] == i ? i : parent[i] = root(parent[i]); }
	std::vector<int> parent;
	std::vector<int> rank;
};
