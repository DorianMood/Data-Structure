template<class T>
void Delete2DArray(T** &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
}
template<class T>
void Make2DArray(T** &a, int n, int m)
{
	a = new T*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new T[m];
	}
}