#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cstring>
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

void part1(){
    string line;
    int count=0,i=0,j=0;
    int nums[4];
    string curr="";
    ifstream input("d4input.txt");
    while(getline(input, line)){
        while(i<line.length()){
            while(isdigit(line[i])){
                curr+=line[i];
                i++;
            }
            nums[j]=toInt(curr);
            curr="";
            j++;
            i++;
        }
        j=0;
        i=0;
        if((nums[2]>=nums[0] && nums[3]<=nums[1]) ||
            (nums[0]>=nums[2] && nums[1]<=nums[3])) count++;

    }
    cout<<count<<endl;
}

void part2(){
    string line;
    int count=0,i=0,j=0;
    int nums[4];
    string curr="";
    ifstream input("d4input.txt");
    while(getline(input, line)){
        while(i<line.length()){
            while(isdigit(line[i])){
                curr+=line[i];
                i++;
            }
            nums[j]=toInt(curr);
            curr="";
            j++;
            i++;
        }
        j=0;
        i=0;
        if((nums[0]>=nums[2] && nums[0]<=nums[3]) ||
            (nums[1]>=nums[2] && nums[1]<=nums[3]) ||
            (nums[2]>=nums[0] && nums[2]<=nums[1]) ||
            (nums[3]>=nums[0] && nums[3]<=nums[1])) count++;

    }
    cout<<count<<endl;
}

int main(){
    part2();
}