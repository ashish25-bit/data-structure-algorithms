class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
};

function levelOrder(root) {
    let queue = [];
    queue.push(root);
    let res = [];

    while (queue.length) {
        let top = queue[0];
        queue.shift();
        res.push(top.data);

        if (top.left)
            queue.push(top.left);

        if (top.right)
            queue.push(top.right);
    }
    console.log(res);
}

function printNode([node, status, depth]) {
    const not_last = "├───";
    const last = "└───";
    const space = " ";
    
    if (status)
        console.log(space.repeat(depth) + last + node.data);
    else
        console.log(space.repeat(depth) + not_last + node.data);
}

function isLeafNode(node) {
    return node.left == null && node.right == null ? 1 : 0;
}

function printTree(root) {
    const indent = 4;
    let stack = [];
    stack.push([root, 1, 0]);
    /**
     * [node, last_status, depth]
     * last -> last child of the parent
     * depth -> depth reached 
     */

    // console.log(" ".repeat(depth) + last + root.data)
    while (stack.length) {
        let top = stack[stack.length - 1];
        stack.pop();
        printNode(top);

        if (top[0].right)
            stack.push([
                top[0].right,
                1,
                top[2] + indent
            ]);

        if (top[0].left) {
            const isLeaf = isLeafNode(top[0].left)
            stack.push([
                top[0].left,
                isLeaf && top[0].right != null ? 0 : 1 ,
                top[2] + indent
            ]);
        }
            
    }   
}

function main() {
    const root = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.left = new Node(4);
    root.left.right = new Node(5);
    root.right.right = new Node(6);
    root.right.right.left = new Node(7);
    root.right.right.right = new Node(8);
    
    // levelOrder(root)
    printTree(root)
}

main();
