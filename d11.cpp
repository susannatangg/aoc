#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
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

struct Monkey{
    queue<long long> items;
    char operation;
    int num;
    int divisible;
    int ifTrue;
    int ifFalse;
    long long inspected;
};

Monkey *newMonkey(queue<long long> items, char operation, int num, int divisible, int ifTrue, int ifFalse, long long inspected){
    Monkey *m=new Monkey;
    m->items=items;
    m->operation=operation;
    m->num=num;
    m->divisible=divisible;
    m->ifTrue=ifTrue;
    m->ifFalse=ifFalse;
    m->inspected=inspected;
    return m;
}

void part1(){
    string line;
    vector<Monkey *> monkeys;
    ifstream input("d11input.txt");
    queue<long long> currItems;
    Monkey *m=newMonkey(currItems,' ',0,0,0,0,0);
    while(getline(input,line)){
        if(line=="" || line[line.length()-1]==':')continue;
        else if(line[2]=='S'){
            m=newMonkey(currItems,' ',0,0,0,0,0);
            int i=0;
            int previ=18;
            while(previ+i<line.length()){ //might have problems
                while(previ+i<line.length() && line[previ+i]!=',')i++;
                m->items.push(toInt(line.substr(previ,i)));
                previ+=i+2;
                i=0;
            }
        }else if(line[2]=='O'){
            m->operation=line[23];
            if(isdigit(line[25]))m->num=toInt(line.substr(25));
            else m->num=-1;
        }else if(line[2]=='T'){
            m->divisible=toInt(line.substr(21));
        }else if(line[2]==' '){
            if(line[7]=='t'){
                m->ifTrue=toInt(line.substr(29));
            }else{
                m->ifFalse=toInt(line.substr(30));
                monkeys.push_back(m);
                while(!currItems.empty())currItems.pop();
            }
        }
    }
    for (int round=0; round<20; round++){
        for (int i=0; i<monkeys.size(); i++){
            while(!monkeys[i]->items.empty()){
                monkeys[i]->inspected++;
                int inspect=monkeys[i]->items.front();
                if(monkeys[i]->operation=='+'){
                    if(monkeys[i]->num==-1) inspect*=2;
                    else inspect+=monkeys[i]->num;
                }else {
                    if(monkeys[i]->num==-1) inspect*=inspect;
                    else inspect*=monkeys[i]->num;
                }
                inspect/=3;
                if(inspect%(monkeys[i]->divisible)==0){
                    monkeys[monkeys[i]->ifTrue]->items.push(inspect);
                }else{
                    monkeys[monkeys[i]->ifFalse]->items.push(inspect);
                }
                monkeys[i]->items.pop();
            }
        }
    }
    int most=-1,secondMost=-1;
    for (int i=0; i<monkeys.size(); i++){
        if(monkeys[i]->inspected>=most){
            secondMost=most;
            most=monkeys[i]->inspected;
        }
        else if(monkeys[i]->inspected>secondMost)secondMost=monkeys[i]->inspected;
    }
    cout<<most*secondMost<<endl;
}

void part2(){
string line;
    vector<Monkey *> monkeys;
    ifstream input("d11input.txt");
    queue<long long> currItems;
    Monkey *m=newMonkey(currItems,' ',0,0,0,0,0);
    while(getline(input,line)){
        if(line=="" || line[line.length()-1]==':')continue;
        else if(line[2]=='S'){
            m=newMonkey(currItems,' ',0,0,0,0,0);
            int i=0;
            int previ=18;
            while(previ+i<line.length()){ //might have problems
                while(previ+i<line.length() && line[previ+i]!=',')i++;
                m->items.push(toInt(line.substr(previ,i)));
                previ+=i+2;
                i=0;
            }
        }else if(line[2]=='O'){
            m->operation=line[23];
            if(isdigit(line[25]))m->num=toInt(line.substr(25));
            else m->num=-1;
        }else if(line[2]=='T'){
            m->divisible=toInt(line.substr(21));
        }else if(line[2]==' '){
            if(line[7]=='t'){
                m->ifTrue=toInt(line.substr(29));
            }else{
                m->ifFalse=toInt(line.substr(30));
                monkeys.push_back(m);
                while(!currItems.empty())currItems.pop();
            }
        }
    }
    long long mod=1;
    for (int i=0; i<monkeys.size(); i++){
        mod*=monkeys[i]->divisible;
    }
    for (int round=0; round<10000; round++){
        for (int i=0; i<monkeys.size(); i++){
            while(!monkeys[i]->items.empty()){
                monkeys[i]->inspected++;
                long long inspect=monkeys[i]->items.front();
                if(monkeys[i]->operation=='+'){
                    if(monkeys[i]->num==-1) inspect*=2;
                    else inspect+=monkeys[i]->num;
                }else {
                    if(monkeys[i]->num==-1) inspect*=inspect;
                    else inspect*=monkeys[i]->num;
                }
                inspect%=mod;
                if(inspect%(monkeys[i]->divisible)==0){
                    monkeys[monkeys[i]->ifTrue]->items.push(inspect);
                }else{
                    monkeys[monkeys[i]->ifFalse]->items.push(inspect);
                }
                monkeys[i]->items.pop();
            }
        }
    }
    long long most=-1,secondMost=-1;
    for (int i=0; i<monkeys.size(); i++){
        if(monkeys[i]->inspected>=most){
            secondMost=most;
            most=monkeys[i]->inspected;
        }
        else if(monkeys[i]->inspected>secondMost)secondMost=monkeys[i]->inspected;
    }
    cout<<most*secondMost<<endl;
}

int main(){
    part2();
}