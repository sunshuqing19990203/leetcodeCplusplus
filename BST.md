# BST二叉搜索树

## 1.判断BST的合法性

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//左子树的最深右子树必须小于根值，右子树的最深左子树必须大于根值。同时在递归的时候判断左子树要小于父节点的值，右子树要大于父节点的值即可。
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        bool flag = true;
        if (root->left != NULL) {
            TreeNode* cur = root->left;
            while (cur->right != NULL) 
                cur = cur->right;
            if (root->val <= cur->val || !isValidBST(root->left))
                return false;
        }
        if (root->right != NULL) {
            TreeNode* cur = root->right;
            while (cur->left != NULL) 
                cur = cur->left;
            if (root->val >= cur->val || !isValidBST(root->right))
                return false;
        }
        return true;
    }
};


//方法二：利用BST的中序遍历升序的方法检验是否合法
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   void midSort(vector<TreeNode*> &ret,TreeNode* root){
     if(root!=NULL){
         midSort(ret,root->left);
         ret.push_back(root);
         midSort(ret,root->right);
     }   
    }
    
    bool isValidBST(TreeNode *root) {
        if(root==NULL) return true;
        
        vector<TreeNode*> ret;
        midSort(ret,root);
        
        for(int i=1;i<ret.size();i++){
            if(ret[i]->val<=ret[i-1]->val) return false;
        }
        return true;
    }
};
```



## 2.在BST中搜索一个数

```c++
//利用BST的左子树<root<右子树的特性
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class solution{
public:
    bool isInBST(TreeNode root, int target){
        if(root == nullptr) return false;
        if(root->val == target) return true;
        if(root->val < target) return isInBST(root->right, target);
        else return isInBST(root->left, target);
    }
    
}
```

因此，我们对树遍历框架进行修改，针对BST二叉搜索树的遍历框架为：

```c++
void BSTtravese(TreeNode* root, int target){
    if(root->val == target) //do what?
    if(root->val < target) 
        BSTtravese(root->right, target);
    if(root->val > target)
        BSTtravese(root->left, target);
     
}
```

## 3.在BST中插入一个数

对数据结构的操作无非遍历 + 访问，遍历就是「找」，访问就是「改」。

```c++
/* Definition of Treenode
* struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};
*/

struct TreeNode* insertBST(TreeNode* root, int val){
    if(root == NULL) return new TreeNode(val);
    if(val < root->val) root->left = insertBST(root->left, val);
    if(val > root->val) root->right = insertBST(root->right, val);
    return root;
}
```

## 4.在BST中删除一个数据

```c++
TreeNode getMin(TreeNode* node){
    while(node->left) node = node->left;
    return node;
}
struct TreeNode* deleteBST(TreeNode* root, int target){
    if(root->val == target){
        //delete
        //1.恰好是叶节点,直接删除
        if(root->left == NULL && root->right == NULL)
            return NULL;
        //2.只有一个左子树或右子树
        else if(root->right == NULL) return root->left;
        else if(root->left == NULL) return root->right;
        //3.两个子节点，找到左子树最大的节点（最右节点）或者是右子树最小的节点（最左节点）替代自己
        else{
            TreeNode minNode = getMin(root.right);
            root->val = minNode->val;
            root.right = deleteNode(root.right,minNode->val);
        }

    }
    else if(root->val > target){
       root->left = deleteBST(root->left, target);
    }
    else if(root->val < target){
        root->right = eleteBST(root->right,target);
    }
    return root;
}
```



## 5.树的总结：

1. 如果当前节点会对下面的子节点有整体的影响，一般构造辅助函数传递更多的参数。
2. 在二叉树的递归框架之中，根据BST的中序遍历升序（中序逆序遍历降序）的特性，扩展出一个BST遍历的代码框架可以减少时间复杂度（val== <, > root->val，。