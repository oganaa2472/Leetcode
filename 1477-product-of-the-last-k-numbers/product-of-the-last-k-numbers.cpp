class ProductOfNumbers {
public:
    vector<int> pq;
    ProductOfNumbers() {
   
    }
    
    void add(int num) {
        pq.push_back(num);
    }
    
    int getProduct(int k) {
        int s = 1;
        int sz = pq.size();
        for(int i = sz-1;i>=sz-k;i--){
            s=s*pq[i];
        }
        return s;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */