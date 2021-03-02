// Cycle-Detect

/**
 * The idea here is to add the element in the queue.
 * when the element is added the status of that node is changed to -1 which is a pending state
 * take the top element in the queue and change the status of that element to 1
 * push all the non-visited adjacent nodes in the queue
 * while pushing the adjacent node check whether the status of the node is -1.
 * If such condition is encountered then it can be said that a cycle is present in the graph.
 */
class Graph {
    constructor (num, edges) {
        this.list = new Array(num);
        for (let i = 0; i < num; i++) this.list[i] = [];
        for (const [v1, v2] of edges) {
            this.list[v1].push(v2);
            this.list[v2].push(v1);
        }
        this.queue = [];
        /**
         * visited[i] = 0 -> not visited
         * visited[i] = 1 -> visited
         * visited[i] = -1 -> in the queue
         */
        this.visited = new Array(num).fill(0);
    }

    cycleDetect() {
        this.queue.push(0);
        this.visited[0] = -1;

        while (this.queue.length > 0) {
            const top = this.queue[0];
            this.visited[top] = 1;
            this.queue.shift();

            for (const x of this.list[top]) {
                // already present in the queue
                if (this.visited[x] == -1) return true;

                // not visited node
                if (!this.visited[x]) {
                    this.queue.push(x);
                    this.visited[x] = -1;
                }
            }
        }
        return false;
    }
}

function main() {
    // const edges = [
    //     [0, 1],
    //     [0, 2],
    //     [1, 3],
    //     [1, 4], 
    //     [3, 4]
    // ];
    const edges = [
        [0, 4],
        [1, 2],
        [1, 4],
        [2, 3],
        [3, 4]
    ];
    // const edges = [
    //     [0, 1],
    //     [1, 2],
    //     [2, 3]
    // ];

    // find the max vertex
    let max = Number.MIN_VALUE;
    for (const [v1, v2] of edges) {
        max = max < v1 ? v1 : max;
        max = max < v2 ? v2 : max;
    }

    const graph = new Graph(max + 1, edges);
    console.log(graph.cycleDetect());
}

main();
