#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "drzewo.cpp"





int main()
{
    int choice, item;
    AVL avl;
    while (1)
    {
        cout<<"\n                     "<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n                     "<<endl;
        cout<<"1.Insert element "<<endl;
        cout<<"2.show balanced AVL Tree"<<endl;
        cout<<"3.Delete element "<<endl;
        cout<<"4.PreOrder "<<endl;
        cout<<"5.PostOrder "<<endl;
        cout<<"6.InOrder "<<endl;
        cout<<"7.Close the program"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<" Enter the number : ";
            cin>>item;
            root = avl.ins(root, item);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.show(root, 1);
            break;
        case 3:
          cout<<"Enter the number to delete: ";
          cin>>item;
          root=avl.del(root, item);
          break;
        case 4:
            cout<<"Preorder :"<<endl;
            avl.preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder :"<<endl;
            avl.postorder(root);
            cout<<endl;
            break;
        case 6:
             cout<<"Inorder:"<<endl;
            avl.inorder(root);
            cout<<endl;
            break;
        case 7:
            return 0;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
7
