#include<iostream>
using namespace std;

// 立方体类

class Cube
{

public:
    void set_parameters(int ml, int mw, int mh)
    {
        m_h = mh;
        m_l = ml;
        m_w = mw;
    }

    // int get_parameters()
    // {
    //     cout << "长: " << m_l << "\t";
    //     cout << "宽: " << m_w << "\t";
    //     cout << "高: " << m_h << endl;  
    // }

    int get_length()
    {
        return m_l;
    }
    int get_width()
    {
        return m_w;
    }
    int get_height()
    {
        return m_h;
    }

    int solve_area()
    {
        return (m_l*m_w + m_w*m_h + m_h*m_l)*2;
    }

    int solve_volum()
    {
        return m_l*m_w*m_h;
    }

    // 成员函数判断相等与否
    bool isSamebyclass(Cube &c)
    {
        if(m_l == c.get_length() && m_w == c.get_width() && m_h == c.get_height())
        {
            return true;
        }
        return false;
    }

private:
    int m_l;
    int m_w;
    int m_h;
};

// 利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2){
    if(c1.get_height() == c2.get_height() && c1.get_length()==c2.get_length() && c1.get_width() == c2.get_width())
    {
        return true;
    }
    return false;
};

int main(){

    Cube c1;
    c1.set_parameters(10, 20, 30);
    cout << "c1的面积: " << c1.solve_area() << endl;
    cout << "c1的体积: " << c1.solve_volum() << endl;
    

    Cube c2;
    c2.set_parameters(10, 23, 30);
    cout << "c2的面积: " << c2.solve_area() << endl;
    cout << "c2的体积: " << c2.solve_volum() << endl;


    //利用全局函数判断是否相等
    bool res = isSame(c1, c2);
    if(res){
        cout << "相等" << endl;
    }else{
        cout << "不相等" << endl;
    }
    
    //利用成员函数判断是否相等
    bool ret = c1.isSamebyclass(c2);
    if(res){
        cout << "相等" << endl;
    }else{
        cout << "不相等" << endl;
    }
    return 0;
}
