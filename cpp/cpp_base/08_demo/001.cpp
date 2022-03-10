#include<iostream>
using namespace std;
#define MAX 1000 //没有分号


// 显示菜单函数
void show_menu(){
    cout << "************************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "************************" << endl;

};

// 联系人结构体
struct Person
{
    string m_name;
    int m_gender;
    int m_age;
    string m_phone;
    string m_addr;
};

// 通讯录结构体
struct AddressBooks
{
    struct Person arr[MAX]; //联系人结构体变量数组
    int m_size; //当前人数
};

// 添加联系人
void add_person(AddressBooks * abs)
{
    //判断通讯录容量
    if(abs -> m_size == MAX){
        cout << "通讯录已满，无法添加" << endl;
    }
    else{

        // ①姓名
        string name;
        cout << "请输入姓名:" << endl;
        cin >> name;
        abs -> arr[abs->m_size].m_name = name; 

        // ②性别
        int gender = 0;
        cout << "请输入性别: 1 -- 男\t 2 -- 女" << endl;
        while(true){
            cin >> gender;
            if(gender == 1 || gender == 2){
                abs -> arr[abs->m_size].m_gender = gender;
                break;
            }
            else{
                cout << "请输入正确性别" << endl;
            }
        };

        // ③年龄
        int age = 0;
        cout << "请输入年龄:" << endl;
        cin >> age;
        abs -> arr[abs->m_size].m_age = age; 
        

        // ④电话
        string phone;
        cout << "请输入联系电话:" << endl;
        cin >> phone;
        abs -> arr[abs->m_size].m_phone= phone; 
        

        // ⑤住址
        string addr;
        cout << "请输入家庭住址:" << endl;
        cin >> addr;
        abs -> arr[abs->m_size].m_addr= addr; 

        //更新size
        abs -> m_size ++;

        cout << "添加成功" << endl;
        system("read");
        system("clear");
        }     
};

// 显示联系人
void show_person(AddressBooks *abs){
    if(abs->m_size == 0){
        cout << "当前通讯录为空" << endl;
    }
    else{
        for(int i=0; i<abs->m_size; i++){
            cout << "姓名:" << abs ->arr[i].m_name << ";  ";
            cout << "性别:" << (abs ->arr[i].m_gender == 1 ? "男": "女")<< ";  ";
            cout << "年龄:" << abs ->arr[i].m_age << ";  ";
            cout << "电话:" << abs ->arr[i].m_phone << ";  ";
            cout << "住址:" << abs ->arr[i].m_addr  << endl;
        }
    }
    system("read");
    system("clear");
}

// 联系人是否存在
int is_exist(AddressBooks * abs, string name){
    for(int i=0; i<abs->m_size; i++){
        if(abs->arr[i].m_name == name){
            return i;
        }
    }
    return -1;
};

// 删除联系人
void delete_person(AddressBooks * abs){
    cout << "请输入您要删除的联系人:" << endl;
    string name;
    cin >> name;
    int ret = is_exist(abs, name);
    if(ret != -1){
        for(int i = ret; i < abs->m_size; i++)
        {
            // 数据前移
            abs->arr[i] = abs->arr[i+1];         
        }
        abs->m_size --;
        cout << "===== 删除成功 =====" << endl;
    }else{
        cout << "===== 查无此人 =====" << endl;
    }

    system("read");
    system("clear");
}

// 查找联系人
void find_person(AddressBooks * abs){
    cout << "请输入要查找的联系人" << endl;
    string name;
    cin >> name;
    
    int ret = is_exist(abs, name);
    if(ret != -1){
        cout << "姓名:" << abs->arr[ret].m_name << "\t";
        cout << "性别" << abs->arr[ret].m_gender << "\t";
        cout << "年龄:" << abs->arr[ret].m_age << "\t";
        cout << "电话:" << abs->arr[ret].m_phone << "\t";
        cout << "住址:" << abs->arr[ret].m_addr << endl;


    }else{
        cout << "查无此人" << endl;
    }
    system("read");
    system("clear");
}

// 修改联系人
void modify_person(AddressBooks * abs){
    cout << "请输入要修改的联系人" << endl;
    string name;
    cin >> name;
    
    
    int ret = is_exist(abs, name);
    if(ret != -1){
        string name;
        cout << "姓名:" << endl;
        cin >> name;
        abs->arr[ret].m_name = name;

        int gender;
        cout << "性别:" << endl;    
        while(true){
            cin >> gender;
            if(gender == 1 || gender ==2){
                abs->arr[ret].m_gender = gender;
                break;
            }
            else{
                cout << "输入有误，请重新输入" << endl;
            }
            
        }

        int age;
        cout << "年龄:" << endl;
        cin >> age;
        abs->arr[ret].m_age = age;

        string phone;
        cout << "电话:" << endl;
        cin >> phone;
        abs->arr[ret].m_phone = phone;

        string addr;
        cout << "住址:" << endl;
        cin >> addr;
        abs->arr[ret].m_addr = addr;

        cout << "===== 修改成功 =====" << endl;

    }else{
        cout << "查无此人" << endl;
    }
    system("read");
    system("clear");
}

// 清空联系人
void clear_person(AddressBooks * abs){
    abs->m_size = 0;
    cout << "已清空!" << endl;
    system("read");
    system("clear");
}

int main(){  
    
    // 创建通讯录结构体变量
    AddressBooks abs;
    abs.m_size = 0;

    int select = 0; 
    while(true){
        //菜单调用
        show_menu();
        cin >> select;
        switch (select)
        {
            case 1:
                /* 1.添加联系人 */
                add_person(&abs);
                break;

            case 2:
                /* 2.显示联系人 */
                show_person(&abs);
                break;
            
            case 3:
                /* 3.删除联系人 */
                // {string name;
                // cout << "请输入要删除人的姓名" << endl;
                
                // cin >> name;
                // if(is_exist(&abs, name) == -1){
                //     cout << "查无此人" << endl;
                //     system("read");
                //     system("clear");
                // };
                delete_person(&abs);
                break;

            case 4:
                /* 4.查找联系人 */
                find_person(&abs);
                break;

            case 5:
                /* 5.修改联系人 */
                modify_person(&abs);
                break;

            case 6:
                /* 6.清空联系人 */
                clear_person(&abs);
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