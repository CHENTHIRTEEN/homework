#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
struct node{
    int index;// 当前节点编号
    int value;// 当前节点的值
    struct node *next;//指向下一个节点的指针
};typedef struct node node;

// 初始化
node* init(node *l, int n){
    node *p;// 尾指针
    for (int i = 0; i < n; ++i) {
        int code;
        printf("请输入第%d个人的密码：\n", i + 1);
        scanf("%d", &code);
        node *q = (node*) malloc(sizeof (node));
        if(l == NULL){// 判断头节点是否为空
            l = q;l->index = i + 1;
            l->value = code;l->next = NULL;
            p = l;
            continue;
        }
        p->next = q;p = p->next;// 插入衔接点，操作顺序不可改变
        p->index = i + 1;p->value = code;
        p->next = NULL;
    }
    p->next = l;
    return l;
}

// 生成出列序列，用一个新的循环链表保存出列序列
node* pop(node *l, node *p, int m){
    int k = 1;
    node *q = (node*) malloc(sizeof (node));// 分配空间
    while (p->next != p){
        if((k + 1) % m == 0){// 判断是否符合出列条件
            if(l == NULL){
                q = p->next;p->next = p->next->next;
                p = p->next;l = q;
                q->next = l;k = q->value;
            } else{
                q->next = p->next;p->next = p->next->next;p = p->next;
                q = q->next;q->next = l;k = q->value;
            }
        } else{
            p = p->next;
            k++;
        }
    }
    q->next = p;// 当只剩下一个节点时候直接插入新链表
    q = q->next;
    q->next = l;
    return l;
}

int main() {
    int n;//总人数n
    int m;//初始报数上限值m
    printf("请输入总人数n：\n");
    scanf("%d", &n);
    node *head;// 头指针便于遍历操作
    head = NULL;
    head = init(head, n);
//    node *p = head;
//    do{
//        printf("%d \n", p->value);
//        p=p->next;
//    }while (p != head);
    printf("请输入初始报数上限值m：\n");
    scanf("%d", &m);
    node *h;
    h = NULL;
    h = pop(h, head, m);
    node *q = h;
    node *p = h;
    printf("出列顺序：\n");
    do{
        printf("%d ", p->index);
        p=p->next;
    }while (p != h);
    printf("\n生成密码：\n");
    do{
        printf("%d ", q->value);
        q = q->next;
    }while (q != h);
    return 0;
}

// 4 5 10
// 3 6 9 2 7 1 8 5 10 4