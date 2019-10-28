#include "BTnode.h"

template <typename elemType>
inline BinaryTree<elemType>::
BinaryTree() : _root(0)
{}

// Copy Constructor
template <typename elemType>
inline BinaryTree<elemType>::
BinaryTree(const BinaryTree &rhs)
{ copy(_root, rhs._root); }

// destructor
template <typename elemType>
inline BinaryTree<elemType>::
~BinaryTree()
{ clear(); }

// Copy Assignment Operator
template <typename elemType>
inline BinaryTree<elemType>&
BinaryTree<elemType>::
operator=(const BinaryTree &rhs)
{
    if (this != &rhs)
    {
        clear(); copy(_root, rhs._root);
    }
    return *this;
}

template <typename elemType>
inline void
BinaryTree<elemType>::
insert(const elemType &elem)
{
    if (!_root)
        _root = new BTnode<elemType>(elem);
    else _root->insert_value(elem);
}

template <typename elemType>
void BTnode<elemType>::
insert_value(const elemType &val)
{
    if (val == _val)
    {
        _cnt++;
        return;
    }

    if (val < _val)
    {
        if (!_lchild)
            _lchild = new BTnode(val);
        else _lchild->insert_value(val);
    }
    else
    {
        if (!_rchild)
            _rchild = new BTnode(val);
        else _rchild->insert_value(val);
    }
    
}


// BTnode
template<typename elemType>
inline BTnode<elemType>::
BTnode(const elemType &val) : _val(val)
{
    _cnt = 1;
    _lchild = _rchild = 0;
}