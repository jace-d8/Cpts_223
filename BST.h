#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;


/* ----------------------------------------------------------------------------
---- Below is declaration of BST class, referring to textbook, Figure 4.16 ----
---------------------------------------------------------------------------- */

template <typename Comparable>
class BST
{
public:
	BST();
	~BST();
	void makeEmpty();

	const Comparable & findMin() const;
	const Comparable & findMax() const;

	bool contains(const Comparable & x) const;
	void insert(const Comparable & x);
	void remove(const Comparable & x);
	int treeSize() const;
	int treeHeight() const;
	void printInOrder() const;
	void printLevels() const;
	void printMaxPath() const;

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;

		BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt): element(theElement), left(lt), right(rt) {}
		BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt): element(move(theElement)), left(lt), right(rt) {}
	};

	BinaryNode *root;
	bool containHelper(const Comparable &x, BinaryNode *t) const;
	void insertHelper(const Comparable &x, BinaryNode *&t);
	void removeHelper(const Comparable &x, BinaryNode *&t);
	int treeSizeHelper(BinaryNode *t) const;
	int treeHeightHelper(BinaryNode *t) const;
	void printInOrderHelper(const BinaryNode * t) const;
	BinaryNode * findMin( BinaryNode * t ) const;
	BinaryNode * findMax( BinaryNode * t ) const;
	void makeEmpty( BinaryNode * & t );
};


/* --------------------------------------------------------------
---- Below is implementation of public and private functions ----
-------------------------------------------------------------- */

// constructor
template<typename Comparable>
BST<Comparable>::BST() : root(NULL) {}

// destructor, refer to textbook, Figure 4.27
template<typename Comparable>
BST<Comparable>::~BST() {
	makeEmpty();
}

// public makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty() {
    makeEmpty(root);
}

// private recursive makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty(BinaryNode *& t) {
    if ( t != NULL ) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
}

// // public findMin
template <typename Comparable>
const Comparable & BST<Comparable>::findMin() const {
    if (root == NULL) {
    	throw underflow_error("Tree is empty");
	}
    return findMin(root)->element;
}

// private findMin: refer to textbook, Figure 4.20
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMin(BinaryNode * t) const {
    if ( t == NULL )
    {
        return NULL;
    } else if (t->left == NULL)
    {
        return t;
    } else
    {
        return findMin(t->left);
    }
}

// public findMax
template <typename Comparable>
const Comparable & BST<Comparable>::findMax() const {
    if (root == NULL) {
    	throw underflow_error("Tree is empty");
	}
    return findMax(root)->element;
}

// private findMax: refer to textbook, Figure 4.21
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMax(BinaryNode * t) const {
    if ( t == NULL )
    {
        return NULL;
    } else if (t->right == NULL)
    {
        return t;
    } else
    {
        return findMax(t->right);
    }
}

// public contains: refer to textbook, Figure 4.17, Line 4 - 7
template<typename Comparable>
bool BST<Comparable>::contains( const Comparable & x ) const
{
	return containHelper(x, root);
}

template<typename Comparable>
bool BST<Comparable>::containHelper(const Comparable &x, BinaryNode *thisRoot) const
{
	if(thisRoot)
	{
		if(thisRoot->element == x)
		{
			return true;
		}
		if(thisRoot->element > x)
		{
			return containHelper(x, thisRoot->left);
		}
		if(thisRoot->element < x)
		{
			return containHelper(x, thisRoot->right);
		}
	}
	return false;
}


// public insert: refer to textbook, Figure 4.17, Line 12 - 15
template<typename Comparable>
void BST<Comparable>::insert(const Comparable & x)
{
	insertHelper(x, root);
}



template<typename Comparable>
void BST<Comparable>::insertHelper(const Comparable & x, BinaryNode *& thisRoot)
{
	if(thisRoot == nullptr)
	{
		thisRoot = new BinaryNode(x, nullptr, nullptr);
	}
	else if(thisRoot->element > x) // go left
	{
		insertHelper(x, thisRoot->left);
	}
	else if(thisRoot->element < x)
	{
		insertHelper(x, thisRoot->right);
	}
}

// public remove: refer to textbook, Figure 4.17, Line 20 - 23
template<typename Comparable>
void BST<Comparable>::remove( const Comparable & x )
{
	if(this->contains(x))
	{
		removeHelper(x, root);
	}
	else
	{
		// throw error or print output error?
		cout << "Element not found-" << endl;
	}
}

template<typename Comparable>
void BST<Comparable>::removeHelper(const Comparable &x, BinaryNode *&t)
{
	if(t->element == x)
	{

	}
	else if(t->element > x)
	{
		removeHelper(x, root->left);
	}else if(t->element < x)
	{
		removeHelper(x, root->right);
	}
}
// public treeSize
template <typename Comparable>
int BST<Comparable>::treeSize() const
{
	return treeSizeHelper(root);
}
template<typename Comparable>
int BST<Comparable>::treeSizeHelper(BinaryNode *t) const
{
	if(t)
	{
		return 1 + treeSizeHelper(t->left) + treeSizeHelper(t->right);
	}else
	{
		return 0;
	}
}

// public treeHeight
template <typename Comparable>
int BST<Comparable>::treeHeight() const {
	return treeHeightHelper(root);
}

template<typename Comparable>
int BST<Comparable>::treeHeightHelper(BinaryNode *t) const
{
	if(!t)
		return -1;

	int leftSide = treeHeightHelper(t->left);
	int rightSide = treeHeightHelper(t->right);

	if(rightSide < leftSide)
	{
		return leftSide + 1;
	}
	return rightSide + 1;
}

// public printInOrder: refer to textbook, Figure 4.60
template<typename Comparable>
void BST<Comparable>::printInOrder() const
{
	printInOrderHelper(root);
}
template<typename Comparable>
void BST<Comparable>::printInOrderHelper(const BinaryNode *t) const
{
	if(t)
	{
		printInOrderHelper(t->left);
		cout <<  t->element << " -> ";
		printInOrderHelper(t->right);
	}
}
// public printLevels
template <typename Comparable>
void BST<Comparable>::printLevels() const {
	cout << "**TODO**: printLevels function" << endl;
}

// public printMaxPath
template <typename Comparable>
void BST<Comparable>::printMaxPath() const {
	cout << "**TODO**: printMaxPath function" << endl;
}

#endif
