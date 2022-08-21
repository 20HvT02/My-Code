#include<bits/stdc++.h>
using namespace std;
 
void daoNguocSo(string s) {
    int l = s.length();
    while(s[l-1] == '0') --l;
    for (int i = l-1; i>=0; i--) 
        cout << s[i];
}

int main(){
    string s;
    cin >> s;
    daoNguocSo(s);
    system("pause");
    return 0;
}