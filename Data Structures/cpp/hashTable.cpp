#include<iostream>
#include<string>
#ifndef TABLE_SIZE
#define TABLE_SIZE 3333
#endif

template<typename T>
class HashTable{
	private:
	 T *table = new T[TABLE_SIZE];
	 int numItems = 0;
	
	public:
	int hashStringToInt(std::string s,int tableSize);

	void resize();
  	void setItem(std::string key,T value);
	void getItem(std::string key);
};

int main(int argc,char const **argv){
	
	HashTable<std::string> mytable;
	mytable.setItem("sajid","great");
	
	

	mytable.getItem("sajid");
	

	return 0;
}


template<class T>
int HashTable<T>::hashStringToInt(std::string s,int tableSize){
	int hash = 17;
	for(int i = 0;i < s.size();i++){
		hash = (13 * hash * char(s[i])) % tableSize;
	}

	return hash;
}

template<class T>
void HashTable<T>::setItem(std::string key,T value){
	this->numItems++;

	

	int arrayLength = (sizeof(this->table) / sizeof(*this->table));
	const int loadFactor = this->numItems / arrayLength;

	if(loadFactor > 0.8){
		/*resize the array*/
		resize();
	}
	arrayLength = (sizeof(this->table) / sizeof(*this->table));
	const int idx = hashStringToInt(key,arrayLength);
	this->table[idx] = value;
}

template<class T>
void HashTable<T>::getItem(std::string key){
	this->numItems++;
	int arrayLength = (sizeof(this->table)/sizeof(*this->table));
	int idx = hashStringToInt(key,arrayLength);


	try{
		std::cout << this->table[idx]; 
	}
	catch(const std::out_of_range& oor){
		std::cout << "Not found";
	}
}

template<class T>
void HashTable<T>::resize(){
	
	int arrayLength = (sizeof(this->table)/sizeof(*this->table));
	T* newTable = new T[arrayLength*2];

	std::copy(this->table, this->table + std::min(arrayLength, arrayLength*2), newTable);
	
	delete[] this->table;
	this->table = newTable;
}