 ///
 /// @file    CowString.cc
 /// @author    kyle(kyleyang58@gmail.com)
 /// @date    2019-01-24 09:32:44
 ///
 
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
class String {
    friend class CharProxy;

public:
    String()
        : _pstr(new char[5]() + 4)
    {
        cout << "String()" << endl;
        initRefcount();
    }

    String(const char* pstr)
        : _pstr(new char[strlen(pstr) + 5]() + 4)
    {
        strcpy(_pstr, pstr);
        initRefcount();
        cout << "String(const char *) constructor" << endl;
    }

    String(const String& rhs)
        : _pstr(rhs._pstr)
    {
        increaseRefcount();
        cout << "String(const String &) constructor" << endl;
    }

    String& operator=(const String& rhs)
    {

        if (this != &rhs) { // 自复制
            release(); //释放左操作数空间
            _pstr = rhs._pstr; // 进行浅拷贝
            increaseRefcount();
        }
        return *this;
    }

    void release()
    {
        decreaseRefcount();
        if (refcount() == 0) {
            delete[](_pstr - 4);
        }
    }

    ~String()
    {
        release();
    }

    int refcount() const
    {
        return *(int*)(_pstr - 4);
    }

    const char* c_str() const
    {
        return _pstr;
    }

    size_t size() const
    {
        return strlen(_pstr);
    }

    class CharProxy { //字符代理
    public:
        CharProxy(String& str, int index)
            : theString(str)
            , charIndex(index)
        {
        }
        CharProxy& operator=(const CharProxy& rhs)
        {
            cout << "write only operator []" << endl;
            if ((theString.refcount()) > 1) {
                theString = *(new String(theString._pstr));
            }
            theString._pstr[theString.refcount()] = rhs.theString._pstr[rhs.theString.refcount()];
            return *this;
        }
        CharProxy& operator=(char c)
        {
            cout << "write only operator []" << endl;
            if ((theString.refcount()) > 1) {
                theString = *(new String(theString._pstr));
            }
            theString._pstr[charIndex] = c;
            return *this;
        }

        operator char() const
        {
            cout << "read only operator []" << endl;
            return theString._pstr[charIndex];
        }

    private:
        String& theString;
        int charIndex;
    };
    const CharProxy operator[](int index) const // for const Strings
    {

        return CharProxy(const_cast<String&>(*this), index);
    }
    CharProxy operator[](int index) // for non-const Strings
    {

        return CharProxy(*this, index);
    }

private:
    void initRefcount()
    {
        *(int*)(_pstr - 4) = 1;
    }

    void increaseRefcount()
    {
        ++*(int*)(_pstr - 4);
    }

    void decreaseRefcount()
    {
        --*(int*)(_pstr - 4);
    }

    friend std::ostream& operator<<(std::ostream& os, const String& rhs);

private:
    char* _pstr; //指向字符串内容本身
};

std::ostream& operator<<(std::ostream& os, const String& rhs)
{
    os << rhs._pstr;
    return os;
}

int main(void)
{

    String s1("hello,world");
    String s2 = s1; //copy constructor
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    auto x = s1[3];
    s2[5] = '2';
    cout << x << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    

    return 0;
}


