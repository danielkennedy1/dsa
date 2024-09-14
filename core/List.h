#ifndef LIST_H
#define LIST_H
template <typename T>
class List {
public:
    List();
    ~List();
    virtual void append(T value) = 0;
    virtual T get(int index) = 0;
    virtual void remove(int index) = 0;
};

#endif
