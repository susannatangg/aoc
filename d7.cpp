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

long long total=0;
long long total2=0;
vector<long long> sums;

struct Node{
    long long size;
    string name;
    Node *parent;
    long long sum;
    vector<Node *> child;
};

Node *newNode(long long size, string name, Node *parent, long long sum){
    Node *n=new Node;
    n->size=size;
    n->name=name;
    n->parent=parent;
    n->sum=sum;
    return n;
}

int toInt(string s){
    int r=0;
    int place=1;
    for (int i=s.length()-1; i>=0; i--){
        r+=((s[i]-'0')*place);
        place*=10;
    }
    return r;
}

long long getSum (Node *root){
    if(root->size!=-1){
        total2+=root->size;
        return root->size;
    }
    int sum=0;
    for (int i=0; i<root->child.size(); i++){
        sum+=getSum(root->child[i]);
    }
    if(sum<=100000)total+=sum;
    sums.push_back(sum);
    return sum;
}

void part1(){
    string line;
    ifstream input("d7input.txt");
    Node *currNode=newNode(-1,"/",nullptr,0);
    getline(input,line);
    while(getline(input,line)){
        if(line[0]=='$' && line[2]=='c'){ //$ cd
            string cd=line.substr(5);
            if (cd==".."){ //$ cd ..
                currNode=currNode->parent;
            }else if(cd=="/"){ //$ cd /
                while(currNode->parent!=nullptr){
                    currNode=currNode->parent;
                }
            }else{ //$ cd x
                for (int i=0; i<currNode->child.size(); i++){
                    if(currNode->child[i]->size==-1 && currNode->child[i]->name==cd){
                        currNode=currNode->child[i];
                        break;
                    }
                }
            }
        }else if(line[0]=='d'){ //dir xyz
            string dir=line.substr(4);
            currNode->child.push_back(newNode(-1,dir,currNode,0));
        }else if(isdigit(line[0])){ //123 abc
            int space=line.find(' ');
            currNode->child.push_back(newNode(toInt(line.substr(0,space)), line.substr(space+1), currNode,0));
        }
    }
    while(currNode->parent!=nullptr){
        currNode=currNode->parent;
    }
    long long sdf=getSum(currNode);    
    // cout<<total<<endl;
    long long smallest=INT_MAX;
    for (int i=0; i<sums.size(); i++){
        if(70000000-total2+sums[i]>=30000000){
            smallest=min(smallest,sums[i]);
        }
    }
    cout<<smallest<<endl;
}

int main(){
    part1();
}