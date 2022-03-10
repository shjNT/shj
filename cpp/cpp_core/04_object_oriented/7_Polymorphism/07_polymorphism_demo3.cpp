#include<iostream>
using namespace std;

// 电脑组装案例


class CPU{public:virtual void calculate() = 0;};
class GPU{public:virtual void display() = 0;};
class Memory{public:virtual void storage() = 0;};

// 电脑类
class Computer
{
public:
    Computer(CPU *cpu, GPU *gpu, Memory *memory)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_memory = memory;
    }

    void work()
    {   
        m_cpu->calculate();
        m_gpu->display();
        m_memory->storage();
    }

    // 提供析构，释放零件
    // ~Computer()
    // {
    //     if (m_cpu != NULL)
    //     {
    //         delete m_cpu;
    //         m_cpu = NULL;
    //     }

    //     if (m_gpu != NULL)
    //     {
    //         delete m_gpu;
    //         m_gpu = NULL;
    //     }

    //     if (m_memory != NULL)
    //     {
    //         delete m_memory;
    //         m_memory = NULL;
    //     }
        
    // }

private:
    CPU * m_cpu;
    GPU * m_gpu;
    Memory * m_memory;
};

class InterCpu: public CPU
{
public:
    void calculate()
    {
        cout << "inter的cpu计算。。。" << endl;
    }
};

class InterGpu: public GPU
{
public:
    void display()
    {
        cout << "inter的gpu计算。。。" << endl;
    }
};

class InterMemory: public Memory
{
public:
    void storage()
    {
        cout << "inter的memory计算。。。" << endl;
    }
};


class LenovoCpu: public CPU
{
public:
    void calculate()
    {
        cout << "lenovo的cpu计算。。。" << endl;
    }
};

class LenovoGpu: public GPU
{
public:
    void display()
    {
        cout << "lenovo的gpu计算。。。" << endl;
    }
};

class LenovoMemory: public Memory
{
public:
    void storage()
    {
        cout << "lenovo的memory计算。。。" << endl;
    }
};


void test01()
{
    CPU * intercpu = new InterCpu;
    GPU * intergpu = new InterGpu;
    Memory * intermemory = new InterMemory;

    Computer * computer1 = new Computer(intercpu, intergpu, intermemory);
    computer1->work();
    delete computer1;

    Computer * computer2 = new Computer(new LenovoCpu, new LenovoGpu, new LenovoMemory);
    computer2->work();
    delete computer2;

    Computer * computer3 = new Computer(new InterCpu, new LenovoGpu, new LenovoMemory);
    computer3->work();
    delete computer3;
}

int main()
{
    test01();
    return 0;
}