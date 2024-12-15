#include <iostream>

using namespace std;

int main()
{
    int n,i,j;
    int a[10][10];
    
    cout << "Print size of matrix ";
    cin >> n;
    
    for ( int i = 0; i < n; i++){
        for ( int j = 0; j < n; j++){
          if (i >= j)
          a[i][j] = i + 1 - j;
          else
          a[i][j] = j + 1 - i;
         cout << "a[" << i+1 << "]" << "[" << j+1 << "] = " << a[i][j] << "  ";
    }
    cout << "\n";
    }
    
    return 0;
}


#include <iostream>

using namespace std;

int n,i,j; 
int a[10][10];
    
int ar (int n){
    
     for ( int i = 0; i < n; i++){
        for ( int j = 0; j < n; j++){
          if (i >= j)
          a[i][j] = i + 1 - j;
          else
          a[i][j] = j + 1 - i;
         cout << "a[" << i+1 << "]" << "[" << j+1 << "] = " << a[i][j] << "  ";
    }
    cout << "\n";
    }
}

int main()
{
    cout << "Print size of matrix ";
    cin >> n;
    
    ar(n);
    
    return 0;
}
