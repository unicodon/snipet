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

