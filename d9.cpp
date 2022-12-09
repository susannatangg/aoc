#include <iostream>
#include <unordered_set>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
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

bool inRange(int ti, int tj, int hi, int hj){
    return (abs(hi-ti)<=1 && abs(hj-tj)<=1);
}

void part1(){
    string line;
    unordered_set <string> us;
    us.insert("0,0");
    int ti=0,tj=0,hi=0,hj=0;
    char dir;
    int move;
    ifstream input("d9input.txt");
    while(getline(input, line)){
        dir=line[0];
        move=toInt(line.substr(2));
        for (int i=0; i<move; i++){
            if(dir=='R')hj++;
            if(dir=='L')hj--;
            if(dir=='U')hi--;
            if(dir=='D')hi++;
            if(!inRange(ti,tj,hi,hj)){
                if(hi==ti){
                    if(tj<hj)tj++;
                    else tj--;
                }else if(hj==tj){
                    if(ti<hi)ti++;
                    else ti--;
                }else{
                    if(inRange(ti-1,tj-1,hi,hj)){
                        ti--; tj--;
                    }else if(inRange(ti-1,tj+1,hi,hj)){
                        ti--; tj++;
                    }else if(inRange(ti+1,tj+1,hi,hj)){
                        ti++; tj++;
                    }else if(inRange(ti+1,tj-1,hi,hj)){
                        ti++; tj--;
                    }
                }
            }
            string tjs(1,tj);
            string tis(1,ti);
            us.insert(tis+","+tjs);
            // cout<<i+1<<" hi:"<<hi<<",hj:"<<hj<<",ti:"<<ti<<",tj:"<<tj<<endl;
        }
    }
    cout<<us.size()-1<<endl;
}

void part2(){
    
}

int main(){
    part1();
}