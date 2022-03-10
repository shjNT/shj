#include<iostream>
using namespace std;

//demo

struct Student
{
    string sname;
    int score;
};

struct Teacher 
{
    string name;
    struct Student stu_arr[5];
};



// 赋值函数
void gave_info(Teacher tea_arr[], int len){
    string nameseed = "ABCDE";
    for(int i=0; i< len; i++){
        tea_arr[i].name = "teacher_";
        tea_arr[i].name += nameseed[i];

            for(int j=0; j<5; j++){
                tea_arr[i].stu_arr[j].sname = "student_";
                tea_arr[i].stu_arr[j].sname += nameseed[j];

                //系统生成随机数
                int num = rand() % 41 + 60;     //生成40~100的随机数
                tea_arr[i].stu_arr[j].score = num;
            }

    }
};


// 打印函数
void print_info(Teacher tea_arr[], int len){
    for(int i=0; i<len; i++){
        cout << tea_arr[i].name << ": " << endl;
        for (int j=0; j< 5; j++){
            cout << "\t" << tea_arr[i].stu_arr[j].sname << "\t" 
            << tea_arr[i].stu_arr[j].score << endl;
        }
    }
}

int main(){

    //添加随机数种子，利用当前系统时间生成随机数 -->> 放在循环之外
    srand((unsigned int)time(NULL));

    // teacher数组
    Teacher tea_arr[3];
    
    // 赋值
    int len = sizeof(tea_arr) / sizeof(tea_arr[0]);
    gave_info(tea_arr, len);


    // 输出
    print_info(tea_arr, len);

    return 0;
}