#ifndef _Container_
#define _Container_

#include <set>

template <class T> class Container {
    public:
        Container() {}
        Container(const Container<T>& src) {this->_data = src;}
        ~Container() {}

        bool insert(const T& item) {return _data.insert(item).second;}
        bool erase(const T& item) {return this->_data.erase(item) != 0 ;}
        int size() {return this->_data.size();}
        void clear() {this->_data.clear();}
    private:
        std::set<T> _data;
};

#endif