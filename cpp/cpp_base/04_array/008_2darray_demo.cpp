#include<iostream>
using namespace std;

// 考试成绩统计

int main(){
    string names[3] = {"sun", "zhao", "qian"};

    int socres[3][3] = {
        {100, 100, 100},
        {90, 50, 100},
        {60, 70, 80}
    };

    for(int i =0; i< 3; i++){
        int sum_s = 0;
        for(int j =0; j< 3; j++){
            sum_s += socres[i][j];
        }
        cout << names[i] << "的成绩:" << sum_s << endl;
    }

    return 0;
}