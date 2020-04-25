#include <iostream>
#include<cstdlib>

bool isPrime(int n);
int main(int argc, char const *argv[])
{
	std:: cout << isPrime(100);
	system("pause");
	return 0;
}
bool isPrime(int n){
	if (n <= 1)
	{
		return false;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}

	}
	return true;
}