// T: value type, N: dimension
template<typename T, unsigned N>
struct Vector {
	using ArrayType = std::array<T, N>;
	ArrayType val;

	Vector() = default;
	Vector(std::initializer_list<T> in)
	{
		int i = 0;
		for(auto& e: in)
			val[i++] = e;
	}
	Vector(const Vector& rhs) : val(rhs.val) {}
	Vector& operator=(const Vector& rhs) { val = rhs.val; return *this; }

	T& operator[](unsigned i) { return val[i]; }
	const T& operator[](unsigned i) const { return val[i]; }

	void dump() const
	{
		for (unsigned i = 0; i < N; i++)
			std::cout << val[i] << ", ";
		std::cout << std::endl;
	}

	static constexpr Vector zero()
	{
		Vector v;
		for (unsigned i = 0; i < N; i++)
			v.val[i] = (T)0;
		return v;
	}
};

template<typename T, unsigned N>
T operator*(const Vector<T, N>& lhs, const Vector<T, N>& rhs)
{
	T x = 0;
	for (unsigned i = 0; i < N; i++)
		x += lhs.val[i] * rhs.val[i];
	return x;
}


template<typename T, unsigned N>
struct Matrix {
	using VectorType = Vector<T, N>;
	using MatrixType = std::array<Vector<T, N>, N>;
	MatrixType val;

	Matrix() = default;
	Matrix(std::initializer_list<VectorType> in)
	{
		int i = 0;
		for(auto& e: in)
			val[i++] = e;
	}
	Matrix(std::initializer_list<T> in)
	{
		int i = 0;
		for(auto& e: in) {
			val[i/N][i%N] = e;
			i++;
		}
	}
	T& operator[](unsigned i) { return val[i]; }
	const T& operator[](unsigned i) const { return val[i]; }

	VectorType operator*(const VectorType& rhs) const
	{
		VectorType v;
		for (unsigned i = 0; i < N; i++)
			v[i] = val[i] * rhs;
		return v;
	}

	void dump() const
	{
		std::cout << ">>>" << std::endl;
		for (unsigned i = 0; i < N; i++)
			val[i].dump();
		std::cout << "<<<" << std::endl;
	}

	static constexpr Matrix identity()
	{
		Matrix m;
		for (unsigned i = 0; i < N; i++)
			for (unsigned j = 0; j < N; j++)
				m.val[i][j] = i == j ? (T)1 : (T)0;
		return m;
	}
};

template<typename T, unsigned N>
Matrix<T,N> operator*(const Matrix<T,N>& lhs, const Matrix<T,N>& rhs)
{
	Matrix<T,N> m;
	for (unsigned i = 0; i < N; i++) {
		for (unsigned j = 0; j < N; j++) {
			T tmp = 0;
			for (unsigned k = 0; k < N; k++)
				tmp += lhs.val[i][k] * rhs.val[k][j];
			m.val[i][j] = tmp;
		}
	}
	return m;
}
