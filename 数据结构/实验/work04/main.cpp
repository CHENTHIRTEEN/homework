#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<char>q;
    q.push('A');
    q.push('B');
    q.push('C');
    q.push('D');
    q.push('E');
    q.push('F');
    //asdfghjkl
    while (!q.empty())
    {
        cout << "元素：" << q.front() << "入队" << endl; // Output the 1st element
        q.pop();  // Delete the 1st element
    }
    cout << "队满！" << endl;
    return 0;
}
