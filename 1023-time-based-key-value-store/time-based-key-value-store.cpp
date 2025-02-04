class TimeMap {
public:
    map<pair<string,int>,string> t;
   
    TimeMap() {
        t.clear();
    }
    
    void set(string key, string value, int timestamp) {
        t[{key,timestamp}] = value;
        
    }
    
    string get(string key, int timestamp) {
        auto it = t.upper_bound({key,timestamp});
        if (it == t.begin()){
            return "";
        }
        // if(it!=t.end()){
            --it;
            if(it->first.first==key){
                return it->second;
            }else return "";
        // }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */