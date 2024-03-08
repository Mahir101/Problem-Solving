#include<iostream>
#include<vector>
#include<string>
using namespace std;

string removeDuplicates(string str) {
    int n = str.size();
    if(n <= 1) {
        return str;
    }
    int index = 1;
    for (int i = 1; i < n; i++) {
        if (str[i] != str[i - 1]) {
            str[index++] = str[i];
        }
    }
    return str.substr(0, index);
}

int main() {
    
    cout << removeDuplicates("sttrss");

    return 0;
}
