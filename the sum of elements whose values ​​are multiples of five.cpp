/*Прочитати з файлу елементи масиву B. 
Обчислити суму елементів, значення яких кратні п'ятьом і не перевищує задане число А. 
Результат записати у файл.*/

#include <iostream>

using namespace std;

int main() {
    const int SIZE = 6; // Розмір масиву
    int A, sum = 0;
    int numbers[SIZE];

    // Введення числа A
    cout << "Enter the maximum value A: ";
    cin >> A;

    // Введення масиву чисел
    cout << "\nEnter " << SIZE << " numbers:\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> numbers[i];
    }

    // Обчислення суми елементів, які кратні 5 і менші за A
    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] % 5 == 0 && numbers[i] < A) {
            sum += numbers[i];
        }
    }

    // Виведення результату
    cout << "\nThe sum of elements divisible by 5 and less than " << A << " is: " << sum << endl;

    return 0;
}
