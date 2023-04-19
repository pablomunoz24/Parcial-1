#include <iostream>

using namespace std;
#include <fstream>
/*int main()
{
    ifstream file_in;
    char texto[25];
    char lineas[10][25];
    char *c , *b;
    int i=0;
    int con=0;
    c=texto;
    file_in.open("documento.txt");
    while(file_in.getline(texto,25)){
    if(*c==NULL){
        cout<<"esta vacio"<<endl;

    }
    else{
        for(int j=0;j<10;j++){
            lineas[i][j]=texto[j];

        }
        i++;
        con++;
      }
  }
    for(int j=0;j<con;j++){
        for(int i=0;i<10;i++){

        cout<<lineas[j][i];
        }
       cout<<"\n";
     }
 return 0;
}
*/
void comparacion(bool b,int cc, int c, char **prueba, int n, char **codigo);

int main()
{

    char dias[7][15]={

       {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
       {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
       {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
       {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
       {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
       {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
       {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},

       };
       int n=1;    //cantida de filas inicial del arreglo
       int a=1;    // variable para seguir registrando o no
       bool b=false;    // para saber si esta repetida el dato
       int c=0;    // verificar palabra repetida
       int cc=0;   // si no esta repetida

        char **creditos= new char*[n];   //creo un puntero (nombre)de filas y columnas y reservo espacio de n filas
        char **codigo= new char*[n];
        char **cedula=new char*[n];
        char **materia= new char*[n];
        int **horas=new int*[n];
        char **horario= new char*[n];

        cout << "ingrese codigo: ";
        cedula[0]= new char[10];               //en la fila cero reservo memoria de 10 columnas
        cin>>codigo[0];


        cout << "ingrese numero de creditos: ";
        creditos[0]= new char[1];
        cin>>creditos[0];


        cout << "ingrese horario: ";
        horario[0]= new char[12];
        cin.ignore();

        cin.getline(horario[0],12);


        cout << "ingrese materia : ";
        materia[0]= new char[15];
        cin.ignore();
        cin.getline(materia[0],15);


        cout<<"seguir ingresando=1 -- detenerse=0 :";
        cin>> a;
        cout<<endl;

        while(a==1){

            char **prueba= new char*[1];       // puntero para comprobar si esta repetido el dato-una fila
            char **prueba1= new char*[1];
            char **prueba2= new char*[1];
            char **prueba3= new char*[1];
            char **prueba4= new char*[1];

            comparacion(b, cc, c, prueba, n, codigo);

            cout << "ingrse el numero de creditos ";
            prueba1[0]= new char[1];           //en la fila cero reservo memoria de 1 columna ya que son creditos
            cin>>prueba1[0];

            cout << "ingrese horario ";

             prueba3[0]= new char[12];
              cin.ignore();
              cin.getline(horario[0],12);

            cout << "ingrese materia : ";
            materia[0]= new char[15];
            cin.ignore();
            cin.getline(materia[0],15);


            char **auxiliar= new char*[n];    // puntero auxuliar para copiar y pegar el de categoria-codigo
            char **auxiliar1= new char*[n];
            char **auxiliar2= new char*[n];
            char **auxiliar3= new char*[n];
            for(int g=0; g<n; g++){         //hago una copia
                auxiliar[g]=codigo[g];
                auxiliar1[g]=creditos[g];
                auxiliar2[g]=materia[g];
                auxiliar3[g]=horario[g];

            }

            delete[] codigo;           //libero espacio en memoria
            delete[] creditos;
            delete[] materia;
            delete[] horario;
            codigo=nullptr;
            creditos=nullptr;
            materia=nullptr;
            horario=nullptr;

            n++;                         //incremento pa la nueva fila

            creditos= new char*[n];
            codigo= new char*[n];
            materia= new char*[n];
            horario= new char*[n];
            for(int g=0; g<n-1; g++){          //pego lo de auxiliar a categoria
                cedula[g]=auxiliar[g];
                creditos[g]=auxiliar1[g];
                materia[g]=auxiliar2[g];
                horario[g]=auxiliar3[g];
            }
            delete[] auxiliar;                //libero es espacio en memoria de auxiliar
            delete[] auxiliar1;
            delete[] auxiliar2;
            delete[] auxiliar3;
            auxiliar=nullptr;                 //lo referencio a cero
            auxiliar1=nullptr;
            auxiliar2=nullptr;
            auxiliar3=nullptr;


            codigo[n-1]=new char[10];      //en la ultima fila reservo espacio de memoria 10 columnas
            codigo[n-1]=prueba[0];          //ingreso en la ultima fila la nueva categoria
            creditos[n-1]=new char[34];
            creditos[n-1]=prueba1[0];
            materia[n-1]=new char[15];
            materia[n-1]=prueba2[0];
            horario[n-1]=new char[12];
            horario[n-1]=prueba3[0];
            delete[] prueba;                   //libero espacio de memoria
            prueba=nullptr;                   // referencio a cero
            delete[] prueba1;
            prueba1=nullptr;
            delete[] prueba2;
            prueba2=nullptr;
            delete[] prueba3;
            prueba3=nullptr;
            delete[] prueba4;
            prueba4=nullptr;


            cout<<"seguir ingresando=1 -- detenerse=0 :";
            cin>> a;
            cout<<endl;

        }

        for (int g=0; g<n; g++){       //visualizar el registro
            cout <<codigo[g]<<" ";
            cout <<materia[g]<<" ";
            cout <<creditos[g]<<" ";
            cout <<horario[g]<<" ";
            cout <<endl;
        }

        delete[] codigo;
        codigo=nullptr;
        delete[] creditos;
        creditos=nullptr;
        delete[] materia;
        materia=nullptr;
        delete[] horario;
        horario=nullptr;


  /*  cout<<"Escoger el dia De la materia "<<endl;
    cout<<"1 si es lunes \n";
    cout<<"2 si es martes \n";
    cout<<"3 si es miercoles \n";
    cout<<"4 si es jueves \n";
    cout<<"5 si es viernes \n";
    cout<<"6 si es sabado \n";
    cin>>c;
    switch(c){

      case 1: cout<<"Escogio lunes"<<endl;
        cout<<"ingrese el codigo de la materia"<<endl;

        break;
      case 2: cout<<"Escogio marte"<<endl;break;
      case 3: cout<<"Escogio miercoles "<<endl;break;
      case 4: cout<<"Escogio jueves"<<endl;break;
      case 5: cout<<"Escogio viernes"<<endl;break;
      case 6: cout<<"Escogio sabado"<<endl;break;
      default: cout<<"no esccogio ningun dia"<<endl;break;


    }
*/
        return 0;

}
    void comparacion(bool b,int cc, int c, char **prueba, int n, char **codigo){
    // probar si la categoria ya esta repetida -------------------------------------------------------

    b=true;
    while(b==true){                       //mirar si hay repetidas
        cc=0;
        cout << "ingrese codigo: ";
        prueba[0]= new char[10];           //prueba primera fila reservo memoria dinamica 20 columnas
        cin >>prueba[0];                 //ingresa la categoria en la primera fila
        for(int k=0; k<n; k++){          //recorrer las filas
            c=0;           //reiniciar a c
            for(int j=0; j<10; j++){       // recorrer columnas
                if(prueba[0][j]==codigo[k][j]){    //comparo
                    c++;                              // incremento
                }
            }
            if(c==10){                            //si son iguales c=20
                cout<<"el usuario ya esta"<<endl;
                delete[] prueba;    //libero el espacio en memoria de prueba
                prueba=nullptr;
                prueba=new char*[1];
                break;      //salir del for
            }
            else{           //si no se repite
                cc++;
            }

        }
        if(cc==n){      //si a la final no se repitio en ninguna
            b=false;
        }
      }     //--------------------------------------- prueba tendra la nueva categoria a ingresar en categoria
    }



