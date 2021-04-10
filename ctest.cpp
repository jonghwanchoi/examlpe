#include <iostream>
#include <string>

using namespace std;

int main(void)
{   
    int a,b;
    string str;
    string name = "최종환";
    str = "안녕하세요, " + name + " 님"; //배열x (길이 상관 없음)
    //std = namespace => first(family) name
    cout << str << endl; //endline(줄바꿈)
    cin >> a >> b;

    cout << a << "+" << b <<"=" << a+b << endl;
    return 0;
}