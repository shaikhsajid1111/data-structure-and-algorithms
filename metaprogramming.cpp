#include <iostream>
#include<cstdlib>
#include<tuple>

template<unsigned int n>
struct factorial{
	enum{value = n * factorial<n-1>::value};
};

template<>
struct factorial<0>{
	enum{value = 1};
};

/*
template<long long n>
struct factorial:
	std::integral_constant<long long, n*factorial<n-1>::value>{};

template <>
	struct factorial<0>:
	std::integral_constant<long long,1>{};


constexpr long long fact(long long n){
	return (n == 0) ? 1 : n*fact(n-1);
}*/
/*
C > +11	
std::tuple<int,int,int,int> operation(int a,int b){
	return std::make_tuple(a+b,a-b,a*b,a/b);
}*/	
std::tuple<int,int,int,int> operation(int a,int b){
	return {a+b,a-b,a*b,a/b};
}
/*
template <class F>
void foo(int a, int b, F consumer) {
 consumer(a + b, a - b, a * b, a / b);
}
// use is simple... ignoring some results is possible as well
foo(5, 12, [](int sum, int , int , int ){
 std::cout << "sum is " << sum << '\n';
});
*/
std::array<int ,4> bar(int a,int b){
	return {a+b,a-b,a*b,a/b};
}
int main(int argc, char const *argv[])
{

	//int add,sub,mul,div;
	//std::tie(add,sub,mul,div) = operation(5,12);
	std::cout << factorial<5>::value;
	system("pause");
	return 0;
}