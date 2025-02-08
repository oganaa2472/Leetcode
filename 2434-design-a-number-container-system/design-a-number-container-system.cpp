class NumberContainers {
public:
    unordered_map<int,int> mp;
    multiset<pair<int,int>> mpNumber;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp.find(index)!=mp.end()){
            pair<int,int> m = {mp[index],index};
            mpNumber.erase(m);
        }
        mp[index] = number;
        mpNumber.insert({number,index});
    }
    
    int find(int number) {
        auto it = mpNumber.upper_bound({number,0});
        if(it!=mpNumber.end()&&it->first==number){
            return it->second;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */