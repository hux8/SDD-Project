#ifndef _Container_
#define _Container_

#include <set>

/**
 * Overview:
 * A wrapper of the stl set container, makes manipulating the set easier.
 * This container works for any class that has operator< defined. Items
 * inserted in this container are automatically sorted.
 * 
 * Accessors:
 * Container::size()
 * 
 * Modifiers:
 * Container::insert()
 * Container::erase()
 * Container::clear()
 */
template <class T> class Container {
    public:
        /**
         * The default constructor
         */
        Container() {}

        /**
         * The copy constructor
         * 
         * @param src: the container we are copying from
         * @modifies: this->_data
         */        
        Container(const Container<T>& src) {this->_data = src;}
        
        /**
         * The destructor
         */        
        ~Container() {}

        /**
         * Inserts an item into the container
         * 
         * @param item: the item being inserted
         * @modifies: this->_data
         * @effect: if item is not in container, then it is added
         * @returns: TRUE if insertion is success, FALSE if item already exists
         */
        bool insert(const T& item) {return _data.insert(item).second;}

        /**
         * Removes an item from the container
         * 
         * @param item: the item being removed
         * @modifies: this->_data
         * @effect: removes item from the container
         * @returns: TRUE if removed, FALSE if item does not exist
         */        
        bool erase(const T& item) {return this->_data.erase(item) != 0 ;}

        /**
         * Counts number of items inside the container
         * 
         * @returns: this->_data.size()
         */        
        int size() {return this->_data.size();}

        /**
         * Clears the container
         * 
         * @modifies: this->_data
         * @effect: after calling this function, _data will be empty
         */        
        void clear() {this->_data.clear();}

    private:
        std::set<T> _data;
};

#endif