#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

typedef struct List{
	char elem;
	struct List* next;
} list;

void first(char* A, char* B, char* C, char* D, int k);
void second(list* uniSpiA, list* uniSpiB, list* uniSpiC, list* uniSpiD, int k);
void third(bool* bitArrA, bool* bitArrB, bool* bitArrC, bool* bitArrD, int k);
void fourth(long machWordA, long machWordB, long machWordC, long machWordD, int k);

char* generatStr();
char symByPos(int pos);
void setToArr(char* set, bool* arr);
char* arrToSet(bool* arr);
void outputArr(char* arr);
void outputArr(bool* arr);
void outputList(list* spi);
char* mappingSetReverse(long machWord);
char* mapOrdToElem(bool* bA);
list* arrToList(char* arr, list* spi);
void setToArr(list* node0, bool* arr);
list* createElem();
bool catch_exception(char* str);
int posInSet(char sym);
long mappingSet(char* set);
void mapElemToOrd(char* A, bool* bA);
bool is_in_uni(char sym);


string uni = "abcdefghijklmnopqrstuvwxyz";
int main(){
	srand(time(0));
	char *A = NULL, *B = NULL, *C = NULL, *D = NULL, input[80];
	long machWordA, machWordB, machWordC, machWordD, machWordRes;
	bool mdf, flag, bitArrA[26], bitArrB[26], bitArrC[26], bitArrD[26];
	list *uniSpiA = NULL, *uniSpiB = NULL, *uniSpiC = NULL, *uniSpiD = NULL;
	unsigned long t, n = 10000000;
	
	for(int i = 0;i < 26;i++){
		bitArrA[i] = 0;
		bitArrB[i] = 0;
		bitArrC[i] = 0;
		bitArrD[i] = 0;
	}
	
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
	if(mdf)	A = generatStr(); 
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
			A = new char[80];
			do{
				cout << "Enter elements of set A: ";
				cin >> A;
				A[80] = '\0';
			}while(!catch_exception(A));
			
		}else{
			A = new char[1];
			A[0] = '\0';
		}
	}
	
	
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
	if(mdf)	B = generatStr(); 
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
			B = new char[80];
			do{
				cout << "Enter elements of set B: ";
				cin >> B;
				B[80] = '\0';
			}while(!catch_exception(B));
		
		}else{
			B = new char[1];
			B[0] = '\0';
		}
	}
	
	
	
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
	if(mdf)	C = generatStr(); 
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
			C = new char[80];
			do{
				cout << "Enter elements of set C: ";
				cin >> C;
				C[80] = '\0';
			}while(!catch_exception(C));
			
		}else{
			C = new char[1];
			C[0] = '\0';
		}
	}
	

	
	puts(" ");
	
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
	if(mdf)	D = generatStr(); 
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
			do{
				D = new char[80];
				cout << "Enter elements of set D: ";
				cin >> D;
				D[80] = '\0';
			}while(!catch_exception(D));
		}else{
			D = new char[1];
			D[0] = '\0';
		}
	}
	
	
	cout << "\n=======================String======================\n" << endl;
	
	if(A[0] != 0){
		cout << "  Set A: " << A << "\n";		
	} else cout << "  Set A is empty!" << "\n";
	
	
	if(B[0] != 0){
		cout << "  Set B: " << B << "\n";	
	} else cout << "  Set B is empty!" << "\n";
	
	
	if(C[0] != 0){
	cout << "  Set C: " << C << "\n";		
	} else cout << "  Set C is empty!" << "\n";
	
	if(D[0] != 0){
		cout << "  Set D: " << D << "\n";
	} else cout << "  Set D is empty!" << "\n";
	
	cout << "\n=======================Total=======================" << endl;
	cout << "\n  Result : ";
	
	t = clock();
	for(int i = 0; i < n; i++) first(A, B, C, D, i);
	
	cout << "  Time for string: " << (float)(clock() - t) / CLK_TCK << " seconds." << "\n";
	cout << "\n=======================List========================" << endl;
	
//	cout << "Manual input or generate data? (0/1): ";
//	cin >> mdf;
//	if(mdf)	A = generatStr(); 

	if(A[0] != 0){
		cout << "\n  Set A: " << A << "\n";		
	} else cout << "  Set A is empty!" << "\n";

	
//	cout << "Manual input or generate data? (0/1): ";
//	cin >> mdf;
//	if(mdf)	B = generatStr(); 

	if(B[0] != 0){
		cout << "  Set B: " << B << "\n";	
	} else cout << "  Set B is empty!" << "\n";
	

	
//	cout << "Manual input or generate data? (0/1): ";
//	cin >> mdf;
//	if(mdf)	C = generatStr(); 

	if(C[0] != 0){
		cout << "  Set C: " << C << "\n";		
	} else cout << "  Set C is empty!" << "\n";

	
//	cout << "Manual input or generate data? (0/1): ";
//	cin >> mdf;
//	if(mdf)	D = generatStr(); 

	if(D[0] != 0){
		cout << "  Set D: " << D << "\n";
	} else cout << "  Set D is empty!" << "\n";
	
	
	uniSpiA = arrToList(A, uniSpiA);
	uniSpiB = arrToList(B, uniSpiB);
	uniSpiC = arrToList(C, uniSpiC);
	uniSpiD = arrToList(D, uniSpiD);
	
	cout << "\n=======================Total=======================" << endl;
	cout << "\n  Result : ";
	
	t = clock();
	for(int i = 0; i < n; i++) second(uniSpiA, uniSpiB, uniSpiC, uniSpiD, i);
	
	cout << "  Time for list : " << (float)(clock() - t) / CLK_TCK << " seconds." << "\n";
	cout << "\n=====================Bits array====================\n" << endl;
	
//	for(int i = 0; i < 26; i++) bitArrA[i] = rand()%2;
//	for(int i = 0; i < 26; i++) bitArrB[i] = rand()%2;
//	for(int i = 0; i < 26; i++) bitArrC[i] = rand()%2;
//	for(int i = 0; i < 26; i++) bitArrD[i] = rand()%2;
	mapElemToOrd(A, bitArrA);
	mapElemToOrd(B, bitArrB);
	mapElemToOrd(C, bitArrC);
	mapElemToOrd(D, bitArrD);
	cout << "  Bits Array A " << " -> ";
	outputArr(mapOrdToElem(bitArrA));
	cout << "  Bits Array B " << " -> ";
	outputArr(mapOrdToElem(bitArrB));
	cout << "  Bits Array C " << " -> ";
	outputArr(mapOrdToElem(bitArrC));
	cout << "  Bits Array D " << " -> ";
	outputArr(mapOrdToElem(bitArrD));
	
	cout << "\n=======================Total=======================" << endl;
	cout << "\n  Result : ";
	
	t = clock();
	for(int i = 0; i < n; i++) third(bitArrA, bitArrB, bitArrC, bitArrD, i);
	
	cout << "  Time for bit array : " << (float)(clock() - t) / CLK_TCK << " seconds." << "\n";
	cout << "\n====================Machine word===================\n" << endl;
	
//	machWordA = (long)(rand()%16)|rand();
//	machWordB = (long)(rand()%16)|rand();
//	machWordC = (long)(rand()%16)|rand();
//	machWordD = (long)(rand()%16)|rand();
	
	machWordA = mappingSet(A);
	machWordB = mappingSet(B);
	machWordC = mappingSet(C);
	machWordD = mappingSet(D);
	cout << "  Machine Word A : " << machWordA << " -> ";
	outputArr(mappingSetReverse(machWordA));
	cout << "  Machine Word B : " << machWordB << " -> ";
	outputArr(mappingSetReverse(machWordB));
	cout << "  Machine Word C : " << machWordC << " -> ";
	outputArr(mappingSetReverse(machWordC));
	cout << "  Machine Word D : " << machWordD << " -> ";
	outputArr(mappingSetReverse(machWordD));
	
	cout << "\n=======================Total=======================" << endl;
	cout << "\n  Result : ";
	
	t = clock();
	for(int i = 0; i < n; i++) fourth(machWordA, machWordB, machWordC, machWordD, i);
	
	cout << "  Time for machine word : " << (float)(clock() - t) / CLK_TCK << " seconds." << "\n";
	cout << "\n===================================================" << endl;
	
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	
	return 0;
}

// 1. string to bool array

void first(char* A, char* B, char* C, char* D, int k){ 
	bool strToUniArrA[26], strToUniArrB[26], strToUniArrC[26], strToUniArrD[26], result[26];
	for(int i = 0;i < 26;i++){
		strToUniArrA[i] = 0;	strToUniArrB[i] = 0;	strToUniArrC[i] = 0;	strToUniArrD[i] = 0;
		result[i] = 0;	
	}	
	setToArr(A, strToUniArrA);
	setToArr(B, strToUniArrB);
	setToArr(C, strToUniArrC);
	setToArr(D, strToUniArrD);
	
	for(int i = 0; i < 26; i++){
		result[i] = (strToUniArrA[i] || strToUniArrB[i] || strToUniArrC[i]) && !strToUniArrD[i];
	}
	if(k == 0) outputArr(arrToSet(result));
}

// 2. list
void second(list* uniSpiA, list* uniSpiB, list* uniSpiC, list* uniSpiD, int k){
	bool listToUniArrA[26], listToUniArrB[26], listToUniArrC[26], listToUniArrD[26], result[26];
	for(int i = 0;i < 26;i++){
		listToUniArrA[i] = 0;
		listToUniArrB[i] = 0;
		listToUniArrC[i] = 0;
		listToUniArrD[i] = 0;
		result[i] = 0;
	}
	setToArr(uniSpiA, listToUniArrA);	
	setToArr(uniSpiB, listToUniArrB);
	setToArr(uniSpiC, listToUniArrC);
	setToArr(uniSpiD, listToUniArrD);
	
	for(int i = 0;i < 26;i++){
		result[i] = (listToUniArrA[i] || listToUniArrB[i] || listToUniArrC[i]) && !listToUniArrD[i];
	}
	if(k == 0) outputArr(arrToSet(result));
}

// 3. bits array
void third(bool* bitArrA, bool* bitArrB, bool* bitArrC, bool* bitArrD, int k){
	bool result[26];
	
	for(int i = 0;i < 26;i++){
		result[i] = (bitArrA[i] || bitArrB[i] || bitArrC[i]) && !bitArrD[i];
	}
	if(k == 0) outputArr(mapOrdToElem(result));
}

// 4. machine words

void fourth(long machWordA, long machWordB, long machWordC, long machWordD, int k){
	long machWordRes;
	machWordRes = (machWordA | machWordB | machWordC) & ~machWordD;
	if(k == 0) outputArr(mappingSetReverse(machWordRes));
}

char* generatStr(){
	int k = 0; char* set = NULL; set = new char[26];
	for(int i = 0; i < 26; i++) if(rand()%2) set[k++] = symByPos(i); set[k] = 0;
	return set; 
}

char symByPos(int pos){
	return char(pos + 'a');
}

void setToArr(char* set, bool* arr){
	for(int i = 0;i < strlen(set);i++){
		if(arr[int(set[i]) - 97] == false)	arr[int(set[i]) - 97] = true;
	}
}

char* arrToSet(bool* arr){
	char* set = NULL;
	int n = 0, j = 0;
	for(int i = 0;i < 26;i++)	if(arr[i])	n++;
	if(n > 0)	set = new char[n];
	for(int i = 0;i < 26;i++){
		if(arr[i])		set[j++] = char(i + 97);
	}
	if(n > 0)	set[j] = '\0';
	return set;
}

void outputArr(char* arr){
	if(arr != NULL){
		for(int i = 0;i < strlen(arr);i++)	cout << arr[i];
		puts(" ");
	} else	cout << "  Set is empty!" << "\n";
}

void outputArr(bool* arr){
	bool flag = 0;
	for(int i = 0;i < 26;i++)	if(arr[i] == 1)		flag = 1;
	if(flag) {
		for(int i = 0;i < 26;i++){
			cout << char(i+97) << ": " << arr[i] << endl;
		}
	} else	cout << "set is empty!" << endl;
}

void outputList(list* spi){
	while(spi != NULL){
		cout << spi->elem << endl;
		spi = spi->next;
	}
}

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
}

char* mapOrdToElem(bool* bA){
	char* A = NULL;
	int k = 0;
	bool flag = 0;
	for(int i = 0;i < 26;i++)	if(bA[i] == 1)	flag = 1;
	if(flag){
		A = new char[26];
		for(int i = 0;i < 26;++i){
			if(bA[i])	A[k++] = symByPos(i);
		}
		A[k] = '\0';
	}	
	return A;
}

list* arrToList(char* arr, list* spi){
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

void setToArr(list* node0, bool* arr){
	list* spi = node0;
	while(spi != NULL){
		if(arr[spi->elem - 97] == false)	arr[spi->elem - 97] = true;
		spi = spi->next;
	}
}

int posInSet(char sym){
	return sym - 'a';	
}

void mapElemToOrd(char* A, bool* bA) {
	for(int i = 0;A[i];++i){
		bA[posInSet(A[i])] = 1;
	}
}


long mappingSet(char* set){
	long N = 0;
	for(int i = 0;set[i] != '\0';i++){
		N += 1 << posInSet(set[i]);
	}
	return N;
}

list* createElem(){
	list* spi = new list;
	spi->next = NULL;
	spi->elem = false;
	return spi;
}
