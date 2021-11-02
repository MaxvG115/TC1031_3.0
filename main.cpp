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
#include "MyBST.h"

using namespace std;
//funcion para leer archivo y guardar los datos en un vector
void readFile(vector<string>& Vector){
    string ip;
    ifstream file;//objeto para leer archivo
    file.open("bitacoraOrdenada-Eq#6.txt");

    if(file.fail()){
        exit(0);
    }else{
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

void fillTree(MyBST& tree,vector<string>& vec){
    //comparar los valores y para compararlos
    int count=0;
    string aux=vec[0];
    
    for(int i=0;i<vec.size();i++){
        //comparamos si la ip actual es igual que la anterior y la sumamos al contador
        if(vec[i]==aux){
            count++;
        }else{
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
    //generamos nuestro vector
    vector<string>* ips=new vector<string>();
    //generamos el arbol
    MyBST tree;
    //leemos y guardamos en un vector todas las ip
    readFile(*ips);
    //contamos cuantas veces se repite cada ip
    fillTree(tree,*ips);
    cout<<tree.root->left->ipes[0];
    return 0;
}