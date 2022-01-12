#include <iostream>
using namespace std;

const int MAXN = 10001;
int main()
{
    int n;
    int nums[MAXN];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < n - 1; i++) /* 外循环为排序趟数，len个数进行len-1趟 */
        for (int j = 0; j < n - 1 - i; j++) { /* 内循环为每趟比较的次数，第i趟比较len-i次 */
            if (nums[j] > nums[j + 1]) { /* 相邻元素比较，若逆序则交换（升序为左大于右，降序反之） */
                swap(nums[j], nums[j + 1]);
            }
        }
    cout << "排序后的数字：" << endl;
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
}

