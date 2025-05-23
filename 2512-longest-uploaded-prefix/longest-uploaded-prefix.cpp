class LUPrefix {
private:
    vector<bool> uploaded;
    int ptr = 1;
public:
    LUPrefix(int n) {
        uploaded = vector<bool>(n + 2, false);
    }

    void upload(int video) {
        uploaded[video] = true;
        while (uploaded[ptr]) ptr++;
    }

    int longest() {
        return ptr - 1;
    }
};
