#include<iostream>
using namespace std;
#define MAX 1000 //没有分号

int main(){  
    
    // 创建通讯录结构体变量
    // AddressBooks abs;
    // abs.m_size = 0;

    int select = 0; 
    while(true){
        //菜单调用
        // show_menu();
        cin >> select;
        switch (select)
        {
            case 1:
                /* 1.添加联系人 */
                // add_person(&abs);
                break;

            case 2:
                /* 2.显示联系人 */
                break;
            
            case 3:
                /* 3.删除联系人 */
                break;

            case 4:
                /* 4.查找联系人 */
                break;

            case 5:
                /* 5.修改联系人 */
                break;

            case 6:
                /* 6.清空联系人 */
                break;
            
            case 0:
                /* 0.退出通讯录 */
                cout << "欢迎下次使用!" << endl;
                return 0;
                
            default:
                cout << "请输入正确选择" << endl;
                break;
            }
    } 
    return 0;
}