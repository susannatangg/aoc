#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int value(char c){
    if(c=='A' || c=='X')return 1; //rock
    if(c=='B' || c=='Y')return 2; //paper
    if(c=='C' || c=='Z')return 3; //scissors
    return 0;
    //paper>rock 
    //scissors>paper
    //rock>scissors
}

int resultValue(char c){
    if(c=='X')return 0;
    if(c=='Y')return 3;
    if(c=='Z')return 6;
    return 0;
}

void part1(){
    string line;
    int score=0;
    int elf,you;
    ifstream input("d2input.txt");
    while(getline(input, line)){
        elf=value(line[0]);
        you=value(line[2]);
        score+=you;
        if(elf-you==0)score+=3;
        else if((elf-you==2 || elf-you<0) && elf-you!=-2)score+=6;
    }
    cout<<score<<endl;
}

void part2(){
    string line;
    int score=0;
    int elf,result;
    ifstream input("d2input.txt");
    while(getline(input, line)){
        elf=value(line[0]);
        result=resultValue(line[2]);
        score+=result;
        if(result==0){
            if(elf==1)score+=3;
            else score+=elf-1;
        }else if(result==6){
            if(elf==3)score+=1;
            else score+=elf+1;
        }else score+=elf;
    }
    cout<<score<<endl;
}

int main(){
    part2();
}