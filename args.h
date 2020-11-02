vector<int> read_int_args()
{
	int N;
	cin >> N;
	vector<int> v(N);
	for (auto& e : v) {
		cin >> e;
	}
	return v;
}
