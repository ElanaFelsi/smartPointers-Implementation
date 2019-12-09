#ifndef MEMORY_SMART_POINTERS_ELANAFELSI_SHAREDPOINTER_H
#define MEMORY_SMART_POINTERS_ELANAFELSI_SHAREDPOINTER_H

#include <iostream>
#include "refrenceCount.h"


template <typename T>
class shared_ptr
{
public:
    explicit shared_ptr(T* ptr);

private:
    T* m_Object;
    ReferenceCount* m_ReferenceCount;
};

template<typename T>
shared_ptr<T>::shared_ptr(T *ptr): m_Object(ptr), m_ReferenceCount(new ReferenceCount())
{
    if(ptr)
        m_ReferenceCount->Increment();
    std::cout << "Created smart_ptr! Ref count is " << m_ReferenceCount->GetCount() << std::endl;
}

#endif //MEMORY_SMART_POINTERS_ELANAFELSI_SHAREDPOINTER_H