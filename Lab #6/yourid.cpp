#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int STR2INT (string str){
	int result;
	
	try {
		result = stoi(str);
	} catch (invalid_argument) {
		result = -1;
	}
	
	return result;
}

void Print_Table(list <int>* T, int size){
	list<int>::iterator it;
	for(int i = 0; i < size; i++) {
		cout << i << ":";
		for(it = T[i].begin(); it != T[i].end(); it++) {
			cout << *it << "->";
		}
		cout << ";" <<endl;
	}
}

void Hash_Insert(list <int>* T, int k, int m){
	int hash = (k % m);
	T[hash].push_front(k);
}

void Hash_Search(list <int>* T, int k, int m){
	int hash = (k % m), count = 0;
	bool flag = false;
	list<int>::iterator it;
	for(it = T[hash].begin(); it != T[hash].end(); it++) {
		if(*it == k) {
			cout << k << ":" << "FOUND_AT" << hash << "," << count << ";" <<endl;
			flag = true;
			break;
		}
		count++;
	}
	if(!flag) {
		cout << k << ":NOT_FOUND;" <<endl;
	}
	
}

bool Hash_Delete(list <int>* T, int k, int m){
	int hash = (k % m), count = 0;
	list<int>::iterator it;
	bool flag = false;
	for(it = T[hash].begin(); it != T[hash].end(); ++it) {
		if(*it == k) {
			list<int>::iterator it_del = T[hash].begin();
			advance(it_del, count);
			T[hash].erase(it_del);
			cout << k << ":DELETED;" <<endl;
			return true;
		}
		count++;
	}
	if(!flag) {
		cout << k << ":DELETE_FAILED;" << endl;
	}
	return false;
	
	
}

int main(){
	int arrSize = 0;
	cin >> arrSize;
	
	list<int>* T = new list<int>[arrSize];
	
	string cmd;
	
	while (getline(cin, cmd)) {
		if(cmd.size() == 0) {
			continue;
		}
		
		if(cmd.substr(0,1) == "e") {
			return 0;
		}
		
		if(cmd.substr(0,1) == "o") {
			Print_Table(T, arrSize);
			continue;
		}
		
		int key = STR2INT(cmd.substr(1, cmd.size()-1));
		
		if(cmd.substr(0,1) == "i") {
			Hash_Insert(T, key, arrSize);
		}
		if(cmd.substr(0,1) == "d") {
			Hash_Delete(T, key, arrSize);
		}
		if(cmd.substr(0,1) == "s") {
			Hash_Search(T, key, arrSize);
		}
		
	}

	delete[] T;
	
	return 0;
}
