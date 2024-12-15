//Щасливим називають таке шестизначне число, у якого сума перших трьох дорівнює сумі останніх трьох.
//Видрукувати всі щасливі числа. Визначити функцію для визначення суми цифр тризначного числа 

#include <iostream>
using namespace std;

int n, d1, d2, d3, d4, d5, d6, i_L, i_R, Sum_2, Sum_1, i;

int ask_num(int n){
 
    d1 = n % 10;
    d2 = n % 100 / 10;
    d3 = n % 1000 /100;
    
    return  d1 + d2 + d3;
}

int main()
{
    for (int i = 100000; i <= 999999; i++){
        i_L = i / 1000;
        Sum_1 = ask_num (i_L);
        i_R = i % 1000;
        Sum_2 = ask_num (i_R);
        if (i_L == i_R)
            cout << i_L << i_R << endl;   
    }
    
    ask_num(i);
    cout << d1 + d2 +  d3 + d4 + d5 + d6;
     
    return 0;
}
