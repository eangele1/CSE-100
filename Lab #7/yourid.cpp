#include <iostream>

using namespace std;

int Cut_Rod(int p[], int rods[], int n, int& numOfRodsUsed){
    
    int r[n + 1], s[n + 1];
    
    r[0] = 0;
    
    int i, j;
    
    for (i = 1; i <= n; i++) {
        int q = INT_MIN;
        int currRodLength = -1;
        
        for (j = 0; j < i; j++) {
            if (q < p[j] + r[i - j - 1]) {
                q = p[j] + r[i - j - 1];
                currRodLength = j;
            }
            r[i] = q;
            s[i] = currRodLength + 1;
        }
    }
    
    i = n;
    j = 0;
    
    while(i > 0){
        rods[j++] = s[i];
        i -= s[i];
    }
    
    numOfRodsUsed = j;
    
    return r[n];
}

int main(){
    
    int arrSize;
    
    cin >> arrSize;
    int p[arrSize];
    
    for (int i = 0; i < arrSize; i++) {
        cin >> p[i];
    }
    
    int rods[arrSize + 1];
    
    int numOfRodsUsed = 0;
    
    cout << Cut_Rod(p, rods, arrSize, numOfRodsUsed) << "\n";
    cout << rods[0];

    for (int i = 1; i < numOfRodsUsed; i++) {
        cout << " " << rods[i];
    }
    cout << " -1\n";
    
    return 0;
}
