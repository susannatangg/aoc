#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cstring>
using namespace std;

int getValue(char c){
    if(isupper(c)){
        return c-'A'+27;
    }else{
        return c-'a'+1;
    }
}

void part1(){
    string line;
    int total=0;
    unordered_set<int> items;
    ifstream input("d3input.txt");
    while(getline(input, line)){
        for (int i=0; i<line.length()/2; i++){
            items.insert(getValue(line[i]));
        }
        for (int i=line.length()/2; i<line.length(); i++){
            if(items.find(getValue(line[i]))!=items.end()){
                total+=getValue(line[i]);
                i=line.length();
            }
        }
        items.clear();
    }
    cout<<total<<endl;
}

void part2(){
    string line;
    int total=0;
    unordered_set<int> items1;
    unordered_set<int> items12;
    ifstream input("d3input.txt");
    int j=0;
    while(getline(input, line)){
        if(j==0){
            for (int i=0; i<line.length(); i++){
                items1.insert(getValue(line[i]));
            }
            j++;
        }else if(j==1){
            for (int i=0; i<line.length(); i++){
                if(items1.find(getValue(line[i]))!=items1.end()){
                    items12.insert(getValue(line[i]));
                }
            }
            j++;
        }else{
            for (int i=0; i<line.length(); i++){
                if(items12.find(getValue(line[i]))!=items12.end()){
                    total+=getValue(line[i]);
                    i=line.length();
                    items1.clear();
                    items12.clear();
                    j=0;
                }
            }
        }
    }
    cout<<total<<endl;
}

int main(){
    part2();
}