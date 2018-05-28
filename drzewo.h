#include <iostream>
#include <cstdlib>


using namespace std;

 struct AVLNode
{
    int data;
     AVLNode *left;
     AVLNode *right;

}*root;



class AVL

{


public:
    int height(AVLNode *);
    int diff(AVLNode *);
    AVLNode *rotation_RR(AVLNode *);
    AVLNode *rotation_LL(AVLNode *);
    AVLNode *rotation_LR(AVLNode *);
    AVLNode *rotation_RL(AVLNode *);
    AVLNode* balance(AVLNode *);
    AVLNode* ins(AVLNode *, int );
    AVLNode* del(AVLNode *, int);
    void show(AVLNode *, int);
    void inorder(AVLNode *);
    void preorder(AVLNode *);
    void postorder(AVLNode *);
    AVL()
    {
        root = NULL;
    }
};
