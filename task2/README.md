```c++
#include <iostream>

using namespace std;

int main()
{
    int* elements;
    int kolvo;
    
    cout << "Enter amount of elements\n";
    cin >> kolvo;
    
    elements=(int*)malloc(kolvo*sizeof(int));
    kolvo--;
    
    for(int i = 0; i <= kolvo; i++) {
        elements[i]=i+1;    
        cout << elements[i] << " ";
    }
    cout << endl;
    
    for(int i = kolvo; i > 0; i--) {
        if(elements[i]>elements[i-1]) {
            int idx = i;
            for(i = kolvo; i >= idx; i--) {
                if(elements[i] > elements[idx-1]) {
                   int element = elements[idx-1];
                   elements[idx-1] = elements[i];
                   elements[i] = element;
                   
                   for(int j = kolvo, i = idx; j > i; j--, i++) {
                        element = elements[i];
                        elements[i] = elements[j];
                        elements[j] = element;
                   }
                   for(i=0;i<=kolvo;i++) cout << elements[i] << " ";
                   cout << endl;
                   break;
                }
            }
        }
    }
    
    return 0;
}
```