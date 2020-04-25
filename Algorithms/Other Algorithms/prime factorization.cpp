#include <iostream>
#include<cstdlib>
#include<cmath>

void primeFactor(int n);

int main(int argc, char const *argv[])
{
	primeFactor(1000);
	system("pause");
	return 0;
}
void primeFactor(int n){
	/*if number is divided by 2 than half the number and print 2 */
	while(n % 2 == 0){
		std::cout << 2 << " ";
		n /= 2;
	}
	/*if number becomes odd*/
	for (int i = 3; i <=  sqrt(n);i += 2)
	{
		while(n % i == 0){
			std::cout << i << " ";
			n /= i;
		}
	}
	if (n > 2)
	{
		std::cout << n << " ";
	}
}