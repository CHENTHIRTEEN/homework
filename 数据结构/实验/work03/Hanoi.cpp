#include <iostream>
using namespace std;

int count = 0;//统计移动次数
void move(char A, int n, char C){
    cout << n << "号盘从" << A << "移动到" << C << endl;
    count++;
}

void Hanoi(int n, char A, char B, char C){
    if (n == 1)move(A, 1, C);
    else{
        Hanoi(n - 1, A, C, B);
        move(A, n, C);
        Hanoi(n - 1, B, A, C);
    }
}

int main()
{
    char A = 'A', B = 'B', C = 'C';
    Hanoi(3, A, B, C);
    cout << "共移动了" << count << "次" << endl;
}

