#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool isVisible(vector<string> map, int i, int j){
    int val=map[i][j]-'0';
    int tempi=i+1;
    bool right=true, left=true, up=true, down=true;
    while(tempi<map[0].length()){ //right
        if(map[tempi][j]-'0'>=val){
            right=false;
            break;
        }
        tempi++;
    }
    tempi=i-1;
    while(tempi>=0){ //left
        if(map[tempi][j]-'0'>=val){
            left=false;
            break;
        }
        tempi--;
    }
    int tempj=j+1;
    while(tempj<map.size()){ //down
        if(map[i][tempj]-'0'>=val){
            down=false;
            break;
        }
        tempj++;
    }
    tempj=j-1;
    while(tempj>=0){ //down
        if(map[i][tempj]-'0'>=val){
            up=false;
            break;
        }
        tempj--;
    }
    return (right || left || down || up);
}

void part1(){
    string line;
    vector<string> map;
    ifstream input("d8input.txt");
    while(getline(input, line)){
        map.push_back(line);
    }
    int visible=(map.size()*2)+((map[0].size()-2)*2);
    for (int i=1; i<map.size()-1; i++){
        for (int j=1; j<map[0].length()-1; j++){
            if(isVisible(map,i,j))visible++;
        }
    }
    cout<<visible<<endl;
}

int scenicScore(vector<string> map, int i, int j){
    int val=map[i][j]-'0';
    int tempi=i+1;
    int scenicScore=1;
    while(tempi<map[0].length()){ //right
        if(tempi+1==map[0].length() && map[tempi][j]-'0'<val){
            scenicScore=map[0].length()-i-1;
            break;
        }
        if(map[tempi][j]-'0'>=val){
            scenicScore=tempi-i;
            break;
        }
        tempi++;
    }
    tempi=i-1;
    while(tempi>=0){ //left
        if(tempi-1==-1 && map[0][j]-'0'<val){
            scenicScore*=i;
            break;
        }
        if(map[tempi][j]-'0'>=val){
            scenicScore*=(i-tempi);
            break;
        }
        tempi--;
    }
    int tempj=j+1;
    while(tempj<map.size()){ //down
        if(tempj+1==map.size() && map[i][tempj]-'0'<val){
            scenicScore*=map.size()-j-1;
            break;
        }
        if(map[i][tempj]-'0'>=val){
            scenicScore*=(tempj-j);
            break;
        }
        tempj++;
    }
    tempj=j-1;
    while(tempj>=0){ //down
        if(tempj-1==-1 && map[i][tempj]-'0'<val){
            scenicScore*=j;
            break;
        }
        if(map[i][tempj]-'0'>=val){
            scenicScore*=(j-tempj);
            break;
        }
        tempj--;
    }
    return scenicScore;
}

void part2(){
    string line;
    vector<string> map;
    ifstream input("d8input.txt");
    while(getline(input, line)){
        map.push_back(line);
    }
    int maxScore=-1;
    for (int i=1; i<map.size()-1; i++){
        for (int j=1; j<map[0].length()-1; j++){
            maxScore=max(maxScore, scenicScore(map,i,j));
        }
    }
    cout<<maxScore<<endl;
}

int main(){
    part2();
}