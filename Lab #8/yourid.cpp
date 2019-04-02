#include <iostream>

using namespace std;

void Print_Optimal_Parentheses(int* s, int i, int j, int n){
    if(i == j){
        cout << "A" << i - 1;
        return;
    }
    else{
        cout << "(";
        Print_Optimal_Parentheses(s, i, *((s + i * n) + j), n);
        Print_Optimal_Parentheses(s, *((s + i * n) + j) + 1, j, n);
        cout << ")";
    }
}

void Matrix_Chain_Order(int p[], int n){
    int m[n][n], s[n][n];
    
    for(int i = 1; i < n; i++){
        m[i][i] = 0;
    }
    
    for(int l = 2; l < n; l++){
        
        for(int i = 1; i < n - l + 1; i++){
            
            int j = l + i - 1;
            m[i][j] = 2147483647;
            
            for(int k = i; k < j; k++){
                
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][n - 1] << endl;
    Print_Optimal_Parentheses((int*)s, 1, n - 1, n);
    cout << endl;
}

int main(){
    
    int arrSize;
    cin >> arrSize;
    
    int p[arrSize + 1];
    
    for(int i = 0; i < arrSize + 1; i++){
        cin >> p[i];
    }
    
    Matrix_Chain_Order(p, arrSize + 1);
    
    return 0;
}
