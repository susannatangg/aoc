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

void maxCalories(){
    string currNum;
    long long currSum=0;
    long long currMax=-1;
    ifstream input("d1input.txt");
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

void topThreeMaxCalories(){
    string currNum;
    long long currSum=0;
    vector<long long> v;
    ifstream input("d1input.txt");
    while(getline(input, currNum)){
        if(currNum==""){
            v.push_back(currSum);
            currSum=0;
            continue;
        }
        currSum+=stringToLL(currNum);
    }
    sort(v.begin(), v.end(), greater<int>());
    cout<<v[0]+v[1]+v[2]<<endl;
}

int main(){
    maxCalories();
    topThreeMaxCalories();
}