#include <iostream>
#include <string.h>
#ifndef BITARR_H
#define BITARR_H
class Set {
    private:
		int N, cnt;
		int n;
		char S, *elems;
		bool *bitSet;
		
		
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
			this->bitSet = NULL;
			this->elems = NULL;
			this->S = '3';
//			std::cout << "constructor()" << std::endl;
		};
		
		Set(char *str) {
//			cnt++;
			char* resStr = NULL;
			this->N = 26;
			this->S = '3';
			if(str != NULL) {
				this->bitSet = new bool[26];
				for(int i = 0;i < 26;i++)	this->bitSet[i] = 0;
				for(int i = 0;i < strlen(str);i++)	this->bitSet[posInSet(str[i])] = 1;
				resStr = arrToSet(this->bitSet);
				this->n = strlen(resStr);
				this->elems = new char[strlen(resStr)];
				for(int i = 0;i < strlen(resStr);i++)	this->elems[i] = resStr[i];
				this->elems[strlen(resStr)] = '\0';
			} else {
				this->bitSet = NULL;
				this->n = 0;
				this->elems = NULL;
			}
			
//			std::cout << "constructor(str)" << std::endl;
		};
		
		Set(const Set &other) {
			if(other.n > 0) {
				this->bitSet = new bool[26];
				for(int i = 0;i < 26;i++)	this->bitSet[i] = 0;
				for(int i = 0;i < 26;i++)	this->bitSet[i] = other.bitSet[i];
				this->elems = arrToSet(this->bitSet);
			}
			else {
				this->bitSet = NULL;
				this->elems = NULL;
			}
			this->n = other.n;
			this->N = other.N;
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
			if(other.n > 0) {
				res.bitSet = new bool[26];
				for(int i = 0;i < 26;i++)	res.bitSet[i] = 0;
				for(int i = 0;i < 26;i++)	res.bitSet[i] = this->bitSet[i] | other.bitSet[i];
				res.elems = arrToSet(res.bitSet);	
				res.n = strlen(res.elems);
			}	
			else if(this->n == 0)	res = other;
			else if(other.n == 0)	res = *this;
			res.N = this->N;
			res.S = this->S;
			return res;	
		};
		
		Set operator & (const Set &other) {		
			Set res;
			if(other.n > 0) {
				res.bitSet = new bool[26];
				for(int i = 0;i < 26;i++)	res.bitSet[i] = 0;
				for(int i = 0;i < 26;i++)	res.bitSet[i] = this->bitSet[i] & other.bitSet[i];
				res.elems = arrToSet(res.bitSet);	
				res.n = strlen(res.elems);
			}
			res.N = this->N;
			res.S = this->S;
			return res;	
		};
		
		Set operator ~ () {
			Set res;
			if(this->n < 26) {
				res.bitSet = new bool[26];
				for(int i = 0;i < 26;i++)	res.bitSet[i] = 0;
				for(int i = 0;i < 26;i++)	res.bitSet[i] = !this->bitSet[i];
				res.elems = arrToSet(res.bitSet);	
				res.n = strlen(res.elems);
			}
			res.N = this->N;
			res.S = this->S;
			return res;	
		};
		
		Set operator = (const Set &other) {
			if(this->n > 0)	{
				delete[] this->elems;
				delete[] this->bitSet;
				this->elems = NULL;
				this->bitSet = NULL;
			}
			if(other.n > 0) {
				this->bitSet = new bool[26];
				for(int i = 0;i < 26;i++)	this->bitSet[i] = 0;
				for(int i = 0;i < 26;i++)	this->bitSet[i] = other.bitSet[i];
				this->elems = arrToSet(this->bitSet);
			} 
			else {
				this->bitSet = NULL;
				this->elems = NULL;
			}	
			this->S = other.S;
			this->n = other.n;
			this->N = other.N;
			return *this;
		};
		
		~Set() {
			delete[] this->elems;
			delete[] this->bitSet;
//			std::cout << "Destructor" << std::endl;
		};
};
#endif
