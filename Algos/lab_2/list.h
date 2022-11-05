#include <iostream>
#include <string.h>
#ifndef LIST_H
#define LIST_H

class Set {
    private:
		typedef struct List{
			char elem;
			struct List* next;
		} list;
		int N;
		int n;
		char S;
		list* node0;
		
		int posInSet(char sym){
			return sym - 'a';	
		};
		
		list* addToList(list* node0, char sym) {
			list* obj = NULL, *p;
			if(node0 == NULL) {
				node0 = createElem();
				node0->elem = sym;
			}
			else {
				obj = node0;
				while(obj->next != NULL)	obj = obj->next;
				p = createElem();
				p->elem = sym;
				obj->next = p;
			}
			return node0;
		}
		
		list* strToList(char* arr, list* spi){
			list *node0 = NULL, *elem = NULL;
			for(int i = 0;i < strlen(arr);i++){
				spi = createElem();
				if(i == 0)	node0 = spi;
				else	elem->next = spi;
				spi->elem = arr[i];
				elem = spi;
				spi = spi->next;
			}	
			return node0;
		}
		
		list* copyList (list* node0) {
			list* node1 = NULL, *obj = NULL, *p;
			int cnt = 0;
			while(node0 != NULL) {
				if(cnt == 0) {
					node1 = createElem();
					node1->elem = node0->elem;
				}
				else {
					p = node1;
					while(p->next != NULL)	p = p->next;
					obj = createElem();
					obj->elem = node0->elem;
					p->next = obj;
				}
				node0 = node0->next;
				cnt++;
			}
			return node1;
		}
		
		char* arrToSet(bool* arr){
			char* set = NULL;
			int n = 0, j = 0;
			for(int i = 0;i < 26;i++)	if(arr[i])	n++;
			if(n > 0) {
				set = new char[n];
				for(int i = 0;i < 26;i++)	if(arr[i])		set[j++] = char(i + 97);
				set[j] = '\0';
			}	
			return set;
		};

		
		void setToArr(list* node0, bool* arr){
			list* spi = node0;
			while(spi != NULL){
				if(arr[spi->elem - 97] == false)	arr[spi->elem - 97] = true;
				spi = spi->next;
			}
		};
		
		list* createElem(){
			list* spi = new list;
			spi->next = NULL;
			return spi;
		};
		
		void deleteList(list* node0) {
			list* elem = NULL;
			while(node0 != NULL) {
				elem = node0;
				node0 = node0->next;
				delete elem;
				elem = NULL;
			}
		}
		
	public:
		Set() {
//			cnt++;
			this->N = 26;
			this->n = 0;
			this->node0 = NULL;
			this->S = '2';
//			std::cout << "constructor()" << std::endl;
		};
		
		Set(char *str) {
//			cnt++;
			bool uni[26];
			char* resStr = NULL;
			for(int i = 0;i < 26;i++)	uni[i] = 0;
			this->N = 26;
			this->S = '2';
			if(str != NULL) {
				for(int i = 0;i < strlen(str);i++)	uni[posInSet(str[i])] = 1;
				resStr = arrToSet(uni);
				this->n = strlen(resStr);
				this->node0 = NULL;
				this->node0 = strToList(resStr, this->node0);
			} else {
				this->n = 0;
				this->node0 = NULL;
			}
			
//			std::cout << "constructor(str)" << std::endl;
		};
		
		Set(const Set &other) {
			this->node0 = copyList(other.node0);
			this->n = other.n;
			this->N = other.N;
			this->S = other.S;
//			std::cout << "constructor(Set)" << std::endl;
		};
		
		void Show() {
			list* p = this->node0;
			if(p != NULL) {
				while(p != NULL) {
					std::cout << p->elem;
					p = p->next;
				}
				std::cout << "\n";
			}
			else std::cout << "Set is empty!" << std::endl;
		};
		
		int power() {return n;};
		
		Set operator | (const Set &other) {			
			bool listToUniArrA[26], listToUniArrB[26], result[26];
			Set res;
			for(int i = 0;i < 26;i++){
				listToUniArrA[i] = 0;	listToUniArrB[i] = 0;
				result[i] = 0;	
			}
			
			if(this->n != 0 && other.n != 0) {
				setToArr(other.node0, listToUniArrA);
				setToArr(this->node0, listToUniArrB);
				for(int i = 0; i < 26; i++){
					result[i] = listToUniArrA[i] || listToUniArrB[i];
				}
				res = Set(arrToSet(result));
			}
			else if(this->n == 0)	res = other;
			else if(other.n == 0)	res = *this;
			return res;	
		};
		
		Set operator & (const Set &other) {
			bool listToUniArrA[26], listToUniArrB[26], result[26];
			Set res;
			for(int i = 0;i < 26;i++){
				listToUniArrA[i] = 0;	listToUniArrB[i] = 0;
				result[i] = 0;	
			}
			
			if(this->n != 0 && other.n != 0) {
				setToArr(other.node0, listToUniArrA);
				setToArr(this->node0, listToUniArrB);
				for(int i = 0; i < 26; i++){
					result[i] = listToUniArrA[i] && listToUniArrB[i];
				}
				res = Set(arrToSet(result));
			}
			return res;
		};
		
		Set operator ~ () {
			bool listToUniArrA[26], result[26];
			Set res;
			if(this->n != 0) {
				for(int i = 0;i < 26;i++){
					listToUniArrA[i] = 0;
					result[i] = 0;	
				}	
				setToArr(this->node0, listToUniArrA);
				for(int i = 0; i < 26; i++){
					result[i] = !(listToUniArrA[i]);
				}
			}
			else	for(int i = 0;i < this->N;i++)	result[i] = 1;
			res = Set(arrToSet(result));
			return res;
		};
		
		Set operator = (const Set &other) {
			if(this->n > 0)		deleteList(this->node0);
			if(other.node0 > 0)		this->node0 = copyList(other.node0);
			else	this->node0 = NULL;
			this->S = other.S;
			this->n = other.n;
			this->N = other.N;
			return *this;
		};
		
		~Set() {
			deleteList(this->node0);
//			std::cout << "Destructor" << std::endl;
		};
};
#endif
