#include <iostream>
using namespace std;

const int MAXN = 1001;
struct node{
    int row, col; // 非零元素的下标
    int value;
};typedef struct node NODE;

int transpose(NODE ma[], NODE mb[]){
    int i, j, k, num[MAXN], pos[MAXN];
    if(ma->value == 0)return 0;
    mb[0].row = ma[0].col;mb[0].col = ma[0].row;
    mb[0].value = ma[0].value;
    for (i = 0; i < ma[0].col; ++i) {
        num[i] = 0;
    }
    for (i = i; i <= ma[0].value; i++) {
        num[ma[i].col]++;
    }
    for(pos[0] = 1, i = 1; i < ma[0].col; i++)
        pos[i] = pos[i - 1] + num[i - 1];
    for(i = 1; i <= ma[0].value; i++)
    {
        j = ma[i].col;k = pos[j]; mb[k].row = ma[i].col;
        mb[k].col = ma[i].row;mb[k].value = ma[i].value;pos[j]++;
    }
    return 1;
}

int main() {
    NODE ma[MAXN], mb[MAXN];
    ma[0].row = 6;ma[0].col = 7; ma[0].value = 8;
    ma[1].row = 0;ma[1].col = 1; ma[1].value = 12;
    ma[2].row = 0;ma[2].col = 2; ma[2].value = 9;
    ma[3].row = 2;ma[3].col = 0; ma[3].value = -3;
    ma[4].row = 2;ma[4].col = 5; ma[4].value = 14;
    ma[5].row = 3;ma[5].col = 2; ma[5].value = 24;
    ma[6].row = 4;ma[6].col = 1; ma[6].value = 18;
    ma[7].row = 5;ma[7].col = 0; ma[7].value = 15;
    ma[8].row = 5;ma[8].col = 3; ma[8].value = -7;

    return 0;
}
