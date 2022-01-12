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
bool SqList<T>::del(SqList<T> *L, int index, T& e) {
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
    return true;
}

int main()
{
    // 1、编写函数创建一张空的顺序表L，将ajcniydu存储到顺序表中。
    SqList<char> sqList;
    SqList<char> *L;
    L = &sqList;
    while (1)
    {
        cout << "请输入要插入的元素，输入0结束:" << endl;
        char ch;
        cin >> ch;
        if (ch == '0')break;
        if (L->insert(L, L->length + 1, ch))
        {
            cout << "插入成功" << endl;
        } else{
            cout << "插入失败，请重试！" << endl;
        }
    }
    cout << "创建完成的顺序表：" << endl;
    for (int i = 0; L->elem[i] != 0; ++i) {
        cout << L->elem[i] << " ";
    }
    cout << endl;
    // 2、编程实现：在顺序表ajcniydu的第三个位置插入p。
    cout << "请输入要插入的元素位置和值，用空格隔开：" << endl;
    int index;
    char e;
    cin >> index >> e;
    L->insert(L, index, e);
    cout << "插入p后的顺序表：" << endl;
    for (int i = 0; L->elem[i] != 0; ++i) {
        cout << L->elem[i] << " ";
    }
    cout << endl;

    // 3、编程实现：删除顺序表ajcniydu第三个位置的元素。
    SqList<char> sqList2;
    SqList<char> *L2;
    L2 = &sqList2;
    while (1)
    {
        cout << "请输入要插入的元素，输入0结束:" << endl;
        char ch;
        cin >> ch;
        if (ch == '0')break;
        if (L2->insert(L2, L2->length + 1, ch))
        {
            cout << "插入成功" << endl;
        } else{
            cout << "插入失败，请重试！" << endl;
        }
    }
    cout << "创建完成的顺序表：" << endl;
    for (int i = 0; L2->elem[i] != 0; ++i) {
        cout << L2->elem[i] << " ";
    }
    cout << endl;
    cout << "请输入要删除的元素位置：" << endl;
    cin >> index;
    L2->del(L2, index, e);
    cout << "删除的元素是：" << e << endl;
    cout << "插入第" << index << "个元素后的顺序表：" << endl;
    for (int i = 0; L2->elem[i] != 0; ++i) {
        cout << L2->elem[i] << " ";
    }
    cout << endl;

    // 编程实现将顺序表1、3、5、7、9和2、3、6合并，合并后的表为非递减的顺序。
    // 顺序表的创建
    SqList<int> nums1;SqList<int> nums2;SqList<int> nums3;
    SqList<int>* p1;SqList<int>* p2;SqList<int>* p3;
    p1 = &nums1;p2 = &nums2;p3 = &nums3;
    while (1)
    {
        cout << "请输入要插入表1的元素，输入-1结束:" << endl;
        int num;
        cin >> num;
        if (num == -1)break;
        if (p1->insert(p1, p1->length + 1, num))
        {
            cout << "插入成功" << endl;
        } else{
            cout << "插入失败，请重试！" << endl;
        }
    }
    cout << "创建完成的顺序表：" << endl;
    for (int i = 0; p1->elem[i] != 0; ++i) {
        cout << p1->elem[i] << " ";
    }
    cout << endl;

    while (1)
    {
        cout << "请输入要插入表2的元素，输入-1结束:" << endl;
        int num;
        cin >> num;
        if (num == -1)break;
        if (p2->insert(p2, p2->length + 1, num))
        {
            cout << "插入成功" << endl;
        } else{
            cout << "插入失败，请重试！" << endl;
        }
    }
    cout << "创建完成的顺序表：" << endl;
    for (int i = 0; p2->elem[i] != 0; ++i) {
        cout << p2->elem[i] << " ";
    }
    cout << endl;

    // 顺序表排序合并
    // 定义新的空顺序表存放元素
    int i = 0, j = 0;
    while(i < p1->length || j < p2->length)
    {
        if (p1->elem[i] < p2->elem[j])
        {
            p3->insert(p3, p3->length + 1, p1->elem[i]);
            i++;
        }else{
            if(p1->elem[i] != 0 && p2->elem[j] != 0){
                p3->insert(p3, p3->length + 1, p2->elem[j]);
                j++;
            }
            if (p1->elem[i] > p2->elem[j] && p2->elem[j] == 0)
            {
                p3->insert(p3, p3->length + 1, p1->elem[i]);
                i++;
            }
            if (p1->elem[i] < p2->elem[j] && p1->elem[i] == 0)
            {
                p3->insert(p3, p3->length + 1, p2->elem[j]);
                j++;
            }
        }
    }
    cout << "合并后的顺序表为:" << endl;
    for (int k = 0; k < p3->length; ++k) {
        cout << p3->elem[k] << " " ;
    }
    return 0;
}

