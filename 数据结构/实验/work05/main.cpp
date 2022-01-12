#include <iostream>
#include <cstring>
using namespace std;

int match(char *P, char *T){
    size_t n = strlen(T), i = 0;// 文本串长度、与模式串首字符的对齐位置
    size_t m = strlen(P), j = 0;// 模式串长度、当前接受对比字符位置
    while(j < m && i < n){
        cout << "T[i]:" << T[i] << " P[j]" << P[j] << endl;
        if(T[i] == P[j]){
            i++; j++;
        } else{
            i -= j - 1;
            j = 0;
        }
    }
    return (i - j);//返回子串位置
}

//源串acabaabcaabaabcac，模式串abaabcac，编程实现BF法模式匹配
int main() {
    int index = match("abaabcac", "acabaabcaabaabcac");
    cout << index << endl;
    return 0;
}
