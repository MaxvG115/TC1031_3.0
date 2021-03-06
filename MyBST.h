/*===============================*
<Autores>
+Vicente Viera Guízar, ID: A01639784
+Maximiliano Villegas Garcia. ID: A01635825
+Emma Gabriela Alfaro De la Rocha. ID: A01740229
</Autores>
=================================*
*/
#ifndef MYBST
#define MYBST

#include <vector>
#include <string>
#include <string>

struct MyNodeBST{
  int data;
  MyNodeBST* left;
  MyNodeBST* right;
  std::vector<std::string> ipes;

  MyNodeBST(int data){
    this->data=data;
    this->left=this->right=nullptr;
  }
};

class MyBST{
    private:
        MyNodeBST* root;
        int size;
        void preorder(MyNodeBST*);
        void postorder(MyNodeBST*);
        void inorder(MyNodeBST*);
        void lvl(MyNodeBST*);
        int height(MyNodeBST*);
        int whatLevelIAm(int,MyNodeBST*);
        int steps(int,MyNodeBST*);
        MyNodeBST* insert(MyNodeBST*,int,std::string);
        MyNodeBST* remove(MyNodeBST*,int);
        bool ancestors(MyNodeBST*,int);
        bool search(int,MyNodeBST*);
        int reverseOrder(MyNodeBST*,int,int);
    public:
        int level;
        MyBST();
        int getSize();
        bool isEmpty();
        bool search(int);
        void visit(int);
        int height();
        int whatLevelIAm(int);
        bool insert(int,std::string);
        void ancestors(int);
        MyNodeBST* succesor(MyNodeBST*);
        bool remove(int);
        int reverseOrder(int);
};
#endif
