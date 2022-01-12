#include <iostream>
#include <vector>
//#define LIST_INIT_SIZE 100
//#define LISTINCREMENT 10
using namespace std;
template<typename T> class SqList{
private:
    SqList<T> *L;
public:
    vector<T> elems;
    vector<T> *p;
    int length;
//    int listsize;
    // 构造函数
    SqList();
    // 内联函数
    ~SqList();
    // 顺序表的基本方法
    // 插入数据
    bool Insert(SqList<T> *L, int index, T elem);

};
template<typename T>
SqList<T>::~SqList<T>() {

}

// 构造方法初始化顺序表
template<typename T>
SqList<T>::SqList(){
//    vector<T> elems(LIST_INIT_SIZE * sizeof(T));
    vector<T> elems;
//    vector<T> *p;
    length = 0;
//    listsize = LIST_INIT_SIZE;
    cout << "OK" << endl;
}

// 向顺序表中插入元素
template<typename T>
bool SqList<T>::Insert(SqList<T> *L, int index, T e) {
    if (L->elems.size() == 0)
    {
        L->elems.push_back(e);
        L->length++;
        return true;
    }
    if (index < 1 || index > L->length + 1)
    {
        return false;
    }
//    vector<T> *q;
//    q = &(L->elems[index]);
    typename vector<T>::iterator it = L->elems.end();
    for (int i = 0; i < ; ++i) {
        
    }
}

int main() {
    SqList<char> sqList;
    SqList<char> *L;
    L = &sqList;
//    L->elems.push_back('h');
//    cout << L->elems[0];
    // 将ajcniydu存储到顺序表中
    while(1)
    {
        char ch;
        cout << "请输入要插入的元素，输入0结束：" << endl;
        cin >> ch;
        if(ch == '0')
        {
            break;
        }
        if (L->Insert(L, L->length, ch))
        {
            cout << "插入成功" << endl;
        } else{
            cout << "插入失败，请重试！" << endl;
        }
//        cout << L->p << endl;
    }
}


