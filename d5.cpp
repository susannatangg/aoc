#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cstring>
#include <stack>
using namespace std;

int toInt(string s){
    int r=0;
    int place=1;
    for (int i=s.length()-1; i>=0; i--){
        r+=((s[i]-'0')*place);
        place*=10;
    }
    return r;
}

string toString(char c){
    string s="";
    return s+c;
}

void part1(){
    string line;
    ifstream input("d5input.txt");
    getline(input,line);
    int len=line.length();
    stack<char> stacks[len/4+1];
    int i=1;
    while(i<len){
        if(isupper(line[i])){
            stacks[i/4].push(line[i]);
        }
        i++;
    }
    while(getline(input,line) && line[1]!='1'){
        i=0;
        while(i<len){
            if(isupper(line[i])){
                stacks[i/4].push(line[i]);
            }
            i++;
        }
    }
    getline(input,line);
    for (i=0; i<len/4+1; i++){
        stack<char> s;
        while(!stacks[i].empty()){
            s.push(stacks[i].top());
            stacks[i].pop();
        }
        stacks[i]=s;
    }
    int data[3];
    int j=0;
    i=0;
    while(getline(input,line)){
        i=0;
        j=0;
        while(i<line.length()){
            if(isdigit(line[i])){
                if(i==line.length()-1 || line[i+1]==' ') data[j]=toInt(string(1,line[i]));
                else {
                    data[j]=toInt(string(1,line[i])+string(1,line[i+1]));
                    i++;
                }
                j++;
            }
            i++;
        }
        for (i=0; i<data[0]; i++){
            stacks[data[2]-1].push(stacks[data[1]-1].top());
            stacks[data[1]-1].pop();
        }
    }
    string final="";
    for (i=0; i<len/4+1; i++){
        final+=stacks[i].top();
    }
    cout<<final<<endl;
}

void part2(){
    string line;
    ifstream input("d5input.txt");
    getline(input,line);
    int len=line.length();
    stack<char> stacks[len/4+1];
    int i=1;
    while(i<len){
        if(isupper(line[i])){
            stacks[i/4].push(line[i]);
        }
        i++;
    }
    while(getline(input,line) && line[1]!='1'){
        i=0;
        while(i<len){
            if(isupper(line[i])){
                stacks[i/4].push(line[i]);
            }
            i++;
        }
    }
    getline(input,line);
    for (i=0; i<len/4+1; i++){
        stack<char> s;
        while(!stacks[i].empty()){
            s.push(stacks[i].top());
            stacks[i].pop();
        }
        stacks[i]=s;
    }
    int data[3];
    int j=0;
    i=0;
    while(getline(input,line)){
        i=0;
        j=0;
        while(i<line.length()){
            if(isdigit(line[i])){
                if(i==line.length()-1 || line[i+1]==' ') data[j]=toInt(string(1,line[i]));
                else {
                    data[j]=toInt(string(1,line[i])+string(1,line[i+1]));
                    i++;
                }
                j++;
            }
            i++;
        }
        stack<char> temp;
        for (i=0; i<data[0]; i++){
            temp.push(stacks[data[1]-1].top());
            stacks[data[1]-1].pop();
        }
        while(!temp.empty()){
            stacks[data[2]-1].push(temp.top());
            temp.pop();
        }
    }
    string final="";
    for (i=0; i<len/4+1; i++){
        final+=stacks[i].top();
    }
    cout<<final<<endl;
}

int main(){
    part2();
}
//xxxxxxxx[F]x[Q]xxxxxxxxx[Q]xxxxxxxx
//01234567890123456789012345678901234
//          1         2         3