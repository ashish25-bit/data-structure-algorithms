// BETTER TO USE ADJANCENCY LIST WHEN THE GRAPH IS SPARSE
// FOR UNDIRECTED GRAPH

class Graph {
    constructor (num, edges) {
        this.list = new Array(num);
        for (let i = 0; i < num; i++) this.list[i] = [];
        for (const [v1, v2] of edges) {
            this.list[v1].push(v2);
            this.list[v2].push(v1);
        }
    }
}

class BFS extends Graph {
    constructor (num, edges) {
        super(num, edges);
        this.queue = [];
        this.visited = new Array(num).fill(0);
    }

    traverse() {
        let order = [];
        this.queue.push(0);
    
        while (this.queue.length > 0) {
            const v = this.queue[0];
            this.visited[v] = 1;
            order.push(v);
            this.queue.shift();
    
            for (const x of this.list[v]) {
                if (!this.visited[x]) {
                    this.queue.push(x);
                    this.visited[x] = 1;
                }
            }
        }
        return order;
    }
}

class DFS extends Graph{
    constructor (num, edges) {
        super(num, edges);
        this.stack = [];
        /**
         * this.visited[i] = 0 -> not visited
         * this.visited[i] = 1 -> visited
         * this.visited[i] = -1 -> added to stack but not visited
         */
        this.visited = new Array(num).fill(0);
    }

    traverse() {
        let order = [];
        this.stack.push(0);
        this.visited[0] = -1;

        while (this.stack.length > 0) {
            const top = this.stack[this.stack.length - 1];

            if (this.visited[top] != 1) {
                this.visited[top] = 1;
                order.push(top);
            }

            let adjacent = -1;
            for (let i = 0; i < this.list[top].length; i++) {
                const x = this.list[top][i];
                if (this.visited[x] == 0) {
                    adjacent = x;
                    break;
                }
            }

            if (adjacent == -1) this.stack.pop();
            else {
                this.stack.push(adjacent);
                this.visited[adjacent] = -1;
            }
        }
        return order;
    }
}

function main() {
    const edges = [
        [0, 1],
        [0, 3],
        [1, 2],
        [2, 3], 
        [3, 4],
        [3, 1],
        [2, 4]
    ];

    // find the max vertex
    let max = Number.MIN_VALUE;
    for (const [v1, v2] of edges) {
        max = max < v1 ? v1 : max;
        max = max < v2 ? v2 : max;
    }

    const graph = new BFS(max + 1, edges);
    console.log(`BFS: ${graph.traverse().join(' ')}`);
    
    const graph2 = new DFS(max + 1, edges);
    console.log(`DFS: ${graph2.traverse().join(' ')}`);
}

main();