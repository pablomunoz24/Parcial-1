#include <iostream>

using namespace std;

int main()
{
    int c, *a;
    char*b;
    int horas[15]={8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
    char dias[7]={'l','m','w','j','v','s','d'};

    cout<<"Escoger el dia De la materia "<<endl;
    cout<<"1 si es lunes \n";
    cout<<"2 si es martes \n";
    cout<<"3 si es miercoles \n";
    cout<<"4 si es jueves \n";
    cout<<"5 si es viernes \n";
    cout<<"6 si es sabado \n";
    cin>>c;
    switch(c){

      case 1: cout<<"Escogio lunes"<<endl;break;
      case 2: cout<<"Escogio marte"<<endl;break;
      case 3: cout<<"Escogio miercoles "<<endl;break;
      case 4: cout<<"Escogio jueves"<<endl;break;
      case 5: cout<<"Escogio viernes"<<endl;break;
      case 6: cout<<"Escogio sabado"<<endl;break;
      default: cout<<"no esccogio ningun dia"<<endl;break;


    }









    return 0;

}
