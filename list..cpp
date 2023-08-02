#include <iostream>

template <class T>
class Cell
{
public:
    operator ++(){ }
    operator --(){ }

    void getValue()
    {

    }

    T* value;
    T* m_previous;
    T* m_next;
};

template <class T>
class List
{
public:
    List()
    {

    }
    
    List(const List<T>& list)
    {
        ///while(){...}
    }

    List( List<T>&& list){
        front = list.front;
        list.front = nullptr;
    };

    void push_back(T val)
    {

    }
    void push_front(T val)
    {

    }

    void pop_back(){

    }

    size_t getSize()
    {

    }

    Cell<T> getCell()
    {

    }
    
    


private:
    Cell<T> front;

    size_t size;
};

int main()
{
    return 0;
}
