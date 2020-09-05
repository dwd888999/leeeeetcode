

/*
    将二叉搜索树转换为递增的循环双向链表
*/

// 解题思路：
// 1、 递增：中序遍历
// 2、 双向：pre->right = cur, cur->left = pre;
// 3、 循环：head->left = tail  tail->right = head;

// 遍历第一个节点即为head节点，最后一个节点即为tail节点
// 我猜 她还会再回来 2020-09-05 19：41
//

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val){
        val = _val;
        left = nullptr:
        right = nullptr
    }

    Node(int _val, Node* _left, Node* _right){
        val = _val;
        left = _left;
        right = _right;
    }

};


class Solution{
public:
    Node* prev;
    Node* head;
    Node* treeToDoubleyList(Node* root){
        if(root == nullptr) return root;
        prev = nullptr;
        dfs(root);
        head->left = prev;
        prev->right = head;
        return head;
    }
    void dfs(Node* root){
        if(root == nullptr) return;
        dfs(root->left);
        if(prev == NULL){
            head = root;
        }else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        dfs(root->right);
    }
}

