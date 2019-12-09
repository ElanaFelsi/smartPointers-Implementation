#ifndef MEMORY_SMART_POINTERS_ELANAFELSI_SHAREDPOINTER_H
#define MEMORY_SMART_POINTERS_ELANAFELSI_SHAREDPOINTER_H

#include <iostream>
#include "refrenceCount.h"


template <typename T>
class SharedPtr
{
public:
    explicit SharedPtr(T* ptr = NULL);
    SharedPtr(SharedPtr<T> &sp);
    ~SharedPtr();

    T &operator*() const;
    T &operator->() const;

    SharedPtr<T> &operator=(const T *ptr);



private:
    T* m_ptr;
    ReferenceCount* m_ReferenceCount;
};

template<typename T>
SharedPtr<T>::SharedPtr(T *ptr): m_ptr(ptr), m_ReferenceCount(new ReferenceCount())
{
    if(ptr)
        m_ReferenceCount->Increment();
    std::cout << "Created smart_ptr! Ref count is " << m_ReferenceCount->GetCount() << std::endl;
}

#endif //MEMORY_SMART_POINTERS_ELANAFELSI_SHAREDPOINTER_H
