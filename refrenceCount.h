#ifndef MEMORY_SMART_POINTERS_ELANAFELSI_REFRENCECOUNT_H
#define MEMORY_SMART_POINTERS_ELANAFELSI_REFRENCECOUNT_H

class ReferenceCount
{
public:
    ReferenceCount();

    void Increment();

    int Decrement();

    int GetCount() const;


private:
    int m_RefCount;
};

inline void ReferenceCount::Increment()
{
    ++m_RefCount;
}

inline int ReferenceCount::Decrement()
{
    return --m_RefCount;
}

int ReferenceCount::GetCount() const
{
    return m_RefCount;
}

ReferenceCount::ReferenceCount(): m_RefCount(0) {}


#endif //MEMORY_SMART_POINTERS_ELANAFELSI_REFRENCECOUNT_H
