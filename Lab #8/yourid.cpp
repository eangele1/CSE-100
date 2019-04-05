#include <iostream>

using namespace std;

void Print_Optimal_Parentheses(int* s, int& i, int& j, int& n){
	
	if(i == j){
		cout << "A" << i - 1;
	}
	else{
		cout << "(";
		
		int temp = j;
		j = *((s + i * n) + j);
		
		Print_Optimal_Parentheses(s, i, j, n);
		j = temp;
		
		temp = i;
		i = *((s + i * n) + j) + 1;
		Print_Optimal_Parentheses(s, i, j, n);
		
		cout << ")";
	}
}

void Matrix_Chain_Order(int p[], int& n){
	int m[n][n], s[n][n];
	
	int i, l, k;
	
	i = 1;
	
	while(i < n){
		m[i][i] = 0;
		i++;
	}
	
	l = 2;
	
	while (l < n) {
		
		i = 1;
		
		while(i < n - l + 1){
			
			int j = l + i - 1;
			m[i][j] = 2147483647;
			
			k = i;
			
			while(k < j){
				
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
				k++;
			}
			i++;
		}
		l++;
	}
	cout << m[1][n - 1];
	cout << "\n";
	
	i = 1;
	int j = n - 1;
	
	Print_Optimal_Parentheses((int*)s, i, j, n);
	cout << "\n";
}

int main(){
	
	int arrSize;
	cin >> arrSize;
	
	arrSize = arrSize + 1;
	
	int p[arrSize];
	
	int i = 0;
	
	while (i != arrSize) {
		cin >> p[i];
		i++;
	}
	
	Matrix_Chain_Order(p, arrSize);
	
	return 0;
}
