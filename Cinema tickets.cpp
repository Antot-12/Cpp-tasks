#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdlib.h>


using namespace std;

int Show_Menu ();				 // Показати головне меню
void Show_Chart ();			   // Показати таблицю розміщення
const char FULL = 'F';			// Зайняті місця
const char EMPTY = '#';		   // Вільні місця
const int rows = 5;			   // Кількість рядід
const int columns = 30;		   // Кількість місць у ряду
char map [rows][columns];		 // / Масив для розміщення таблиці посадочних місць
double price;
int total = 0;
int seat = 150;
int seat2 = 0;
int Quit = 1;
const int m = 150;
int i = 0;

struct datee {
    
    int day, month, year;
};

struct theatre{

    datee dates;
    char plays[20];
   
}theater_r[m];

bool compare(theatre a, theatre b){
        return (strcmp(a.plays, b.plays) < 0);
    }

int  print();

int main (){
    
const int Num_Rows = 5;
int price [Num_Rows];
int row2, column2, cost;
int answer;
int answer_1;
int ex = 0;


theatre Antot;



//Main Logo

	cout << "*********************************************************\n\n" << endl;
	
	
	cout << "       	     Ласкаво просимо до театру Antot_12     	\n\n" << endl;
	
	
	cout << "*********************************************************" << endl;
	cout << endl << endl;
	

int choice;
int day_check;
	do
	{
		choice = Show_Menu();	  // Головне меню
		switch (choice)
		{
			case 1:
			    system("cls");
			    system("cls||clear"); 
				cout << "Переглянути ціни на місця: \n\n";
				
				for (int count = 0; count < rows; count++)
				{
					cout << "Ціна pа ряд: " << (count + 1) << ": ";
					cout << price [count] << endl;
				}
				break;
			case 2:
		    	system("cls");
		    	system("cls||clear"); 
				cout << "Придбати квиток: \n\n";
				do 
				{
					cout << "Будь ласка, виберіть ряд, в який ви хотіли б сісти: ";
					cin >> row2;
					cout << "Будь ласка, виберіть місце, на якому ви б хотіли сидіти: ";
					
					cin >> column2;
					if (map [row2] [column2] == '*')
						{
							cout << "Місце розпродане, будь ласка, виберіть нове місце. ";
							cout << endl;
						}
					else 
					{
						cost = price [row2] + 0;
						total = total + cost;
						cout << "Цей квиток коштує: " << cost << endl;
						cout << "Підтвердити покупку? Введіть (1 = ТАК / 2 = НІ): \n";
						cin >> answer;
						seat = seat - answer;
						seat2 += answer;
						
						if (answer == 1)
						{ 
							cout << "\n\n Ваша покупка квитка підтверджена. \n\n " << endl;
							map [row2][column2] = FULL;
						}
						else if (answer == 2)
						{  
						    cout << endl << endl;
							cout << "Ви хотіли б поглянути на інші місця? (1 = ТАК / 2 = НІ): ";
							cout << endl;
							cin >> Quit;
						}
					}
				}
				while (Quit == 1);
					
				break;
			case 3:
		    	system("cls");
		    	system("cls||clear"); 
				cout << "Переглянути вільні місця: \n\n";
				Show_Chart ();
				break;
			case 4:
			    system("cls");
			    system("cls||clear"); 
				cout << "Заповнити інформацію про вистави: \n\n";
				
		// Встановлюємо вистави.
                do{
                    cout << "Введіть назву вистави: " << endl;
                    cin >> theater_r[i].plays;
        
                    cout << "Введіть день вистави: " << endl;
                    cin >> theater_r[i].dates.day;
                    
                    cout << "Введіть місяць вистави: " << endl;
                    cin >> theater_r[i].dates.month;
                    
                    cout << "Введіть рік вистави: " << endl;
                    cin >> theater_r[i].dates.year;
                    
                    
                    cout << endl << endl;
            		cout << "Ви хотіли б заповнити інформацію про іншу виставу? (1 = ТАК / 2 = НІ): ";
            		cin >> answer_1; i++;
                }
            	while (answer_1 == 1);
            	
        				break;
	        case 5:
	            system("cls");
		    	system("cls||clear"); 
				cout << "Сортування за датою: \n\n";
				
				sort(theater_r, theater_r + i, compare);
				
                print();
				
				break;
				
			case 6:
			    system("cls");
		    	system("cls||clear"); 
				cout << "Заповнити інформацію про ціни на квитки: \n\n";
				
				 // Встановлюємо ціни рядів.

            	for (int count = 0; count < rows; count++)
            		{
            			cout << "Введіть ціну за ряд " << (count + 1) << ": ";
            				cin >> price [count];
            			   
            		}
            	for (int ii = 0; ii < rows; ii++)
            		{
            			for (int j = 0; j < columns; j++)
            				map [ii][j] = EMPTY;
            				
            		}

				break;
				
	        case 7:
	            system("cls");
		    	system("cls||clear");
		
		    	for (int k = 0; k < i; k++){
    				cout << "\n\n Показати всі вистави: \n\n";
    				print();
    				cout << "Ціна за ряд: " << "\n";
    				cout << "Ряд 1: " << price[0] << endl << "Ряд 2: " << price[1] << endl <<  "Ряд 3: " << price[2] << endl << "Ряд 4: " << price[3] << endl;
    				cout << "Ряд 5: " << price[4] << endl;
		    	}
				break;
			case 8:
		    	system("cls");
		    	system("cls||clear"); 
				cout << "Cьогоднішні вистави: \n\n";
				
				cout << "Введіть День: " << endl;
				cin >> day_check;
				
				bool check_perf;
				check_perf = 0;
				
				for (int k = 0; k < i; k++){
				    
    				if (day_check = theater_r[k].dates.day)
    				{
    				cout << "Така вистава є! " << "\n\n";
    				cout << "Вистава: "  << theater_r[k].plays << " " << endl << "Дата вистави: " << "\n\n" << "День: " << theater_r[k].dates.day << " " << endl;
    				cout << "Місяць: " << theater_r[k].dates.month << " " << endl << "Рік: " <<  theater_r[k].dates.year << " " << endl;
    				check_perf = 1;
    				}
				}
				if (check_perf == 0){
				    cout << "Сьогодні таких вистав немає, вибачте! ";
				}

				break;
				
			case 9:
			    system("cls");
			    system("cls||clear"); 
				cout << "Вийти\n";
				exit(0);
				
				break;
			default : cout << "Помилка введення\n";
		}



	} while (choice != 10);
return 0;
return i;
}

int Show_Menu()    
{
	int MenuChoice;
		cout << endl << endl;
		cout << " \tГОЛОВНЕ МЕНЮ\n";
		cout << " 1. Переглянути ціни на місця.\n";
		cout << " 2. Придбайте квиток.\n";
		cout << " 3. Переглянути вільні місця.\n";
		cout << " 4. Заповнити інформацію про вистави.\n";
		cout << " 5. Заповнити інформацію про ціни на квитки.\n";
		cout << " 6. Сортування за датою.\n";
		cout << " 7. Показати всі вистави.\n";
		cout << " 8. Cьогоднішні вистави.\n";
		cout << " 9. Вихід з програми.\n";
		cout << "_____________________\n\n";
		cout << "Будь ласка, введіть свій вибір: ";
		cin >> MenuChoice;
		cout << endl << endl;
	return MenuChoice;
}

// Таблиця розміщення

void Show_Chart ()
{
	cout << "\tМіцся: " << endl;
	cout << "   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n";
		for (int count = 0; count < 5; count++)
		{
			cout << endl << "Ряд: " << (count + 1);
			for (int count2 = 0; count2 < 30; count2++)
			{
				cout << " " <<  map [count] [count2];
			}
		}
			cout << endl;
}

int print(){
    
			for (int k = 0; k < i; k++){
			cout << "\n\n Показати всі вистави: \n\n";
			cout << "Вистава: "  << theater_r[k].plays << " " << endl << "Дата вистави: " << "\n\n" << "День: " << theater_r[k].dates.day << " " << endl;
			cout << "Місяць: " << theater_r[k].dates.month << " " << endl << "Рік: " <<  theater_r[k].dates.year << " " << endl;
    	}
}