#include <iostream>
using namespace std; //可以省略std::
int main(){
    cout << "a multi-line \
    string literal \
    using a backslash"
        << endl; 
    cout << "Hello" << endl;

    //區域性物件
    int value = 2;
    int pow = 10;
    int result = 1;
    //重複result的計算，值到cnt等於pow
    for (int cnt = 0; cnt != pow; ++cnt)
        result *= value; //result = result*value;
    cout << value
         << " raised to the power of "
         << pow << ": \t"
         << result << endl;
    system("pause");
}  