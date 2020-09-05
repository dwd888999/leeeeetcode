

/*
    ������������ת��Ϊ������ѭ��˫������
*/

// ����˼·��
// 1�� �������������
// 2�� ˫��pre->right = cur, cur->left = pre;
// 3�� ѭ����head->left = tail  tail->right = head;

// ������һ���ڵ㼴Ϊhead�ڵ㣬���һ���ڵ㼴Ϊtail�ڵ�
// �Ҳ� �������ٻ��� 2020-09-05 19��41
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

