class BrowserHistory {
public:
    list<string>nodes;
    list<string>::iterator it;
    BrowserHistory(string homepage) {
        nodes.push_back(homepage);
        it = nodes.begin();
    }
    
    void visit(string url) {
        auto temp = it;
        temp++;
        nodes.erase(temp,nodes.end());
        nodes.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(steps-- && it!=nodes.begin()){
            it--;
        }
        return *it;
    }
    
    string forward(int steps) {
        while(steps-- && it!=--nodes.end()){
            it++;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */