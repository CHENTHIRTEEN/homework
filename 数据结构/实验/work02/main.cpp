#include <iostream>
using namespace std;

template<typename T> struct ListNode{
    T data;
    struct ListNode<T> *next;
};

template<typename T>
class LinkList{
public:
    ListNode<T> *head;
    int _size;
    LinkList();
    bool insert(LinkList<T> *L, int i, T data);
    bool del(LinkList<T> *L, int i);
    void show(ListNode<T> *p);
    ~LinkList();
};

template<typename T>
LinkList<T>::LinkList()
{
    head = new ListNode<T>;
    head->next = nullptr;
    _size = 0;
}

template<typename T>
bool LinkList<T>::del(LinkList<T> *L, int i) {
    ListNode<T>* p = L->head;
    int j = 0;
    while (p->next && j < i - 1){
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1) return false;
    ListNode<T> *q = p->next;
    p->next = q->next;
    delete q;
    return true;
}

template<typename T>
bool LinkList<T>::insert(LinkList<T> *L, int i, T data) {
    ListNode<T> *p = L->head;
    int j = 0;
    while (p&&j < i - 1){
        p = p->next;
        j++;
    }
    if (!p||j > i - 1){
        cout << "插入失败" << endl;
        return false;
    }
    ListNode<T> *node = new ListNode<T>;
    node->data = data;
    node->next = p->next;
    p->next = node;
    return true;
}

template<typename T>
void LinkList<T>::show(ListNode<T> *p) {
    while (p){
        cout << p->data;
        p = p->next;
    }
}
template<typename T>
LinkList<T>::~LinkList<T>() {
    delete head;
}

//asdfghjkl
//lkjhgfdsa
int main() {
    LinkList<char> Link;
    LinkList<char> *L;
    L = &Link;
    while (1)
    {
        cout << "请输入要插入的元素，输入0结束:" << endl;
        char ch;
        cin >> ch;
        if (ch == '0')break;
        if (L->insert(L, 1, ch))
        {
            cout << "插入成功" << endl;
        } else{
            cout << "插入失败，请重试！" << endl;
        }
    }
    cout << "创建的链表："<< endl;
    L->show(L->head);
    cout << endl;
    cout << "请输入删除元素的位置：" << endl;
    int n;
    cin >> n;
    L->del(L, n);
    cout << "删除元素后的链表是:" << endl;
    L->show(L->head);
    cout << endl;
    // 编程实现两个有序表adfi和cefi的合并。
    LinkList<char> Link1;
    LinkList<char> Link2;
    LinkList<char> *L1;
    LinkList<char> *L2;
    L1 = &Link1;
    L2 = &Link2;
    L1->insert(L1, 1, 'i');L1->insert(L1, 1, 'f');
    L1->insert(L1, 1, 'd');L1->insert(L1, 1, 'a');
    L2->insert(L2, 1, 'i');L2->insert(L2, 1, 'f');
    L2->insert(L2, 1, 'e');L2->insert(L2, 1, 'c');
    cout << "合并两个链表：" << endl;
    L1->show(L1->head);
    cout << endl;
    L2->show(L2->head);
    ListNode<char> *head = new ListNode<char>;
    ListNode<char> *p = head;
    p->next = nullptr;
    ListNode<char> *p1 = L1->head->next;
    ListNode<char> *p2 = L2->head->next;
    while(p1 != nullptr && p2 != nullptr)
    {
        if(p1->data < p2->data)
        {
            p->next = p1;
            p1 = p1->next;
        }else{
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
       // cout << p->data << endl;
    }
    if(p1!=nullptr)
    {
        p->next = p1;
    }
    if(p2 != nullptr)
    {
        p->next = p2;
    }
    cout << "合并后的链表：" << endl;
    L->show(head);
    return 0;
}
