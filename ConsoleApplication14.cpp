#include <iostream>
using namespace std;

class MyString
{
    char* str;
    int size;
    static int count;

public:
    MyString()
    {
        size = 80;
        str = new char[size + 1];
        count++;
    }

    MyString(const MyString& copy)
    {
        size = copy.size;
        str = copy.str;
        count++;
    }

    MyString(int Size)
    {
        size = Size;
        str = new char[size + 1];
        count++;
    }

    MyString(const char* arr)
    {
        size = strlen(arr);
        str = new char[size + 1];
        strcpy_s(str, size + 1, arr);
        count++;
    }

    friend istream& operator>>(istream& is, MyString& Str);
    friend ostream& operator<<(ostream& os, const MyString& Str);

    MyString(const std::initializer_list<char>& Str) : 
        MyString(Str.size())
    {
        int i = 0;
        for (auto elem : Str) 
        {
            str[i] = elem;
            i++;
        }
    }


    void SetStr(char* string)
    {
        str = string;
    }

    char* GetStr()
    {
        return str;
    }


    void Input()
    {
        cout << "Input string:";
        cin.getline(str, size + 1);
    }

    void Output()
    {
        if (str == nullptr)
        {
            cout << "Empty object!\n";
            return;
        }
        cout << "String: " << str << "\n\n\n";
    }

    static int GetCount()
    {
        return count;
    }

    /* ~MyString()
     {
         delete[] str;
         count--;
     }*/

    MyString operator++()
    {
        int sz = strlen(str);
        char* new_str = new char[sz + 2];

        strcpy_s(new_str, sz + 2, str);

        new_str[sz] = 'x';
        new_str[sz + 1] = '\0';

        delete[] str;
        str = new_str;

        return *this;
    }
    MyString operator++(int)
    {
        int sz = strlen(str);
        char* new_str = new char[sz + 2];

        strcpy_s(new_str, sz + 2, str);

        new_str[sz] = 'x';
        new_str[sz + 1] = '\0';

        delete[] str;
        str = new_str;

        return *this;
    }

    MyString operator--()
    {
        str[size - 1] = '\0';

        return *this;
    }
    MyString operator--(int)
    {
        str[size - 1] = '\0';

        return *this;
    }

    MyString operator+(int value)
    {
        int sz = strlen(str);
        char* new_str = new char[sz + 1 + value];

        strcpy_s(new_str, sz + 1 + value, str);

        for (int i = 0; i < value; i++)
        {
            new_str[sz + i] = 'x';
        }

        new_str[sz + value] = '\0';

        return MyString(new_str);
    }


    MyString operator-(int value)
    {
        int sz = strlen(str);
        str[sz - value] = '\0';

        return *this;
    }
    MyString& operator=(const MyString& obj)
    {
        if (!(this == &obj))
        {
            if (str != nullptr)
            {
                delete[] str;
            }
            if (obj.str == nullptr)
            {
                str = nullptr;
                size = obj.size;
                return *this;
            }
            str = new char[strlen(obj.str) + 1];
            strcpy_s(str, strlen(obj.str) + 1, obj.str);
            size = obj.size;
        }
        return *this;
    }

    char& operator[](int i)
    {
        return str[i];
    }
};

int MyString::count = 0;

MyString operator+(int size, MyString& obj)
{
    char* str = obj.GetStr();
    int sz = strlen(str);

    char* new_str = new char[sz + 1 + size];

    for (int i = 0; i < size; i++)
    {
        new_str[i] = 'x';
    }

    strcpy_s(new_str + size, sz + 1, str);

    return MyString(new_str);
}

istream& operator>>(istream& is, MyString& Str)
{
    cout << "Set string ";
    is >> Str.str;
    return is;
}

ostream& operator<<(ostream& os, const MyString& Str)
{
    os << "String: " << Str.str << '\t';
    return os;
}



int main()
{
    MyString obj1{'H','e','l','l','o'};
    for (int i = 0; i < 5; i++)
    {
        cout << obj1[i];
    }
}

