//
// Created by 10303 on 2021/11/30.
//

#ifndef WORK04_SQLIST_H
#define WORK04_SQLIST_H
#include <iostream>
#include <cstring>
using namespace std;
const int LIST_INIT_SIZE = 20;
const int LISTINCREMENT = 10;

template<typename T>
class SqList{
public:
    T *elem;
    int length;
    int listsize;
    // 构造方法
    SqList();
    ~SqList();
    // 顺序表的操作
    bool insert(SqList<T> *L, int index, T e);
    bool del(SqList<T> *L, int index, T& e);
};

template<typename T>
SqList<T>::SqList() {
    elem = new T[LIST_INIT_SIZE];
    length = 0;
    listsize = LIST_INIT_SIZE;
}


template<typename T>
SqList<T>::~SqList<T>() {
    delete [] elem;
}

template<typename T>
bool SqList<T>::insert(SqList<T> *L, int index, T e) {
    if(index < 1 || index > length + 1)return false;
    if (L->length > L->listsize){
        T* temp;
        temp = L->elem;
        L->elem = new T[LIST_INIT_SIZE + LISTINCREMENT];
        memcpy(L->elem, temp, sizeof(T)*L->listsize);
        delete [] temp;
        L->listsize += LISTINCREMENT;
    }
    T *q = &(L->elem[index - 1]);
    for (T* p = &(L->elem[L->length - 1]); p >= q ; p--) {
        *(p + 1) = *(p);
    }
    *q = e;
    L->length++;
    return true;
}

template<typename T>
T SqList<T>::del(SqList<T> *L, int index, T& e) {
    if(index < 1 || index > length + 1)
    {
        return false;
    }
    T* p = &(L->elem[index - 1]);
    e = *p;
    T* q = L->elem + L->length - 1;
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    L->length--;
    return e;
}
#endif //WORK04_SQLIST_H
