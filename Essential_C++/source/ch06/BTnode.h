#ifndef BTNODE_H
#define BTNODE_H

#include <iostream>

using namespace std;

class string_BTnode {
public: 
    //
private:
    string _val;
    int _cnt;
    string_BTnode *_lchild;
    string_BTnode *_rchild;
};

template <typename elemType>
class BinaryTree;

template <typename elemType>
class BTnode {
    friend class BinaryTree<elemType>;
public: 
    BTnode();
    BTnode(const elemType &val);
    void insert_value(const elemType &val);
private:
    elemType _val;
    int _cnt;
    BTnode<elemType> *_lchild;
    BTnode<elemType> *_rchild;
};

template <typename elemType>
class BinaryTree {
public: 
    BinaryTree();
    BinaryTree(const BinaryTree&);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree&);
    
    bool empty() {return _root==0;}
    void clear();

    void insert(const elemType &elem);

private:
    BTnode<elemType> *_root;
    void copy(BTnode<elemType> *tar, BTnode<elemType> *src);
};




#endif // BTNODE_H