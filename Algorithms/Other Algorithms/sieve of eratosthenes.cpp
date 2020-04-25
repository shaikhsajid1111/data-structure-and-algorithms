#include <iostream>
#include<cstdlib>
#include<cstring>
void sieveOfEratosthenes(int n);
int main(int argc, char const *argv[])
{
	sieveOfEratosthenes(30);
	
	
	system("pause");
	return 0;
}
void sieveOfEratosthenes(int n){
	bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        
        if (prime[p] == true) 
        { 
              
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          std::cout << p << " "; 
}