#include <iostream>
using namespace std;

struct node{
    int row, col, val;
    struct node *down, *right;
};
typedef struct node NODE;
NODE *create(){
    NODE *head, *new_p, *pre, *p, *row_p, *col_p;
    int i, count;
    head = (NODE *) malloc(sizeof(NODE));
    cin >> head->row >> head->col >> head->val;
    for(pre = head, i = 0; i < head->row; i++)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->val = p->row = p->col = 0;
        p->right = p;pre->down = p; pre = p;
    }
    p->right = head;
    count=0;
    while(count<head->val)
    { count++; new_p=(NODE *)malloc(sizeof(NODE));
        scanf("%d,%d,%d\n",&new_p->row,&new_p->col,&new_p->val);
        for(row_p=head,i=0;i<=new_p->row;i++)
        row_p=row_p->down;p=row_p;
        while(p->right!=row_p&&p->right->col<new_p->col)
        p=p->right;
        new_p->right=p->right;p->right=new_p;
        for(col_p=head,i=0;i<=new_p->col;i++)
        col_p=col_p->right;p=col_p;
        while(p->down!=col_p&&p->down->row<new_p->row)
        p=p->down;
        new_p->down=p->down;p->down=new_p;
    }
    return(head);
}
int main()
{

}