#ifndef MEMORY_SMART_POINTERS_ELANAFELSI_SHAREDPOINTER_H
#define MEMORY_SMART_POINTERS_ELANAFELSI_SHAREDPOINTER_H

#include <iostream>
#include "refrenceCount.h"


template <typename T>
class SharedPtr
{
public:
    explicit SharedPtr(T* ptr = NULL);
    ~SharedPtr();

    SharedPtr(const SharedPtr<T> &other);
    SharedPtr<T> &operator=(const SharedPtr<T> &other);


    T &operator*();
    T &operator->();


/*    SharedPtr<T> &operator=(const SharedPtr<T> &sp);
    template <typename U>
    SharedPtr<T> &operator=(const SharedPtr<U> &sp); /* for polymorphism Base=Derived */

    /*template <typename U>
    friend class SharedPtr;*/

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

template<typename T>
inline SharedPtr<T>::~SharedPtr()
{
    if(m_ReferenceCount)
    {
        int decCount = m_ReferenceCount->Decrement();
        std::cout << "Destroyed! ref count is " << decCount << std::endl;
    }
    else
    {
        delete m_ReferenceCount;
        delete m_ptr;

        m_ReferenceCount = NULL;
        m_ptr = NULL;
    }
}

template<typename T>
inline SharedPtr<T>::SharedPtr(const SharedPtr<T> &other): m_ptr(other.m_ptr), m_ReferenceCount(other.m_ReferenceCount)
{
    m_ReferenceCount ->Increment();
    std::cout << "Copied! ref count is " << m_ReferenceCount->GetCount() << std::endl;
}

template<typename T>
inline SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr<T> &other)
{
    if(this != &other)
    {
        if(m_ReferenceCount && m_ReferenceCount->Decrement() == 0)
        {
            delete m_ReferenceCount;
            delete m_ptr;
        }

        m_ptr = other.m_ptr;
        m_ReferenceCount = other.m_ReferenceCount;
        m_ReferenceCount->Increment();
    }
    std::cout << "assigning =  ref count is " << m_ReferenceCount->GetCount() << std::endl;
    return *this;
}

template<typename T>
inline T &SharedPtr<T>::operator*() {
    return *m_ptr;
}

template<typename T>
inline T &SharedPtr<T>::operator->() {
    return m_ptr;
}

#endif //MEMORY_SMART_POINTERS_ELANAFELSI_SHAREDPOINTER_H
