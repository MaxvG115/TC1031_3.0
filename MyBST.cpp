/*===============================*
<Autores>
+Vicente Viera Guízar, ID: A01639784
+Maximiliano Villegas Garcia. ID: A01635825
+Emma Gabriela Alfaro De la Rocha. ID: A01740229
</Autores>
=================================*
*/

#include "MyBST.h"
#include <queue>
#include <iostream>

using namespace std;

//Complejidad de:O(1)
//constructor
MyBST::MyBST(){
  this->root=nullptr;
  this->size=0;
  this->level=0;
}
//---------------------------- funciones basicas --------------------------------------------
//Complejidad de:O(1)
//funcion que regresa la cantidad de datos que tiene el arbol
int MyBST::getSize(){
  return this->size;
}

//Complejidad de:O(1)
//funcion que regresa true si esta vacio el arbol false caso contrario
bool MyBST::isEmpty(){
  return this->size==0;
}

//------------------------------ traversal functions -------------------------------------------
//Complejidad de:O(n)
//funcion para imprimir todos los datos de un arbol especificado de forma preoder
void MyBST::preorder(MyNodeBST* node) {
  if(node==nullptr){
      return;
  }
  else{
    cout<<node->data<<"=>";
    preorder(node->left);
    preorder(node->right);
  }
}

//Complejidad de:O(n)
//funcion para imprimir todos los datos de un arbol especificado en postorder
void MyBST::postorder(MyNodeBST* node) {
  if(node==nullptr){
      return;
  }
  else{
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<"=>";
  }
}

//Complejidad de:O(n)
//funcion para imprimir todos los datos de un arbol especificado de forma inorder
void MyBST::inorder(MyNodeBST* node) {
  if(node==nullptr){
    return;
  }
  else{
    inorder(node->left);
    cout<<node->data<<"=>";
    inorder(node->right);
  }
}

//Complejidad de:O(n^2)
//funcion para imprimir level by level todos los datos de un arbol especificado
void MyBST::lvl(MyNodeBST* node){
  if(node==nullptr){
    return;
  }
  else{
    //creamos las 2 queues para guardar lso datos y hacemos push a la primera con el primer valor
    queue<MyNodeBST*> q1;
    queue<MyNodeBST*> q2;
    q1.push(node);
    //siempre que haya elemenos los va a imprimir y a eliminar de la fila
    while(!q1.empty() || !q2.empty()){
      //verificamos que la primera fila no este vacia para que imprima el dato, le asigne sus hijos a
      //la otra fila y le hace dequeue.
      while(!q1.empty()){
      cout<<q1.front()->data<<"=>";
      if(q1.front()->left != nullptr){
        q2.push(q1.front()->left);
      }
      if(q1.front()->right != nullptr){
        q2.push(q1.front()->right);
      }
      q1.pop();
      }

      //lo mismo que en el anterior
      while(!q2.empty()){
        cout<<q2.front()->data<<"=>";
        if(q2.front()->left != nullptr){
          q1.push(q2.front()->left);
        }
        if(q2.front()->right != nullptr){
          q1.push(q2.front()->right);
        }
        q2.pop();
      }
    }
  cout<<endl;
  }
}

//Complejidad de:O(n)
//visit con parametros para recorrer todo el arbol
// 1 Preorder
// 2 Inorder
// 3 Postorder
// 4 Level by level
void MyBST::visit(int traverse){
  switch (traverse){
    case 1:
      preorder(this->root);
      break;
    case 2:
      inorder(this->root);
      break;
    case 3:
      postorder(this->root);
      break;
    case 4:
      lvl(this->root);
      break;
    default:
      break;
  }
}

//-------------------------- ancestors & succesors -----------------------------------------------
//Complejidad de:O(n)
//funcion que obtiene el sucesor de un nodo especificado
MyNodeBST* MyBST::succesor(MyNodeBST* node){
  MyNodeBST* current = node;
  while(current && current->left!=nullptr){
    current = current->left;
  }
  return current;
}

//Complejidad de:O(log(n))
//funcion que regresa los ancestros de un nodo
bool MyBST::ancestors(MyNodeBST* node, int data){
  //si el valor no existe
  if(node==nullptr){
    return false;
  }
  //si el valor es igual entonces regresa true
  else if(node->data==data){
    cout<<node->data;
    return true;    
  }
  //si no encuentra el valor en el nodo actual busca en el sub arbol izquierdo o derecho e imprime el valor
  else if(data<node->data){
    cout<<node->data<<"=>";
    return ancestors(node->left,data);
  }
  else{
    cout<<node->data<<"=>";
    return ancestors(node->right,data);
  }
}

//Complejidad de:O(log(n))
void MyBST::ancestors(int data){
  if(ancestors(this->root,data)){
    return;
  }else{
    system("cls");
    cout<<"value not found";
  } 
}

//------------------------------ search ----------------------------------------------------------
//Complejidad de:O(log(n))
//funcion que nos regresa si un dato existe en un arbol determinado
bool MyBST::search(int data,MyNodeBST* node){
  if(node==nullptr){
    return false;
  }
  //si el valor es igual entonces regresa true
  else if(node->data==data){
    return true;    
  }
  //si no encuentra el valor en el nodo actual busca en el sub arbol izquierdo o derecho
  else if(data<node->data){
    return search(data,node->left);
  }
  else{
    return search(data,node->right);
  }
}

//Complejidad de:O(log(n))
bool MyBST::search(int data){
  return search(data,this->root);
}

//------------------------------- what level am i --------------------------------------------------
//Complejidad de:O(log(n))
//esta es la funcion de preparacion para saber en que nivel se encuentra un dato
int MyBST::steps(int data,MyNodeBST* node){
  if(node==NULL){
    return 0;
  }
  //si encuentra el valor le suma 1
  else if(node->data==data){
    return this->level++;
  }
  //si no encuentra el valor busca si tiene mas sub arboles y si si, baja a esos sub arboles 
  //buscando el valor especificado y le suma 1 a level
  else if(data<node->data){
    steps(data,node->left);
    return this->level++;
  }
  else{
    steps(data,node->right);
    return this->level++;
  }
}

//Complejidad de:O(log(n))
int MyBST::whatLevelIAm(int data,MyNodeBST* node){
  this->level=0;
  return steps(data,node)+1;
}

//Complejidad de:O(log(n))
//funcion para saber en que nivel se encuentra un dato
int MyBST::whatLevelIAm(int data){
  return whatLevelIAm(data,this->root);
}

//------------------------------------ height ------------------------------------------------
//Complejidad de:O(n)
//funcion para encontrar la altura total del arbol seleccionado
int MyBST::height(MyNodeBST* node){
  if(node==nullptr){
    return -1;
  }
  else{
    //sacamos la altura del arbol izquierdo y luego la del derecho
    int l=height(node->left);
    int r=height(node->right);
        
    //comparamos ambas y regresamos la mayor mas 1
    return (l>r) ? ++l : ++r;   
  }
}

//Complejidad de:O(1)
int MyBST::height(){
  return height(this->root);
}

//------------------------------------------ insert ----------------------------------------------
//Complejidad de:O(log(n))
//inserta el valor indicado en el arbol especificado
MyNodeBST* MyBST::insert(MyNodeBST* node, int data, string ip) {
  //agregamos el nodo cuando llega al final del arbol
  if (node==nullptr){
    this->size++;
    return new MyNodeBST(data);
  }

  //comparamos si el key es igual
  if(node->data==data){
    //agregamos la ip que se repitio la cantidad de veces de su key
    node->ipes.push_back(ip);
    return node;
  }
  //navegamos en el arbol para encontrar la posicion correcta del nuevo nodo y lo asigna en la posicion 
  //correcta del ultimo nodo que le corresponde
  if (data<node->data){
    node->left = insert(node->left, data,ip);
  }
  else{
    node->right = insert(node->right, data,ip);
  }
  return node;
}

//Complejidad de:O(log(n))
bool MyBST::insert(int data,string ip) {
  this->root=insert(this->root,data,ip);
  if(root!=nullptr){
    return true;
  }else{
    return false;
  }
}

//----------------------------------- remove ------------------------------------------------------
//Complejidad de:O(log(n))
//funcion para eliminar un nodo con un valor especifico de un arbol especifico
MyNodeBST* MyBST::remove(MyNodeBST* node, int data){
    //si no hay nada
    if (node==nullptr){
      return root;
    //en caso de que si haya elementos buscamos hasta encontrar el valor seleccionado
    }else if(data<node->data){
      node->left=remove(node->left, data);
    }else if(data>node->data)
      node->right=remove(node->right, data);
    else{
      //en este punto ya encontramos el valor y revisamos:
      //* tiene un solo hijo del lado derecho
      if(node->left==nullptr){
        MyNodeBST* temp = node->right;
        delete node;
        this->size--;
        return temp;
      }
      //* tiene un solo hijo del lado izquierdo
      else if(root->right==nullptr) {
        MyNodeBST* temp = node->left;
        delete node;
        this->size--;
        return temp;
      }
      //* tiene dos hijos
      else{
        MyNodeBST* temp=succesor(node->right);
        node->data=temp->data;
        node->right = remove(node->right, temp->data);
      }
    }
  return node;
}

//Complejidad de:O(1)
bool MyBST::remove(int data){
  return remove(this->root,data);
}

int MyBST::reverseOrder(MyNodeBST* node, int n,int count){
    if (node == nullptr){
         return 0;
    }else{
        count += reverseOrder(node->right,n,count);
        for(int j=0;((j<node->ipes.size()) && (count<n));j++){
            cout<<"->"<<node->ipes[j]<<endl;
            count++;
        }
        count+=reverseOrder(node->left,n,count);
        return count;
    }
        
    
    /*if(node == NULL){
        return 0;
    }else{
        int count=reverseOrder(node->right,n);
        
        for(int i=0;i<node->ipes.size() && count<n;i++){
            cout<<node->ipes[i]<<endl;
            count++;
        }
        reverseOrder(node->left,count);
        return count;
    }*/

    /*if (node == nullptr){
        return 0;
    }else{
        int count = reverseOrder(node->right,n);
        if(count <= n){
            for (int i = 0; count < node->ipes.size() && count < 5; i++){
                cout << node->ipes[i]<<endl;
                count++; 
            }
        } 
        return count;
    } */
}

//Complejidad de:O(n)
int MyBST::reverseOrder(int n){
    this->reverseOrder(this->root,n,0);
}
