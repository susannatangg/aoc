#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

void part1(){
    string line;
    ifstream input("d6input.txt");
    getline(input,line);
    queue<char> q,temp;
    char compare[4];
    for (int i=0; i<4; i++) q.push(line[i]);
    for (int k=4; k<line.length(); k++){
        for (int i=0; i<4; i++){
            temp.push(q.front());
            compare[i]=q.front();
            q.pop();
        }
        for (int i=0; i<4; i++){
            q.push(temp.front());
            temp.pop();
        }
        bool found=true;
        for (int i=0; i<4; i++){
            for (int j=1; j<4; j++){
                if(i!=j && compare[i]==compare[j]){
                    found=false;
                }
            }
        }
        if(found){
            cout<<k<<endl;
            return;
        }
        q.pop();
        q.push(line[k]);
    }
}

void part2(){
    string line;
    ifstream input("d6input.txt");
    getline(input,line);
    queue<char> q,temp;
    char compare[14];
    for (int i=0; i<14; i++) q.push(line[i]);
    for (int k=14; k<line.length(); k++){
        for (int i=0; i<14; i++){
            temp.push(q.front());
            compare[i]=q.front();
            q.pop();
        }
        for (int i=0; i<14; i++){
            q.push(temp.front());
            temp.pop();
        }
        bool found=true;
        for (int i=0; i<14; i++){
            for (int j=1; j<14; j++){
                if(i!=j && compare[i]==compare[j]){
                    found=false;
                }
            }
        }
        if(found){
            cout<<k<<endl;
            return;
        }
        q.pop();
        q.push(line[k]);
    }
}

int main(){
    part2();
}