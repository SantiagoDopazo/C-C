#include <iostream>

using namespace std;

int test(int x)
{
    if(x == 0 || x == 1)
    {
        return x;
    }
    else
    {
        return test(x-1) + test(x-2);
    }
}

int main ()
{
    int num;

    num = test(6);

    cout << num << endl;

    return 0;
}