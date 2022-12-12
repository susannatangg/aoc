#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

vector<string> map;
int steps[1000][1000];
bool visited[1000][1000];
int ei,ej, minSteps=100000;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void bfs(int i,int j, int currSteps, char prev){
    if(i>=map.size() || i<0 || j>=map[0].length() || j<0 || map[i][j]-prev>1)return;
    if(i==ei && j==ej){
        minSteps=min(minSteps,currSteps);
        return;
    }
    if(visited[i][j] && currSteps>=steps[i][j])return;
    visited[i][j]=true;
    steps[i][j]=currSteps;
    for (int k=0; k<4; k++) bfs(i+dir[k][0],j+dir[k][1], currSteps+1, map[i][j]);
}

void part1(){
    string line;
    ifstream input("d12input.txt");
    int i=0;
    int si,sj;
    while(getline(input,line)){
        map.push_back(line);
        for (int j=0; j<line.length(); j++){
            if(line[j]=='S'){
                si=i;
                sj=j;
                map[i][j]='a';
            }else if(line[j]=='E'){
                ei=i;
                ej=j;
                map[i][j]='z';
            }
        }
        i++;
    }
    bfs(si,sj,0,'a');
    cout<<minSteps;
}

void bfs2(int i,int j, int currSteps, char prev){
    if(i>=map.size() || i<0 || j>=map[0].length() || j<0 || map[i][j]-prev>1)return;
    if(i==ei && j==ej){
        minSteps=min(minSteps,currSteps);
        return;
    }
    if(map[i][j]=='a'){currSteps=0;}
    if(visited[i][j] && currSteps>=steps[i][j])return;
    visited[i][j]=true;
    steps[i][j]=currSteps;
    for (int k=0; k<4; k++) bfs2(i+dir[k][0],j+dir[k][1], currSteps+1, map[i][j]);
}

void part2(){
    string line;
    ifstream input("d12input.txt");
    int i=0;
    int si,sj;
    while(getline(input,line)){
        map.push_back(line);
        for (int j=0; j<line.length(); j++){
            if(line[j]=='S'){
                si=i;
                sj=j;
                map[i][j]='a';
            }else if(line[j]=='E'){
                ei=i;
                ej=j;
                map[i][j]='z';
            }
        }
        i++;
    }
    bfs2(si,sj,0,'a');
    cout<<minSteps;
}

int main(){
    part2();
}