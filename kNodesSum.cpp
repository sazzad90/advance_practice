// solution approach: basic(dont think anything about tree or stack)
// update level for '(' and ')' accordingly
// when level == k add upcoming number to result
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int k;
    string str;
    cin >> k >> str;
    
    int level = -1, result = 0;
    
    int i = 0, length = str.length();
    string temp = "";
    while(i < length){
        if(str[i] == '('){
            level++;
            if(temp != ""){
                result += stoi(temp);
                temp = "";
            }
        }else if(str[i] == ')'){
            level--;
            if(temp != ""){
                result += stoi(temp);
                temp = "";
            }            
        }else if(level == k){
            temp += str[i];
        }
        i++;
    }
    
    cout << result;
    return 0;
}
