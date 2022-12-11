#include <iostream>
#include <unordered_set>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int x=1, cycle=0, signalStrength=0;

int toInt(string s){
    int r=0;
    int place=1;
    for (int i=s.length()-1; i>=0; i--){
        r+=((s[i]-'0')*place);
        place*=10;
    }
    return r;
}

void f(){
    cycle++;
    if(cycle==20 || (cycle>20 && (cycle-20)%40==0)){
        cout<<cycle*x<<" "<<x<<" "<<cycle<<endl;
        signalStrength+=(cycle*x);
    }
}

void part1(){
    string line;
    ifstream input("d10input.txt");
    while(getline(input,line) && cycle<225){
        if(line[0]=='a'){
            f();
            f();
            if(line[5]=='-') x+=(toInt(line.substr(6))*(-1));
            else x+=toInt(line.substr(5));
        }else f();
    }
    cout<<signalStrength<<endl;
}

void f2(){
    if(abs(x-(cycle%40))<=1) cout<<'#';
    else cout<<'.';
    cycle++;
    if(cycle%40==0 && cycle!=0) cout<<endl;
}

void part2(){
    string line;
    x=1;
    cycle=0;
    ifstream input("d10input.txt");
    while(getline(input,line)){
        if(line[0]=='a'){
            f2();
            f2();
            if(line[5]=='-') x+=(toInt(line.substr(6))*(-1));
            else x+=toInt(line.substr(5));
        }else f2();
    }
}

int main(){
    part2();
}