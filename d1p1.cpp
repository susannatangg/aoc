#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

long long stringToLL(string s){
    long long l=0;
    int place=1;
    for (int i=s.length()-1; i>=0; i--){
        l += ((s[i]-'0')*place);
        place*=10;
    }
    return l;
}

int main(){
    string currNum;
    long long currSum=0;
    long long currMax=-1;
    ifstream input("d1p1input.txt");
    while(getline(input, currNum)){
        if(currNum==""){
            currMax=max(currMax,currSum);
            currSum=0;
            continue;
        }
        currSum+=stringToLL(currNum);
    }
    cout<<currMax<<endl;
}