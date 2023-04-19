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

int horarios (char d, int s , int e , int dias[7][15] , int j ,int num,int cic,int ca ,int cb);
int semana(int cr);
int crh,cr;
char hdias[15];
int horasd[8];
int cont=0,cont2=0;
char d ;
int s, e;
int dias[7][15]={


    {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
    {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
    {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
    {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
    {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
    {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},
    {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22},

    };

int main()
{

       int n=1;    //cantida de filas inicial del arreglo
       int a=1;    // variable para seguir registrando o no
       bool b=false;    // para saber si esta repetida el dato
       int c=0;    // verificar palabra repetida
       int cc=0;   // si no esta repetida

        int **creditos= new int*[n];   //creo un puntero (nombre)de filas y columnas y reservo espacio de n filas
        char **codigo= new char*[n];
        char **cedula=new char*[n];
        char **materia= new char*[n];
        int **horas=new int*[n];
        char **horario= new char*[n];

        cout << "ingrese codigo: ";
        cedula[0]= new char[10];               //en la fila cero reservo memoria de 10 columnas
        cin>>codigo[0];


        cout << "ingrese numero de creditos: ";
        creditos[0]= new int[1];
        cin>>cr;
        creditos[0][0]=cr;
        semana(cr);

        horario[0]= new char[3];
        //cin.ignore();
        for(int k=0; k<2;k++){
            horario[0][k]=hdias[k];
        }
        cont=0;




        cout << "ingrese materia : ";
        materia[0]= new char[15];
        cin.ignore();
        cin.getline(materia[0],15);


        cout<<"seguir ingresando=1 -- detenerse=0 :";
        cin>> a;
        cout<<endl;

        while(a==1){

            char **prueba= new char*[1];       // puntero para comprobar si esta repetido el dato-una fila
            int **prueba1= new int*[1];
            char **prueba2= new char*[1];
            char **prueba3= new char*[1];
            char **prueba4= new char*[1];

            comparacion(b, cc, c, prueba, n, codigo);

            cout << "ingrse el numero de creditos ";
            prueba1[0]= new int[1];           //en la fila cero reservo memoria de 1 columna ya que son creditos
            cin>>cr;
            prueba1[0][0]=cr;
            semana(cr);


             prueba3[0]= new char[12];
             for(int k=0; k<cont;k++){
                 prueba3[0][k]=hdias[k];

             }
             cont=0;

            cout << "ingrese materia : ";
            prueba2[0]= new char[15];
            cin.ignore();
            cin.getline(prueba2[0],15);


            char **auxiliar= new char*[n];    // puntero auxuliar para copiar y pegar el de categoria-codigo
            int **auxiliar1= new int*[n];
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

            creditos= new int*[n];
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
            creditos[n-1]=new int[34];
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
            cout <<creditos[g][0]<<" ";
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
    int horarios (char d,int s , int e , int dias[7][15] , int j , int cic,int num ,int ca , int cb){
        for(int i=0;i<=num;i++){
            if(dias[j][i]==e ){
                for(int k=0;k<(s-e);k++){
                    dias[j][i]=0;
                    i++;
                    cic=1;
                }
            }

            if(cic==0 && i==14){
                cout<<"Esa horario no esta disponible"<<endl;

            }
            else if(cic==1 && i==14){
                cout<<"se registraron el horario"<<endl;
                crh=crh-(s-e);
                hdias[cont] =d;
                cont++;
                horasd[cont2]=e;
                cont2++;
                horasd[cont2]=s;
                cont2++;
                for(int k=0;k<=cont2;k++){
                    if(horasd[k]==e && horasd[k+1]==s){
                        cout<< hdias <<" "<<horasd[k]<<"-"<<horasd[k+1]<<endl;
                        k=10;
                    }

                }

                if(crh==0){
                    cout<<"ya registro todas las horas"<<endl;
                    break;

                }
                else{
                    cout<<"se registraron "<<(s-e)<<"  horas le falta "<<crh<<" por favor ingrselas"<<endl;

                }
                for(j=0;j<=6;j++){
                    for(int i=0;i<=14;i++){
                        cout<<dias[j][i]<<" ";
                    }
                    cout<<"\n";
                }


            }

        }
        return crh,cont;
    }

    int semana(int cr){
        int ca=0 , cb=0,cred=0;
        int dec;
        int cic=0 , num=14;
         if (cr==5) crh=7;
         else if(cr==4)crh=4;

     while(cred==0){


         if(cr>=4 && cr<=5){

           while (ca==0){
                cout<<"ingrese el dia ";
                cin>>d;
                cic=0;
                cb=0;
                if (d==109){

                    while (cb==0){
                        int j=1;
                        cout<<"ingreso al dia martes"<<endl;
                        cout<<"ingrese la hora de entrada : ";
                        cin>>e;
                        cout<<"ingrese la hora de salida: ";
                        cin>>s;
                        horarios (d,s,e,dias,j ,cic,num,ca,cb);
                        if (crh==0){
                            ca++;
                            cb++;
                            cred++;
                        }
                        else{
                            cout<<"1 si quiere escoger un nuveo dia  ";
                            cout<<"o 2 si quiere agregar otro horario en este mismo dia: ";cin>>dec;
                                if(dec==1){
                                cb++;


                            }
                            else if(dec==2){
                            }
                        }

                    }
                }
                else if(d==108){
                    while (cb==0){
                        int j=0;
                        cout<<"ingreso al dia lunes"<<endl;
                        cout<<"ingrese la hora de entrada : ";
                        cin>>e;
                        cout<<"ingrese la hora de salida: ";
                        cin>>s;
                        horarios (d,s,e,dias,j ,cic,num,ca,cb);
                        if (crh==0){
                            ca++;
                            cb++;
                            cred++;
                        }
                        else{
                            cout<<"1 si quiere escoger un nuveo dia  ";
                            cout<<"o 2 si quiere añadir otro horario en este mismo día: ";cin>>dec;
                                if(dec==1){
                                cb++;


                            }
                            else if(dec==2){
                            }
                        }

                    }
                }
                else if(d==119){
                    while (cb==0){
                        int j=2;
                        cout<<"ingreso al dia Miercoles"<<endl;
                        cout<<"ingrese la hora de entrada : ";
                        cin>>e;
                        cout<<"ingrese la hora de salida: ";
                        cin>>s;
                        horarios (d,s,e,dias,j ,cic,num,ca,cb);
                        if (crh==0){
                            ca++;
                            cb++;
                            cred++;
                        }
                        else{
                            cout<<"1 si quiere escoger un nuveo dia  ";
                            cout<<"o 2 si quiere añadir otro horario en este mismo día: ";cin>>dec;
                                if(dec==1){
                                cb++;


                            }
                            else if(dec==2){
                            }
                        }

                    }
                }
                else if(d==106){
                    while (cb==0){
                        int j=3;
                        cout<<"ingreso al dia Jueves"<<endl;
                        cout<<"ingrese la hora de entrada : ";
                        cin>>e;
                        cout<<"ingrese la hora de salida: ";
                        cin>>s;
                        horarios (d,s,e,dias,j ,cic,num,ca,cb);
                        if (crh==0){
                            ca++;
                            cb++;
                            cred++;
                        }
                        else{
                            cout<<"1 si quiere escoger un nuveo dia  ";
                            cout<<"o 2 si quiere añadir otro horario en este mismo día: ";cin>>dec;
                                if(dec==1){
                                cb++;


                            }
                            else if(dec==2){
                            }
                        }

                    }
                }
                else if(d==118){
                    while (cb==0){
                        int j=4;
                        cout<<"ingreso al dia Viernes"<<endl;
                        cout<<"ingrese la hora de entrada : ";
                        cin>>e;
                        cout<<"ingrese la hora de salida: ";
                        cin>>s;
                        horarios (d,s,e,dias,j ,cic,num,ca,cb);
                        if (crh==0){
                            ca++;
                            cb++;
                            cred++;
                        }
                        else{
                            cout<<"1 si quiere escoger un nuveo dia  ";
                            cout<<"o 2 si quiere añadir otro horario en este mismo día: ";cin>>dec;
                                if(dec==1){
                                cb++;


                            }
                            else if(dec==2){
                            }
                        }
                    }
                }
                else if(d==115){
                    while (cb==0){
                        int j=5;
                        cout<<"ingreso al dia Sabado"<<endl;
                        cout<<"ingrese la hora de entrada : ";
                        cin>>e;
                        cout<<"ingrese la hora de salida: ";
                        cin>>s;
                        horarios (d,s,e,dias,j ,cic,num,ca,cb);
                        if (crh==0){
                            ca++;
                            cb++;
                            cred++;
                        }
                        else{
                            cout<<"1 si quiere escoger un nuveo dia  ";
                            cout<<"o 2 si quiere añadir otro horario en este mismo día: ";cin>>dec;
                                if(dec==1){
                                cb++;


                            }
                            else if(dec==2){
                            }
                        }
                    }
                }
                else{
                    cout<<"Recuerde los dias corresponde"<<endl;
                    cout<<"l es lunes"<<endl;
                    cout<<"m es martes"<<endl;
                    cout<<"w es miercoles"<<endl;
                    cout<<"j es jueves"<<endl;
                    cout<<"v es viernes"<<endl;
                    cout<<"s es sabado";
                }
        }
         }

              else{
                  cout<<"Debe elegir 4 o 5 creditos"<<endl;
                  }

         }


    return d,e,s;
      }



