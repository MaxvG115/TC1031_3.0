/*===============================*
<Autores>
+Vicente Viera Guízar, ID: A01639784
+Maximiliano Villegas Garcia. ID: A01635825
+Emma Gabriela Alfaro De la Rocha. ID: A01740229
</Autores>
=================================*
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <list>
#include "MyBST.h"

using namespace std;

//*********************************** codigo viejo ************************************
struct record{
  public:
    string date;
    string IPqrt1;
    string IPqrt2; 
    string IPqrt3; 
    string IPqrt4;
    string port;
    string status;

    //funcion para comparar dos ips
    bool operator<=(record& a){
    if(stoi(this->IPqrt1)<stoi(a.IPqrt1)){
      return true;
    }
    else if(stoi(this->IPqrt1)==stoi(a.IPqrt1)){
      if(stoi(this->IPqrt2)<stoi(a.IPqrt2)){
        return true;
      }
      else if(stoi(this->IPqrt2)==stoi(a.IPqrt2)){
        if(stoi(this->IPqrt3)<stoi(a.IPqrt3)){
          return true;
        }
        else if(stoi(this->IPqrt3)==stoi(a.IPqrt3)){
          if(stoi(this->IPqrt4)<stoi(a.IPqrt4)){
            return true;
          }
          else if(stoi(this->IPqrt4)==stoi(a.IPqrt4)){
            if(stoi(this->port)<=stoi(a.port)){
              return true;
            }
          }
        }
      }
    }
    return 0;
    }

    //operador para saber si dos records son iguales
    bool operator==(record& a){
    if(this->IPqrt1==a.IPqrt1 && this->IPqrt2==a.IPqrt2 && this->IPqrt3==a.IPqrt3 && this->IPqrt4==a.IPqrt4){
      return true;
    }
    else{
      return false;
    }
    }
        
    //constructor default
    record(){
      this->date="";
      this->IPqrt1="";
      this->IPqrt2="";
      this->IPqrt3="";
      this->IPqrt4="";
    }

    //contructor para el formato de entrada
    record(string ip1,string ip2, string ip3, string ip4){
      this->date="";
      this->IPqrt1=ip1;
      this->IPqrt2=ip2;
      this->IPqrt3=ip3;
      this->IPqrt4=ip4;
    }
};

//Complejidad de:O(n)
//funcion para leer archivo y guardar los datos en un vector
void readFile(vector<record>& Vector){
  record line;
  string aux;
  ifstream file;//objeto para leer archivo
  file.open("bitacora.txt");

  if(file.fail()){
    exit(0);
  }
  else{
    //ciclo para identificar el significado de los datos de cada registro
    while (!file.eof()){
      for(int i=0;i<3;i++){
        getline(file, aux,' ');
        line.date+=aux+' ';
      }
      getline(file, line.IPqrt1, '.');
      getline(file, line.IPqrt2, '.');
      getline(file, line.IPqrt3, '.');
      getline(file, line.IPqrt4, ':');
      getline(file, line.port, ' ');
      getline(file, line.status);

      //line.month=mon2num(line.month);
      Vector.push_back(line);
      line.date="";
    }
  }
  file.close();
}

//Complejidad de:O(n)
//funcion para guardar los datos en una lista
void copyV2L(list<record>& li,vector<record>& vec){
  for(int i=0;i<vec.size();i++){
    li.push_back(vec[i]);
  }
}

//Complejidad de:O(logn)
//funcion para imprimir el documento ordenado completo
void createFile(list<record>& li){
  ofstream archivoResultados("bitacoraOrdenada-Eq#6.txt");
  list<record>::iterator it;

  if (archivoResultados.fail()){
    exit(0);
  }
  for (it = li.begin(); it != li.end(); it++){
    archivoResultados << it->date << " ";
    archivoResultados << it->IPqrt1 << ".";
    archivoResultados << it->IPqrt2 << ".";
    archivoResultados << it->IPqrt3 << ".";
    archivoResultados << it->IPqrt4 << ":";
    archivoResultados << it->port << " ";
    archivoResultados << it->status << endl;
  }
  archivoResultados.close();
}

//Complejidad de:O(n)
//funcion de intercambio de variables
void swap(record *a, record *b) {
  record t = *a;
  *a = *b;
  *b = t;
}

//Complejidad de:O(nlogn)
//hacemos la particion de quicksort
int partition(vector<record>& v, int low, int high) {
  record pivot = v[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (v[j] <= pivot) {
      i++; 
      swap(&v[i], &v[j]);
    }
  }
  swap(&v[i + 1], &v[high]);
  return (i + 1);
}

//Complejidad de:O(nlogn)
//ordenamos el vector con quick sort
void quickSort(vector<record>& v, int low, int high) {
  if(low < high){
    int p = partition(v, low, high);
    quickSort(v, low, p - 1);
    quickSort(v, p + 1, high);
  }
}
//******************************** nuevo programa ****************************************************

//Complejidad de:O(n)
//funcion para leer archivo y guardar los datos en un vector
void readFile(vector<string>& Vector){
  string ip;
  ifstream file;//objeto para leer archivo
  file.open("bitacoraOrdenada-Eq#6.txt");

  if(file.fail()){
    exit(0);
  }
  else{
    //ciclo para descartar la fecha
    while(!file.eof()){
      for(int i=0;i<4;i++){
        getline(file, ip,' ');
      }
      //leemos la ip
      getline(file, ip, ':');

      //lo agregamos al vector
      Vector.push_back(ip);
      getline(file,ip);
    }
  }
  file.close();
}

//Complejidad de:O(n)
void fillTree(MyBST& tree,vector<string>& vec){
  //comparar los valores y para compararlos
  int count=0;
  string aux=vec[0];

  for(int i=0;i<vec.size();i++){
    //comparamos si la ip actual es igual que la anterior y la sumamos al contador
    if(vec[i]==aux){
      count++;
    }
    else{
      //agregamos cuantas veces se repitio la ip como la key y la ip para que la agregue
      //al vector de las ip que se repiten la misma cantidad de veces
      tree.insert(count,aux);
      //actualizamos valores a la nueva ip
      aux=vec[i];
      count=1;
    }
  }
}


int main(){
//******************* codigo viejo ***************************************
//creamos variables iniciales
  vector<record>* vec= new vector<record>();
  list<record>* li=new list<record>();
  pair<bool,list<record>::iterator> f;
  pair<bool,list<record>::iterator> s;

  //leemos y guardamos los registros en un vector
  readFile(*vec);
  //por alguna razon guarda los datos desde una posicion despues del prinipio del begin. para acceder al primer elemento es desde it++
  //ordenamos los datos
  quickSort(*vec, 0, vec->size()-1);
  //pasamos los datos a la lista
  copyV2L(*li,*vec);
  //creacion bitacora ordenada
  createFile(*li);
  //borramos el vector y lista
  delete vec;
  delete li;

//******************** nuevo codigo *****************************************
  //generamos nuestro vector
  vector<string>* ips=new vector<string>();
  //generamos el arbol
  MyBST tree;
  //leemos y guardamos en un vector todas las ip
  readFile(*ips);
  //contamos cuantas veces se repite cada ip
  fillTree(tree,*ips);
  //imprimimos los 5 valores mas grandes
  tree.reverseOrder(5);
  return 0;
}
