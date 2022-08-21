#include<bits/stdc++.h>
using namespace std;

void swap(int a, int b) {
    int temp;
    if(a > b) {
        temp = a;
        a = b;
        b = temp;
    }
}
    
int main() {
    int m, n, x;
    cin >> m >> n >> x;
    int a[m][n];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    int temp;
    for (int j = (n-1); j >= 0; j--) {
        for(int i = 1; i <= j; i++)
            swap(a[x][i-1], a[x][i]);
    }
        
    for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
        
    system("pause");
    return 0;
}