#include <iostream>
#include <string.h>
#include <math.h>
#ifndef MACHWORD_H
#define MACHWORD_H
class Set {
    private:
		int N, cnt;
		int n;
		char S;
		char *elems;
		long machWord;
		
		
		int posInSet(char sym){
			return sym - 'a';	
		};
		
		char symByPos(int pos){
			return char(pos + 'a');
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
		
		void setToArr(char* set, bool* arr){
			for(int i = 0;i < strlen(set);i++){
				if(arr[int(set[i]) - 97] == false)	arr[int(set[i]) - 97] = true;
			}
		};
		
		long mappingSet(char* set){
			long N = 0;
			for(int i = 0;set[i] != '\0';i++){
				N += 1 << posInSet(set[i]);
			}
			return N;
		};
		
		char* mappingSetReverse(long machWord){
			char* A = NULL;
			int k = 0;
			if(machWord != 0){
				A = new char[26];
				for(int i = 0;i < 26;++i){
					if((machWord >> i) & 1)	A[k++] = symByPos(i);
				}
				A[k] = '\0';
			}
			return A;
		};
		
	public:
		Set() {
//			cnt++;
			this->N = 26;
			this->n = 0;
			this->elems = NULL;
			this->S = '4';
			this->machWord = 0;
//			std::cout << "constructor()" << std::endl;
		};
		
		Set(char *str) {
//			cnt++;
			bool uni[26];
			char* resStr = NULL;
			for(int i = 0;i < 26;i++)	uni[i] = 0;
			this->N = 26;
			this->S = '4';
			if(str != NULL) {
				for(int i = 0;i < strlen(str);i++)	uni[posInSet(str[i])] = 1;
				resStr = arrToSet(uni);
				this->n = strlen(resStr);
				this->elems = new char[strlen(resStr)];
				for(int i = 0;i < strlen(resStr);i++)	this->elems[i] = resStr[i];
				this->elems[strlen(resStr)] = '\0';
				this->machWord = mappingSet(elems);
			} else {
				this->machWord = 0;
				this->n = 0;
				this->elems = NULL;
			}
			
//			std::cout << "constructor(str)" << std::endl;
		};
		
		Set(const Set &other) {
			this->machWord = other.machWord;
			this->elems = mappingSetReverse(other.machWord);
			this->n = other.n;
			this->N = other.N;
			this->cnt = other.cnt;
			this->S = other.S;
//			std::cout << "constructor(Set)" << std::endl;
		};
		
		void Show() {
			if(this->elems != NULL)		std::cout << this->elems << std::endl;
			else std::cout << "Set is empty!" << std::endl;
		};
		
		int power() {return n;};
		
		Set operator | (const Set &other) {		
			Set res;
			res.machWord = this->machWord | other.machWord;
			res.elems = mappingSetReverse(res.machWord);
			if(res.elems != NULL)	res.n = strlen(res.elems);
			else	res.n = 0;
			res.N = 26;
			res.S = '4';
			
			return res;	
		};
		
		Set operator & (const Set &other) {		
			Set res;
			res.machWord = this->machWord & other.machWord;	
			res.elems = mappingSetReverse(res.machWord);
			if(res.elems != NULL)	res.n = strlen(res.elems);
			else	res.n = 0;
			res.N = 26;
			res.S = '4';
			return res;
		};
		
		Set operator ~ () {
			Set res;
			res.machWord = ~(this->machWord);
			res.elems = mappingSetReverse(res.machWord);
			if(res.elems != NULL)	res.n = strlen(res.elems);
			else	res.n = 0;
			res.N = 26;
			res.S = '4';
			return res;
		};
		
		Set operator = (const Set &other) {
			if(this->elems != NULL)	{
				delete[] this->elems;
				this->elems = NULL;
			}
			if(other.elems != NULL) {
				this->elems = new char[other.n + 1];
				for(int i = 0;i < other.n;i++)	this->elems[i] = other.elems[i];
				this->elems[other.n] = '\0';
			} else	this->elems = NULL;
			this->machWord = other.machWord;
			this->S = other.S;
			this->n = other.n;
			this->N = other.N;
			this->cnt = other.cnt;
			return *this;
		};
		
		~Set() {
			delete[] this->elems;
//			std::cout << "Destructor" << std::endl;
		};
};
#endif
