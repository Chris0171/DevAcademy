#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Buclers en c++
    for(int i=0; i<5; i++){
        cout << "Bienbenidos" << endl;
    }
    bool condicion = true;
    

    while(condicion == true){
        cout << "Hola mundo" << endl;

        int opcion;
        cout << "Introduce opcion:"; cin >> opcion;
        if(opcion == 0){
            condicion = false;
        }
        
    }

    return 0;
}
