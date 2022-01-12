#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int *buildNext(char* P){//模式串P的next表
    size_t m = strlen(P), j = 0;//主串指针
    int *N = new int[m];//next表
    int t = N[0] = -1;//模式串指针
    while(j < m - 1){
        if(0 > t || P[j] == P[t]){//匹配
            j++;
            t++;
//            N[j] = (P[j] != P[t] ? t : N[t]);
            N[j] = t;
        }else{
            t = N[t];
        }
    }
    return N;
}

int match(char *P, char *T){//KMP
    int *next = buildNext(P);//构造next表
    int n = (int) strlen(T), i = 0;//文本串指针
    int m = (int) strlen(P), j = 0;//模式串指针
    while(j < m && i < n){
        if (0 > j || T[i] == P[i]){
            i++;
            j++;
        } else{
            j = next[j];
        }
    }
    delete [] next;
    return i - j;
}

int main(){
    int index = match("abaabcac", "acabaabcaabaabcac");
    cout << index << endl;
    return 0;
}
