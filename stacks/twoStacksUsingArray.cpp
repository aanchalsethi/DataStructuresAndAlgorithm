#include <iostream>
using namespace std;

class TwoStack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    TwoStack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int num)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void push2(int num)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            return arr[top1];
            top1--;
        }
        else
        {
            return -1;
        }
    }

    int pop2()
    {
        if (top2 < size)
        {
            return arr[top2];
            top2++;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    TwoStack st(5);

    st.push1(1);
    st.push2(2);
    st.push1(3);
    st.push2(4);

    cout << st.pop1() << endl;

    cout << st.pop2() << endl;
    return 0;
}