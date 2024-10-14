

#include <iostream>
#include <limits>
#include <vector>
using namespace std;


template <typename Comparable>
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();

    void makeEmpty();
    const Comparable & findMin() const;
    const Comparable & findMax() const;

    bool contains(const Comparable & x) const;
    void insert(const Comparable & x);
    void remove(const Comparable & x);
    int treeSize() const;




    int computeHeight() const;
    int readRootHeight() const;
    bool isBalanced() const;
    bool isBST() const;

    double averageDepth() const;
    void removeByRank(int rank);

    // the next line follows textbook Figure 4.42, Line 19
    static const int ALLOWED_IMBALANCE = 1;
private:
    struct AVLNode  // refer to textbook, Figure 4.40
    {
        Comparable element;
        AVLNode *left;
        AVLNode *right;
        int height;

        AVLNode( const Comparable & theElement, AVLNode *lt, AVLNode *rt ): element(theElement), left(lt), right(rt) {}
        AVLNode( Comparable && theElement, AVLNode *lt, AVLNode *rt ): element(move(theElement)), left(lt), right(rt) {}
    };

    AVLNode *root;
    AVLNode * findMin( AVLNode * t ) const;
    AVLNode * findMax( AVLNode * t ) const;
    bool containsHelper( const Comparable & theElement, AVLNode* node) const;
    void insertHelper( const Comparable & theElement, AVLNode*& node );
    void removeHelper( const Comparable & theElement, AVLNode*& node );
    void isBSTHelper(AVLNode* node, vector<Comparable> &nodeElements) const;
    bool isBalancedHelper(AVLNode* node) const;
    int treeSizeHelper(AVLNode *t) const;
    int sumHeight(AVLNode* node) const;
    int computeHeightHelper(AVLNode* node) const;
    void removeByRankHelper(AVLNode* node, int rank);
    void makeEmpty( AVLNode * & t );
    void balance(AVLNode * & t);
    void rotateWithLeftChild( AVLNode * & k2 );
    void rotateWithRightChild( AVLNode * & k2 );
    void doubleWithLeftChild( AVLNode * & k3);
    void doubleWithRightChild( AVLNode * & k3);
};

// constructor
template <class Comparable>
AVLTree<Comparable>::AVLTree() : root(NULL) {}

// destructor
template <class Comparable>
AVLTree<Comparable>::~AVLTree()
{
    makeEmpty();
}

// public makeEmpty: follow the makeEmpty in BST, referring to textbook, Figure 4.27
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty() {
    makeEmpty(root);
}

// private recursive makeEmpty: follow the makeEmpty in BST, referring to textbook, Figure 4.27
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty(AVLNode * & t) {
    if ( t != NULL ) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
}

// public findMin: follow the findMin in BST, referring to textbook, Figure 4.20
template <typename Comparable>
const Comparable & AVLTree<Comparable>::findMin() const {
    if (root == NULL) {
        throw underflow_error("Tree is empty");
    }
    return findMin(root)->element;
}



// private findMin: follow the findMin in BST, referring to textbook, Figure 4.20
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode* AVLTree<Comparable>::findMin(AVLNode * t) const
{
    if ( t == NULL ) {
        return NULL;
    } else if (t->left == NULL)
{
        return t;
    } else {
        return findMin(t->left);
    }
}

// public findMax: follow the findMax in BST, referring to textbook, Figure 4.21
template <typename Comparable>
const Comparable & AVLTree<Comparable>::findMax() const {
    if (root == NULL) {
        throw underflow_error("Tree is empty");
    }
    return findMax(root)->element;
}

// private findMax: follow the findMax in BST, referring to textbook, Figure 4.21
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode* AVLTree<Comparable>::findMax(AVLNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->right == NULL) {
        return t;
    } else {
        return findMax(t->right);
    }
}

// start our implementation:
// public contains: follow the contains in BST, referring to textbook, Figure 4.17 and Figure 4.18
template<typename Comparable>
bool AVLTree<Comparable>::contains( const Comparable & x ) const
{
    return containsHelper(x, root);
}

template<typename Comparable>
bool AVLTree<Comparable>::containsHelper(const Comparable &theElement, AVLNode *node) const
{
    if(node)
    {
        if(node->element == theElement)
        {
            return true;
        }
        if(node->element > theElement)
        {
            return containsHelper(theElement, node->left);
        }
        if(node->element < theElement)
        {
            return containsHelper(theElement, node->right);
        }
    }
    return false;
}

// public insert: following BST, referring to textbook, Figure 4.17 and Figure 4.23
template<typename Comparable>
void AVLTree<Comparable>::insert(const Comparable & x)
{
    insertHelper(x, root);
}

template<typename Comparable>
void AVLTree<Comparable>::insertHelper(const Comparable &theElement, AVLNode *&node) // add balance
{
    if(!node)
    {
        node = new AVLNode(theElement, nullptr, nullptr);
        return;
    }
    if(node->element > theElement)
    {
        insertHelper(theElement, node->left);
    }else if (node->element < theElement)
    {
        insertHelper(theElement, node->right);
    }
    balance(node);
    node->height = max(node->left ? node->left->height : -1, node->right ? node->right->height : -1) + 1;
}

// public remove: refer to textbook, Figure 4.17 and Figure 4.26
template<typename Comparable>
void AVLTree<Comparable>::remove( const Comparable & x )
{
    removeHelper(x, root);
}

template<typename Comparable>
void AVLTree<Comparable>::removeHelper(const Comparable &theElement, AVLNode *&node)
{
    if(!node)
    {
        return;
    }
    if(node->element > theElement)
    {
        removeHelper(theElement, node->left);
    }else if (node->element < theElement)
    {
        removeHelper(theElement, node->right);
    }else if (node->element == theElement)
    {
        if(!node->left && !node->right)
        {
            delete node;
            node = nullptr;
        }else if(!(node->left && node->right)) // One child
        {
            const AVLNode* temp = node; // Need a temp to avoid dangling pointers/memory leak
            if(node->left)
            {
                node = node->left;
            }else
            {
                node = node->right;
            }
            delete temp;
        }else // Two children
        {
            node->element = findMin(node->right)->element;
            removeHelper(node->element, node->right);
        }
    }
    balance(node);
}

// private balance: refer to textbook, Figure 4.42, Line 21 - 40
// assume t is the node that violates the AVL condition, and we then identify which case to use (out of 4 cases)
template<typename Comparable>
void AVLTree<Comparable>::balance(AVLNode * & t)
{
    if(!t)
    {
        return;
    }
    int leftHeight = t->left ? t->left->height : -1;
    int rightHeight = t->right ? t->right->height : -1;
    int leftLeftHeight = t->left && t->left->left ? t->left->left->height : -1;
    int leftRightHeight = t->left && t->left->right ? t->left->right->height : -1;
    int rightLeftHeight = t->right && t->right->left ? t->right->left->height : -1;
    int rightRightHeight = t->right && t->right->right ? t->right->right->height : -1;

    if (leftHeight - rightHeight > ALLOWED_IMBALANCE) {
        if (leftLeftHeight >= leftRightHeight) {
            rotateWithLeftChild(t);
        } else {
            doubleWithLeftChild(t);
        }
    } else if (rightHeight - leftHeight > ALLOWED_IMBALANCE) {
        if (rightRightHeight >= rightLeftHeight) {
            rotateWithRightChild(t);
        } else {
            doubleWithRightChild(t);
        }
    }
    t->height = max(leftHeight, rightHeight) + 1;
}

// private rotateWithLeftChild: for case 1, referring to textbook, Figure 4.44 (code) and Figure 4.43 (visualization)
template<typename Comparable>
void AVLTree<Comparable>::rotateWithLeftChild(AVLNode * & k2) // Some subtree
{
    if(!k2->left)
    {
        return;
    }
    AVLNode* leftChild = k2->left; // Perform links before changing k2 identity
    k2->left = leftChild->right; // Set leftChild's right node to the old roots left child.
    leftChild->right = k2; // Set k2 to leftChild's right child
    k2->height = max(k2->left ? k2->left->height : -1, k2->right ? k2->right->height : -1 ) + 1;
    leftChild->height = max( leftChild->left ? leftChild->left->height : -1 , k2->height ) + 1; // change depth
    k2 = leftChild; // Links are set - make leftChild the new root
}

template<typename Comparable>
void AVLTree<Comparable>::rotateWithRightChild(AVLNode * & k2)
{
    if (!k2->right)
    {
        return;
    }
    AVLNode* rightChild = k2->right;
    k2->right = rightChild->left;
    rightChild->left = k2;
    k2->height = max(k2->left ? k2->left->height : -1, k2->right ? k2->right->height : -1) + 1;
    rightChild->height = max(rightChild->left ? rightChild->left->height : -1, rightChild->right ? rightChild->right->height : -1) + 1;
    k2 = rightChild;
}

// private doubleWithLeftChild: for case 2, see textbook, Figure 4.46 (code) and Figure 4.45 (visualization)
template<typename Comparable>
void AVLTree<Comparable>::doubleWithLeftChild(AVLNode * & k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

// private doubleWithRightChild: for case 3 (the mirrored case of case 2)
template<typename Comparable>
void AVLTree<Comparable>::doubleWithRightChild(AVLNode * & k3)
{
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

// public isBalanced
template <class Comparable>
bool AVLTree<Comparable>::isBalanced() const
{
   return isBalancedHelper(root);
}

template<typename Comparable>
bool AVLTree<Comparable>::isBalancedHelper(AVLNode *node) const
{
    if(!node)
    {
        return true;
    }
    bool leftB = isBalancedHelper(node->left);
    bool rightB =  isBalancedHelper(node->right);
    int leftH = computeHeightHelper(node->left);
    int rightH = computeHeightHelper(node->right);
    if(leftH - rightH > ALLOWED_IMBALANCE || leftH - rightH < -ALLOWED_IMBALANCE || !leftB || !rightB)
    {
        return false;
    }
    return true;
}
// public isBST
template <class Comparable>
bool AVLTree<Comparable>::isBST() const
{
    vector<Comparable> nodeElements;
    isBSTHelper(root, nodeElements);
    for(int i = 0; i + 1 < nodeElements.size(); i++)
    {
        if(nodeElements[i] > nodeElements[i + 1]) // Make sure nodes are inOrder
        {
            return false;
        }
    }
    return true;
}

template<typename Comparable>
void AVLTree<Comparable>::isBSTHelper(AVLNode *node, vector<Comparable> &nodeElements) const
{
    if(!node)
    {
        return;
    }
    isBSTHelper(node->left, nodeElements); // Insert into vector inOrder
    nodeElements.push_back(node->element);
    isBSTHelper(node->right, nodeElements);
}

// public treeSize
template <typename Comparable>
int AVLTree<Comparable>::treeSize() const
{
    return treeSizeHelper(root);
}

template<typename Comparable>
int AVLTree<Comparable>::sumHeight(AVLNode* node) const
{
    if(!node)
    {
        return 0;
    }
    return node->height + sumHeight(node->left) + sumHeight(node->right);
}

template<typename Comparable>
int AVLTree<Comparable>::treeSizeHelper(AVLNode *t) const
{
    if(t)
    {
        return 1 + treeSizeHelper(t->left) + treeSizeHelper(t->right);
    }
    return 0;
}

// Public computeHeight. See Figure 4.61 in Textbook
template <typename Comparable>
int AVLTree<Comparable>::computeHeight() const
{
    return computeHeightHelper(root);
}
template<typename Comparable>
int AVLTree<Comparable>::computeHeightHelper(AVLNode *node) const
{
        if(!node)
            return -1;
        int leftSide = computeHeightHelper(node->left);
        int rightSide = computeHeightHelper(node->right);
        if(rightSide < leftSide)
        {
            return leftSide + 1;
        }
        return rightSide + 1;
}

// public readRootHeight
template <typename Comparable>
int AVLTree<Comparable>::readRootHeight() const
{
    return root->height;
}

// public averageDepth
template <typename Comparable>
double AVLTree<Comparable>::averageDepth() const
{
    if(!root || this->treeSize() == 0)
    {
        return 0.0;
    }
    return static_cast<double>(sumHeight(root)) / static_cast<double>(treeSize());
}

// public removeByRank
template <typename Comparable>
void AVLTree<Comparable>::removeByRank(int rank)
{
    removeByRankHelper(root, rank);
}

template<typename Comparable>
void AVLTree<Comparable>::removeByRankHelper(AVLNode *node, int rank)
{
    if(!node)
    {
        return;
    }
    int currentRank = treeSizeHelper(node->left);
    if(currentRank == rank)
    {
        this->remove(node->element);
    }else if(currentRank > rank)
    {
        removeByRankHelper(node->left, rank);
    }else
    {
        removeByRankHelper(node->right, rank - currentRank - 1);
    }
}
