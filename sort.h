template<class T>
void sort(T& v)
{
	sort(v.begin(), v.end());
}

template<class T>
void rsort(T& v)
{
	sort(v.begin(), v.end(), greater<typename T::value_type>());
}
