#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printArray(vector<int> arr) {
    for (int x: arr)
        cout << x << " ";
    cout << endl;
}

vector<int> levelOrder(Node *node) {
    vector<int> res;

    queue<Node*> levelNodes;
    levelNodes.push(node);

    while (!levelNodes.empty()) {
        Node* temp = levelNodes.front();

        res.push_back(temp->data);

        if (temp->left)
            levelNodes.push(temp->left);

        if (temp->right)
            levelNodes.push(temp->right);

        levelNodes.pop();
    }

    return res;
}

void topView(struct Node *root) {
    queue<Node*> q;
    queue<int> hd;
    q.push(root);
    hd.push(0);
    unordered_map<int, int> hashMap;
    int min = 0;
    int max = 0;
    
    while (!q.empty()) {
        Node* temp = q.front();
        int d = hd.front();
        q.pop();
        hd.pop();

        if (temp->left != NULL) {
            q.push(temp->left);
            hd.push(d-1);
            if (d-1 < min)
                min = d-1;
        }

        if (temp->right != NULL) {
            q.push(temp->right);
            hd.push(d+1);
            if (d+1 > max)
                max = d+1;
        }
        if (hashMap.find(d) == hashMap.end())
            hashMap[d] = temp->data;
    }
    
    for (int i=min; i<=max; i++) {
        auto node = hashMap.find(i);
        cout << node->second << " ";
    }
}

int main()
{
    int n,i,k;
    cin>>n;
    i=n;

    Node* root=NULL;
    queue <Node*> q;
    while(i>0) {
        int a,b;
        char c;
        cin >> a >> b >> c;
        if(!root){
            root = new Node(a);
            q.push(root);
        }
        Node* pick = q.front();
        q.pop();

        if(c == 'L'){
            pick->left = new Node(b);
            q.push( pick->left );
        }
        cin>> a >> b >> c;
        if(c == 'R'){
            pick->right = new Node(b);
            q.push( pick->right );
        }
        i-=2;
    }

    topView(root);
    return 0;
}

// 10
// 19 2 L 19 30 R 2 1 L 2 17 R 30 25 L 30 48 R 1 -1 N 1 -1 N 17 9 L 17 -1 N

// 6
// 3 5 L 3 4 R 5 5 L 5 -1 N 4 1 L 4 -1 N