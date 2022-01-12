//
// Created by 10303 on 2021/11/20.
//

#ifndef WORK03_EXPRESS_H
#define WORK03_EXPRESS_H
#include "Stack.h"

int Operate(char a, char op, char b){
    int x = int(a - '0');
    int y = int(b - '0');
    switch (op) {
        case '+':cout << x + y;return x + y;
        case '-':return x - y;
        case '*':return x * y;
        case '/':return x / y;
    }
}

int isOperator(char c){
    cout << "判断是否运算符" << endl;
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
        return 1;
    }else{
        return 0;
    }
}
char Preced(char c1, char c2)
{
    int c_temp1, c_temp2;
    switch (c1) {
        case '*':
        case '/': c_temp1 = 4;
            break;
        case '+':
        case '-': c_temp1 = 2; break;
        case '(': c_temp1 = 0; break;
        case ')': c_temp1 = 5; break;
        case '#': c_temp1 = -1; break;
    }
    switch (c2) {
        case '*':
        case '/': c_temp2 = 3;
            break;
        case '+':
        case '-': c_temp2 = 1; break;
        case '(': c_temp2 = 5; break;
        case ')': c_temp2 = 0; break;
        case '#': c_temp2 = -1; break;
    }
    if (c_temp1 < c_temp2) return('<');
    if (c_temp1 = c_temp2) return('=');
    if (c_temp1 > c_temp2) return('>');
}

int express() {
    auto *OPTR = new Stack<char>; // 存放运算符
    auto *OPND = new Stack<char>; // 存放数字
    SqStack<char> sqStack1(OPTR);
    SqStack<char> sqStack2(OPND);
    SqStack<char> *sq;
    sq->Push(OPTR, '#');
    cout << sq->GetTop(OPTR);
    cout << "请输入一个表达式" << endl;
    char w;
    cin >> w;
    cout << "w=:" << w << endl;
    while (w != '#' || sq->GetTop(OPTR) != '#') {
        if (!isOperator(w)) {
            sq->Push(OPND, w);// 是数字存入数字栈
            cin >> w;
            cout << "w=:" << w << endl;
            cout << sq->GetTop(OPND);
        } else {
            switch (Preced(sq->GetTop(OPTR), w)) {
                case '<':
                    sq->Push(OPTR, w);
                    cin >> w;
                    cout << "w=:" << w << endl;
                    break;
                case '=':
                    int u;
                    char x;
                    x = sq->Pop(OPTR, u);
                    cin >> w;
                    cout << "w=:" << w << endl;
                    break;
                case '>': //新输入的算符c优先级低，即栈顶算符优先权高，
                    //出栈并将运算结果入栈OPND
                    int n;
                    char op = sq->Pop(OPTR, n);
                    char b = sq->Pop(OPND, n);
                    char a = sq->Pop(OPND, n);
                    sq->Push(OPND, Operate(a, op, b));
                    break;
            }
        }
    }
    return sq->GetTop(OPND);
}
#endif //WORK03_EXPRESS_H
