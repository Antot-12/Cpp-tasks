#include <iostream>
using namespace std; 

int main()
{
    int i;
    int maxsum = 0;
    int K = 0;
    int arr[30] = {30, 50, 70, 50, 70, 60, 5, 6, 4, 7, 9, 6, 0, 80, 90, 4, 5, 10, 20, 30};
    
    for (i = 0; i < arr[i]-4; i++){
        if (arr[i] + arr[i+1] + arr[i+2] + arr[i+3] + arr[i+4] > maxsum) 
        {
            maxsum = arr[i] + arr[i+1] + arr[i+2] + arr[i+3] + arr[i+4];
            K = i;
        }
    }
    cout << "\n" << "5 elements with the maximum amount: " << arr[K] <<", " <<  arr[K+1] <<", " 
    << arr[K+2] <<", " << arr[K+3] <<", " << arr[K+4] << endl;
    cout << "The sum of these elements is: " <<arr[K] + arr[K+1] + arr[K+2] + arr[K+3] + arr[K+4];
    
    return 0;
}