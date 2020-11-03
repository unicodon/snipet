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

int gcd(int a,int b)
{
	if (a%b==0)
	{
		return(b);
    }
	else
	{
		return(gcd(b,a%b));
    }
}

bool isprim(long long A)
{
	if (A == 1) return false;
	float sq = sqrt(A);
	long long n = 7;
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
