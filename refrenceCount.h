#ifndef MEMORY_SMART_POINTERS_ELANAFELSI_REFRENCECOUNT_H
#define MEMORY_SMART_POINTERS_ELANAFELSI_REFRENCECOUNT_H

class ReferenceCount
{
public:
    ReferenceCount();

    void Increment();

    unsigned int Decrement();

    unsigned int GetCount() const;


private:
    unsigned int m_RefCount;
};

inline void ReferenceCount::Increment()
{
    ++m_RefCount;
}

inline unsigned int ReferenceCount::Decrement()
{
    return --m_RefCount;
}

unsigned int ReferenceCount::GetCount() const
{
    return m_RefCount;
}

ReferenceCount::ReferenceCount(): m_RefCount(0) {}


#endif //MEMORY_SMART_POINTERS_ELANAFELSI_REFRENCECOUNT_H
