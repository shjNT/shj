#include <iostream>
using namespace std;

// 函数模板案例 -> 选择排序


// 交换函数模板
template<typename T>
void my_swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

// 排序函数模板
template<typename T>
void my_sort(T arr[], int len)
{
    for (int i=0; i<len; i++)
    {
        int max = i;
        for (int j=i+1; j< len; j++)
        {
            if(arr[max] < arr[j])
            {
                max = j;
            }
        }
        if( max != i)
        {
            my_swap(arr[max], arr[i]);
            // T tmp = arr[max];
            // arr[max] = arr[i];
            // arr[i] = tmp;
        }
        
    }
}

// 打印函数模板
template<typename T>
void show_res(T arr[], int len)
{
    for(int i = 0; i< len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01()
{
    char char_arr[] = "badcfe";
    int len = sizeof(char_arr) / sizeof(char);
    my_sort(char_arr, len);
    show_res(char_arr, len);

}

void test02()
{
    int int_arr[] = {1, 4, 3, 5, 9, 7, 0, 2};
    int len = sizeof(int_arr) / sizeof(int);
    my_sort(int_arr, len);
    show_res(int_arr, len);

}

int main()
{
    test01();
    test02();
    return 0;
}