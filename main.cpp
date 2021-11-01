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
    
}

int main(){
    //generamos nuestro vector
    vector<string>* ips=new vector<string>();
    //leemos y guardamos en un vector todas las ip
    readFile(*ips);
    //contamos cuantas veces se repite cada ip
    return 0;
}