#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main()
{
    char a[260];
    cin.getline(a, 260);
    int i = 0, res = 0;
    int num1 = 0, num2 = 0;
    while (a[i] != '#')
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            s.push(a[i] - '0');
        }
        else
        {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            char opt = a[i];
            switch (opt)
            {
            case '+':
                res = num2 + num1;
                break;
            case '-':
                res = num2 - num1;
                break;
            case '*':
                res = num2 * num1;
                break;
            case '/':
                res = num2 / num1;
                break;
            }
            s.push(res);
        }
        i++;
    }
    cout << s.top() << endl;
    system("pause");
    return 0;
}