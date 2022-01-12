//
// Created by 10303 on 2021/11/20.
//

#ifndef WORK03_STACK_H
#define WORK03_STACK_H
#include <iostream>
using namespace std;

const int MAXSIZE = 100;
template<typename T>
struct Stack{
    T *base;
    T *top;
    int stacksize;
};

template<typename T>
class SqStack{
public:
    SqStack();
    SqStack(Stack<T> *s);
    bool Push(Stack<T> *s, T e);
    T Pop(Stack<T> *s, T e);
    bool isEmpty(Stack<T> *s);
    T GetTop(Stack<T> *s);
    void conversion(Stack<T> *s, SqStack<T> *sq, T e);
    ~SqStack();
};

template<typename T>
bool SqStack<T>::isEmpty(Stack<T> *s) {
    if (s->base == s->top)return true;
    else return false;
}

template<typename T>
SqStack<T>::SqStack() {

}

template<typename T>
SqStack<T>::SqStack(Stack<T> *s) {
    s->base = new T[MAXSIZE];
    if (!s->base)exit(0);
    s->top = s->base;
    s->stacksize = MAXSIZE;
}

template<typename T>
bool SqStack<T>::Push(Stack<T> *s, T e) {
    if (s->top - s->base == s->stacksize)return false;
    *s->top++ = e;
    return true;
}

template<typename T>
T SqStack<T>::GetTop(Stack<T> *s) {
    if (s->base != s->top)
        return *(s->top - 1);
}

template<typename T>
T SqStack<T>::Pop(Stack<T> *s, T e) {
    if (s->top == s->base)return false;
    e = *--s->top;
    return e;
}

template<typename T>
void SqStack<T>::conversion(Stack<T> *s, SqStack<T> *sq, T e) {
    cout << "十位数" << e << "转换为8位数是:" << endl;
    while(e!=0) { // x不等于零循环 push(s, x% 8); // x/8第一个余数进栈
        sq->Push(s, e % 8);
        e = e / 8; //整除运算
    }
    while(!sq->isEmpty(s)) //输出存放在栈中的八制数位
    {
        e = sq->Pop(s, e);
        cout << e;
    }
    cout << endl;
}

template<typename T>
SqStack<T>::~SqStack<T>() {

}
#endif //WORK03_STACK_H
