#include <iostream>
#include <cmath>
using namespace std;

struct Stu{
    int number;
    double scores[5];
};

void init(Stu stu[]){
    for (int i = 0; i < 10; ++i) {
        stu[i].number = i + 1;
        cout << "请输入学生" << stu[i].number <<"的成绩，用空格隔开："<< endl;
        for (int j = 0; j < 5; ++j) {
            cin >> stu[i].scores[j];
        }
    }
}

template<typename T>
T avg_stu(Stu stu[]){
    for (int i = 0; i < 10; ++i) {
        T sum = 0;
        for (int j = 0; j < 5; ++j) {
            sum += stu[i].scores[j];
        }
        cout << "学生" << stu[i].number << "的平均成绩是：" << sum / 5 << " ";
    }
}

template<typename T>
T avg_score(Stu stu[]){
    for (int i = 0; i < 10; ++i) {
        T sum = 0;
        for (int j = 0; j < 5; ++j) {
            sum += stu[j].scores[i];
        }
        cout << "课程" << i + 1 << "的平均成绩是：" << sum / 10 << " ";
    }
}

template<typename T>
T max_score(Stu stu[]){
    int a = 0, b = 0;
    for (int i = 0; i < 10; ++i) {
        T max = 0;
        for (int j = 0; j < 5; ++j) {
            if(max < stu[i].scores[j])
            {
                max = stu[i].scores[j];
                a = i;
                b = j;
            }
        }
    }
    cout << "最高分是学生" << stu[a].number << "的课程:" << b << " 成绩是:" << stu[a].scores[b] << endl;
}

template<typename T>
double var(Stu stu[]){
    T sum = 0;
    T sum2 = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            sum += stu[j].scores[i];
            sum2 += pow(stu[j].scores[i], 2);
        }
    }
    cout << "总成绩分方差是：" << sum2 / 50 - pow(sum / 50, 2) << endl;
}

int main() {
    struct Stu stu[10];
    init(stu);
    avg_stu<double>(stu);
    cout << endl;
    avg_score<double>(stu);
    cout << endl;
    max_score<double>(stu);
    cout << endl;
    var<double>(stu);
    return 0;
}
