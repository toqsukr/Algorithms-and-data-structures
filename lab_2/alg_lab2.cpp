#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "machword.h"

using namespace std;

void first(Set A, Set B, Set C, Set D, int k);

char* generatStr();
char symByPos(int pos);
bool is_in_uni(char sym);
bool catch_exception(char* str);

string uni = "abcdefghijklmnopqrstuvwxyz";
int main(){
	srand(time(0));
	unsigned long t, n = 1000000;
	char input[80], *arr = NULL;
	bool mdf, flag;
	Set A, B, C, D, res;
	cout << "====================Input set A====================" << endl;
	cout << "\nValid elements for set: abcdefghijklmnopqrstuvwxyz" << endl;
	cout << "\n  Manual input or generate data? (0/1): ";
	flag = 1;
	cin >> input;
	if(strlen(input) > 1)	flag = 0;
	else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
	while(!flag){
		flag = 1;
		cout << "\n  Manual input or generate data? (0/1): ";
		cin >> input;
		if(strlen(input) > 1)	flag = 0;
		else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
	}
	mdf = atoi(input);
	cout << endl;
	if(mdf)	A = Set(generatStr()); 
	else{
		cout << "Is the set empty? (0/1): ";
		flag = 1;
		cin >> input;
		if(strlen(input) > 1)	flag = 0;
		else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
		while(!flag){
			flag = 1;
			cout << "Is the set empty? (0/1): ";
			cin >> input;
			if(strlen(input) > 1)	flag = 0;
			else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
		}
		mdf = atoi(input);
		if(!mdf){
			arr = new char[80];
			do{
				cout << "Enter elements of set A: ";
				cin >> arr;
			}while(!catch_exception(arr));
		}
		A = Set(arr);
	}
	cout << "Set A: ";
	A.Show();
	
	delete[] arr;
	arr = NULL;
	cout << "====================Input set B====================" << endl;
	cout << "\nValid elements for set: abcdefghijklmnopqrstuvwxyz" << endl;
	cout << "\n  Manual input or generate data? (0/1): ";
	flag = 1;
	cin >> input;
	if(strlen(input) > 1)	flag = 0;
	else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
	while(!flag){
		flag = 1;
		cout << "\n  Manual input or generate data? (0/1): ";
		cin >> input;
		if(strlen(input) > 1)	flag = 0;
		else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
	}
	mdf = atoi(input);
	cout << endl;
	if(mdf)	B = Set(generatStr()); 
	else{
		cout << "Is the set empty? (0/1): ";
		flag = 1;
		cin >> input;
		if(strlen(input) > 1)	flag = 0;
		else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
		while(!flag){
			flag = 1;
			cout << "Is the set empty? (0/1): ";
			cin >> input;
			if(strlen(input) > 1)	flag = 0;
			else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
		}
		mdf = atoi(input);
		if(!mdf){
			arr = new char[80];
			do{
				cout << "Enter elements of set B: ";
				cin >> arr;
			}while(!catch_exception(arr));
		}
		B = Set(arr);
	}
	
	cout << "\nSet B: ";
	B.Show();
	
	delete[] arr;
	arr = NULL;
	
	cout << "====================Input set C====================" << endl;
	cout << "\nValid elements for set: abcdefghijklmnopqrstuvwxyz" << endl;
	cout << "\n  Manual input or generate data? (0/1): ";
	flag = 1;
	cin >> input;
	if(strlen(input) > 1)	flag = 0;
	else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
	while(!flag){
		flag = 1;
		cout << "\n  Manual input or generate data? (0/1): ";
		cin >> input;
		if(strlen(input) > 1)	flag = 0;
		else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
	}
	mdf = atoi(input);
	cout << endl;
	if(mdf)	C = Set(generatStr()); 
	else{
		cout << "Is the set empty? (0/1): ";
		flag = 1;
		cin >> input;
		if(strlen(input) > 1)	flag = 0;
		else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
		while(!flag){
			flag = 1;
			cout << "Is the set empty? (0/1): ";
			cin >> input;
			if(strlen(input) > 1)	flag = 0;
			else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
		}
		mdf = atoi(input);
		if(!mdf){
			arr = new char[80];
			do{
				cout << "Enter elements of set C: ";
				cin >> arr;
			}while(!catch_exception(arr));
		}
		C = Set(arr);
	}
	
	cout << "\nSet C: ";
	C.Show();
	
	puts(" ");
	
	delete[] arr;
	arr = NULL;
	
	cout << "====================Input set D====================" << endl;
	cout << "\nValid elements for set: abcdefghijklmnopqrstuvwxyz" << endl;
	cout << "\n  Manual input or generate data? (0/1): ";
	flag = 1;
	cin >> input;
	if(strlen(input) > 1)	flag = 0;
	else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
	while(!flag){
		flag = 1;
		cout << "\n  Manual input or generate data? (0/1): ";
		cin >> input;
		if(strlen(input) > 1)	flag = 0;
		else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
	}
	mdf = atoi(input);
	cout << endl;
	if(mdf)	D = Set(generatStr()); 
	else{
		cout << "Is the set empty? (0/1): ";
		flag = 1;
		cin >> input;
		if(strlen(input) > 1)	flag = 0;
		else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
		while(!flag){
			flag = 1;
			cout << "Is the set empty? (0/1): ";
			cin >> input;
			if(strlen(input) > 1)	flag = 0;
			else if((int)input[0] != 48 && (int)input[0] != 49)	flag = 0;
		}
		mdf = atoi(input);
		if(!mdf){
			arr = new char[80];
			do{
				cout << "Enter elements of set D: ";
				cin >> arr;
			}while(!catch_exception(arr));
		}
		D = Set(arr);
	}
	
	cout << "\nSet D: ";
	D.Show();
	cout << "\n=======================Total=======================" << endl;
	t = clock();
	for(int i = 0; i < n; i++) first(A, B, C, D, i);
	
	cout << "  Time for string: " << ((float)(clock() - t) / CLK_TCK) / n << " seconds." << "\n";
	delete[] arr;
	return 0;
}

// 1. string to bool array

void first(Set A, Set B, Set C, Set D, int k){ 
	Set res;
	res = A | B;
	res = res | C;
	res = res & ~D;
	if(k == 0) {
		cout << "\nRes set: ";
		res.Show();
		cout << endl;
	}
}

// 2. list
//void second(list* uniSpiA, list* uniSpiB, list* uniSpiC, list* uniSpiD, int k){
//	bool listToUniArrA[26], listToUniArrB[26], listToUniArrC[26], listToUniArrD[26], result[26];
//	for(int i = 0;i < 26;i++){
//		listToUniArrA[i] = 0;
//		listToUniArrB[i] = 0;
//		listToUniArrC[i] = 0;
//		listToUniArrD[i] = 0;
//		result[i] = 0;
//	}
//	setToArr(uniSpiA, listToUniArrA);	
//	setToArr(uniSpiB, listToUniArrB);
//	setToArr(uniSpiC, listToUniArrC);
//	setToArr(uniSpiD, listToUniArrD);
//	
//	for(int i = 0;i < 26;i++){
//		result[i] = (listToUniArrA[i] || listToUniArrB[i] || listToUniArrC[i]) && !listToUniArrD[i];
//	}
//}

char* generatStr(){
	int k = 0; char* set = NULL;
	set = new char[26];
	for(int i = 0; i < 26; i++) if(rand()%2) set[k++] = symByPos(i); set[k] = 0;
	return set; 
}

char symByPos(int pos){
	return char(pos + 'a');
}

bool is_in_uni(char sym){
	bool flag = false;
	for(int i = 0;i < uni.length();i++)		if(uni[i] == sym)	flag = 1;
	return flag;
}

bool catch_exception(char* str){
	bool flag = true;
	for(int i = 0;i < strlen(str);i++){
		if(!is_in_uni(str[i]))	flag = false;
	}
	return flag;
}
