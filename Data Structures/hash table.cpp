#include<iostream>
#ifndef SIZE
#define SIZE 20
#endif

struct DataItem{
	int data,key;
};
struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;
void display();

int hashCode(int key){
	return key % SIZE;
}

struct DataItem *search(int key);
void insert(int key,int data);
struct DataItem *delete_item(struct DataItem *item);

int main(int argc, char const *argv[])
{
	
	return 0;
}

struct DataItem *search(int key){
	int hashIndex = hashCode(key);

	while(hashArray[hashIndex] != NULL){

		if(hashArray[hashIndex]->key == key){
			return hashArray[hashIndex];
		}

		++hashIndex;

		hashIndex %= SIZE;
	}
	return NULL;
}
void insert(int key,int data){
	struct DataItem *item = new DataItem;
	item->data = data;
	item->key = key;

	int hashIndex = hashCode(key);

	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){
		++hashIndex;
		hashIndex %= SIZE;
	}
	hashArray[hashIndex] = item;

}
struct DataItem *delete_item(struct DataItem *item){
	int key = item->key;

	int hashIndex = hashCode(key);


	while(hashArray[hashIndex] != NULL){
		if(hashArray[hashIndex]->key == key){
			struct DataItem *temp = hashArray[hashIndex];

			hashArray[hashIndex] = dummyItem;
			return temp;
		}
		++hashIndex;
		hashIndex %= SIZE;
	}	
	return NULL;
}
void display(){
	
	for(int i =0;i < SIZE;i++){
		if(hashArray[i] != NULL){
			std::cout << "("<<hashArray[i]->key<< "," <<hashArray[i] -> data<<")";
		}
	}
}