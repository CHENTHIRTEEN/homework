#include <iostream>
#include "Stack.h"
#include "express.h"
using namespace std;


int main() {
    auto *stack = new Stack<int>;
    SqStack<int> sqStack(stack);
    SqStack<int> *sq;
    while (1) {
        cout << "请输入一个十进制正整数:" << endl;
        int num;
        cin >> num;
        sq->conversion(stack, sq, num);
    }
//    int a = express();
//    cout << a << endl;
}
