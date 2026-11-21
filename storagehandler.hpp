#ifndef STRGINTERFACE_HPP
#define STRGINTERFACE_HPP

#include <vector>
#include <string>
#include <limits>
#include <stdexcept>


template <typename T>
class StorageInterface
{
    protected: 
        StorageInterface() = default;

    private:
        std::vector<T> elements;
    
    public:
        virtual ~StorageInterface() = default;
        virtual std::vector<T>& getElements();
        virtual T& getElement(int index);
        virtual void addElement(T element);
        virtual bool deleteElement(int index);
};

template <typename T>
std::vector<T>& StorageInterface<T>::getElements(){
    try
    {
        return elements;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Can't return elements: " << e.what() << std::endl;
    }
}

template <typename T>
T& StorageInterface<T>::getElement(int index){
    return elements.at(index);
}

template <typename T>
void StorageInterface<T>::addElement(T element){
    try
    {
        elements.push_back(element);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error when adding: " << e.what() << std::endl;
    }
}

template <typename T>
bool StorageInterface<T>::deleteElement(int index){
    try
    {
        elements.erase(elements.begin() + index);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Cant access the element: " << e.what() << std::endl;
        std::cerr << "The max container size: " << elements.size() << std::endl;
    }
}

#endif