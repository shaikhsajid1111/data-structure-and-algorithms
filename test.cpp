#include <iostream>
#include<cstdlib>
#include<map>
#include<cstring>


void traverse_map(std::map<std::string,int> arr);
void traverse_map_reverse(std::map<std::string,int> arr);

int main(int argc, char const *argv[])
{

	/*
	for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end() ; ++it)
	{
		std::cout << it->first << "=>" << it->second;
	}*/

	//traverse_map(ages);
	//traverse_map_reverse(ages);

	


	system("pause");
	return 0;
}

void traverse_map(std::map<std::string,int> arr){
	
	for (std::map<std::string,int>::iterator it = arr.begin(); it != arr.end() ; ++it)
	{
		std::cout << it->first << "=>" << it->second << std::endl;
	}

}
void traverse_map_reverse(std::map<std::string,int> arr){
	for(std::map<std::string,int>::reverse_iterator it = arr.rbegin();it != arr.rend();++it){
		std::cout << it->first << "=>" << it->second << std::endl;
	}
}