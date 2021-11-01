#ifndef MYBST
#define MYBST

#include <vector>
#include <string>

struct MyNodeBST{
    int data;
    int count;
    MyNodeBST* left;
    MyNodeBST* right;
    vector<std::string> ipes;

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
        MyNodeBST* insert(MyNodeBST*,int);
        MyNodeBST* remove(MyNodeBST*,int);
        bool ancestors(MyNodeBST*,int);
        bool search(int,MyNodeBST*);
    public:
        int level;
        MyBST();
        int getSize();
        bool isEmpty();
        bool search(int);
        void visit(int);
        int height();
        int whatLevelIAm(int);
        bool insert(int);
        void ancestors(int);
        MyNodeBST* succesor(MyNodeBST*);
        bool remove(int);
};

#endif