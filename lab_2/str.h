#include <iostream>
#include <string.h>
#ifndef STR_H
#define STR_H
class Set {
    private:
		int N, cnt;
		int n;
		char S;
		char *elems;
		
		int posInSet(char sym){
			return sym - 'a';	
		};
		
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
	public:
		Set() {
//			cnt++;
			this->N = 26;
			this->n = 0;
			this->elems = NULL;
			this->S = '1';
//			std::cout << "constructor()" << std::endl;
		};
		
		Set(char *str) {
//			cnt++;
			bool uni[26];
			char* resStr = NULL;
			for(int i = 0;i < 26;i++)	uni[i] = 0;
			this->N = 26;
			this->S = '1';
			if(str != NULL) {
				for(int i = 0;i < strlen(str);i++)	uni[posInSet(str[i])] = 1;
				resStr = arrToSet(uni);
				this->n = strlen(resStr);
				this->elems = new char[strlen(resStr)];
				for(int i = 0;i < strlen(resStr);i++)	this->elems[i] = resStr[i];
				this->elems[strlen(resStr)] = '\0';
			} else {
				this->n = 0;
				this->elems = NULL;
			}
			
//			std::cout << "constructor(str)" << std::endl;
		};
		
		Set(const Set &other) {
			if(other.elems != NULL) {
				this->elems = new char[other.n];
				for(int i = 0;i < other.n;i++)	this->elems[i] = other.elems[i];
				this->elems[other.n] = '\0';
			}else	this->elems = NULL;
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
			bool strToUniArrA[26], strToUniArrB[26], result[26];
			Set res;
			for(int i = 0;i < 26;i++){
				strToUniArrA[i] = 0;	strToUniArrB[i] = 0;
				result[i] = 0;	
			}
			
			if(this->n != 0 && other.n != 0) {
				setToArr(other.elems, strToUniArrA);
				setToArr(this->elems, strToUniArrB);
				for(int i = 0; i < 26; i++){
					result[i] = strToUniArrA[i] || strToUniArrB[i];
				}
				res = Set(arrToSet(result));
			}
			else if(this->n == 0)	res = other;
			else if(other.n == 0)	res = *this;
			
			return res;	
		};
		
		Set operator & (const Set &other) {
			bool strToUniArrA[26], strToUniArrB[26], result[26];
			Set res;
			for(int i = 0;i < 26;i++){
				strToUniArrA[i] = 0;	strToUniArrB[i] = 0;
				result[i] = 0;	
			}	
			
			if(this->n != 0 && other.n != 0) {
				setToArr(other.elems, strToUniArrA);
				setToArr(this->elems, strToUniArrB);
				
				for(int i = 0; i < 26; i++){
					result[i] = strToUniArrA[i] && strToUniArrB[i];
				}	
				res = Set(arrToSet(result));
			}
			return res;
		};
		
		Set operator ~ () {
			bool strToUniArrA[26], result[26];
			Set res;
			if(this->n != 0) {
				for(int i = 0;i < 26;i++){
					strToUniArrA[i] = 0;
					result[i] = 0;	
				}	
				setToArr(this->elems, strToUniArrA);
				
				for(int i = 0; i < 26; i++){
					result[i] = !(strToUniArrA[i]);
				}
			}
			else	for(int i = 0;i < this->N;i++)	result[i] = 1;
			res = Set(arrToSet(result));
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
