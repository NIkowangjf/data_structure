#include <iostream>
#include <string>

using namespace std;

class KVM
{
public:
    string a, b;

    KVM(string a, string b)
    {
        this->a = a;
        this->b = b;
    }

    int* NEXT()
    {
        int* next_p =new int [a.length()];
        next_p[0] = 0;
        if (a[1] == a[0])
        {
            next_p[1] = 1;
        }
        else
        {
            next_p[1] = 0;
        }
        if (a.length() >= 3)
        {
            for (int i = 2; i < a.length(); i++)
            {
                int same = 0;
                while (a[same] == a[i - same] && i - same >= 0 && same <= a.length() - 1)
                {
                    same++;
                }
                next_p[i] = same;
            }
        }
        return next_p;
    }
};

int main()
{
    string a = "ABCABD";
    string b = "qwertasdfgzxcvb";
    KVM test(a,b);
    for (int i = 0;i<a.length();i++)
        cout << test.NEXT()[i] << endl;
    system("pause");
    return 0;
}