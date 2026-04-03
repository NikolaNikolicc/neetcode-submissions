class DynamicArray {
    int length;
    int capacity;
    int[] arr;

    public DynamicArray(int capacity) {
        this.length = 0;
        this.capacity = capacity;
        arr = new int[this.capacity];
    }

    public int get(int i) {
        return this.arr[i];
    }

    public void set(int i, int n) {
        this.arr[i] = n;
    }

    public void pushback(int n) {
        if(this.length + 1 > this.capacity){
            this.resize();
        }
        this.arr[this.length++] = n;
        
    }

    public int popback() {
        return this.arr[--this.length];
    }

    private void resize() {
        this.capacity *= 2;
        int[] newArray = new int[this.capacity];
        for(int i = 0; i < this.capacity / 2; i++){
            newArray[i] = this.arr[i];
        }
        this.arr = newArray;
    }

    public int getSize() {
        return this.length;
    }

    public int getCapacity() {
        return this.capacity;
    }
}
