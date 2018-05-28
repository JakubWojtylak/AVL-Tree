#include <iostream>
#include <cstdio>
#include "drzewo.h"




int AVL::height(AVLNode *temp) // temp - temporary node
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int AVL::diff(AVLNode *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}


AVLNode *AVL::rotation_RR(AVLNode *parent) // right-right rotation
{
    AVLNode *temp;
    temp = parent->right; //w temp umieszczamy adres prawego syna węzła ojca
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}


AVLNode *AVL::rotation_LL(AVLNode *parent) // left-left rotation
{
    AVLNode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}


AVLNode *AVL::rotation_LR(AVLNode *parent) // left - right rotation (podwójna)
{
    AVLNode *temp;
    temp = parent->left;
    parent->left = rotation_RR (temp);
    return rotation_LL (parent);
}

AVLNode *AVL::rotation_RL(AVLNode *parent) // right-left rotation (podwójna)
{
    AVLNode *temp;
    temp = parent->right;
    parent->right = rotation_LL (temp);
    return rotation_RR (parent);
}


AVLNode *AVL::balance(AVLNode *temp)
{


    int bf = diff (temp); // balance factor (ró¿nica miêdzy wysokoœciami)


    if (bf > 1)
    {
        if (diff (temp->left) > 0)
            temp = rotation_LL (temp);
        else
            temp = rotation_LR (temp);
    }
    else if (bf < -1)
    {
        if (diff (temp->right) > 0)
            temp = rotation_RL (temp);
        else
            temp = rotation_RR (temp);
    }
    return temp;
}

AVLNode* findMin(AVLNode* root)
{
    if(root == NULL)
        return NULL;
    else if(root->left == NULL)
        return root;
    else
        return findMin(root->right);
}

AVLNode *AVL::ins(AVLNode *root, int value)
{
    if (root == NULL)
    {
        root = new AVLNode;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = ins(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = ins(root->right, value);
        root = balance (root);
    }
    return root;
}

AVLNode *AVL::del(AVLNode *root, int value)
{
    AVLNode *temp;


    if(root == NULL) //pusty
    {
        return 0;
    }
    else if(value < root->data)
    {
        root->left = del(root->left, value);
        root = balance(root);
    }
    else if(value > root->data)
    {
        root->right = del(root->right, value);
        root = balance(root);
    }

    else if(root->left && root->right) // 2 synow
    {
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = del(root->right, root->data);
        root = balance(root);
    }
    else // 0 lub jeden syn
    {
        temp = root;
        if(root->left == NULL)
        {
            root = root->right;
        }

        else if(root->right == NULL)
        {
            root = root->left;
        }

        delete temp;
    }
    if(root == NULL)
    {
        return root;
    }
    root = balance(root);



}





void AVL::show(AVLNode *p, int level)
{

    if (p!=NULL)
    {
        show(p->right, level + 1);
        cout<<"\n"<<endl;
        if (p == root)
            cout<<"Root -> ";
        for (int i = 0; i < level && p != root; i++)
            cout<<"        ";
        cout<<p->data;
        show(p->left, level + 1);
    }
}


void AVL::inorder(AVLNode *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}

void AVL::preorder(AVLNode *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);

}


void AVL::postorder(AVLNode *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}
