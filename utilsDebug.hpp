#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct listLog{
    T _num;
    string _stepFlag;
    listLog(T num, string stepFlag){
        this->_num = num;
        this->_stepFlag = stepFlag;
    }
};

template<typename T>
class debugList{
    private:
        bool _status = false;
        vector<listLog<T>> _list;
    public:

void debugStep(T arg, string stepFlag){
    if (this->_status == false) {
        return;
    }
    listLog<T> temp= listLog<T>(arg, stepFlag);
    this->_list.emplace_back(temp);
}

void printDebugLog() {
    if (this->_status == false) {
        return;
    }
    cout << "Debug Log: \n";
    for (auto i : this->_list) {
        cout << i._num << ". " << i._stepFlag << '\n';
    }
}

void setDebugStatus(bool status) {
    this->_status = status;
}

~debugList() {
    if (this->_status == true) {
        printDebugLog();
    }
}

};
