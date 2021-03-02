// class for stack
function Stack(max) {
    this.top = -1;
    this.data = [];
    this.max = max;
}

Stack.prototype = {

    isEmpty: function() {
        return this.top == -1;
    },

    getTop: function() {
        try {
            if (!this.isEmpty())
                return this.data[this.top];
            throw "empty stack";
        } 
        catch (err) {
            return err;
        }
    },

    push: function(e) {
        try {
            if (!this.isFull()) {
                this.data.push(e);
                this.top++;
            }
            else throw "Max Size Reached!!";
            
        }
        catch (err) {
            console.error(err)
        }
    },

    pop: function() {
        try {
            if (!this.isEmpty()) {
                this.data.pop();
                this.top--;
            }
            else throw "Stack empty";
        } catch (err) {
            console.log(err)
        }
    },

    isFull: function() {
        return this.top + 1 == this.max;
    }
}

function main() {
    const s = new Stack(1);
    s.pop();
}

main();