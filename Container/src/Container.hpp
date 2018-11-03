#ifndef _Container_
#define _Container_

#include <set>

template <class T>
class Container {
    public:
        Container() {}
        Container(const Container<T>&);
        ~Container() {}

        bool insert(const T&);
        bool erase(const T&);

        void clear();
    private:
        std::set<T> _data;
};


Container::Container(const Container<T>& src) {
    this->_data = src;
}

bool Container::insert(const T& item) {
    return _data.insert(item).second;
}

bool Container::erase(const T& item) {
    return this->_data.erase(item) != 0 ;
}

void Container::clear() {
    this->_data.clear();
}
#endif