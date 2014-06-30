
#include <string>
#include <iostream>
#include <cassert>

class MyObject
{
public:
    MyObject()
            : m_number(0),
              m_description("-")
    {}

    MyObject(int n, const std::string& d)
            : m_number(n),
              m_description(d)
    {}

    int number() const 
    {
        return m_number;
    }
    std::string description() const
    {
        return m_description;
    }

private:
    int             m_number;
    std::string     m_description;
};

class MyContainer;

class MyIterator
{
public:

    MyIterator(const MyContainer& c, unsigned idx = 0)
            : m_container(c),
              m_index(idx)
    {}

    // Required
    bool operator!=(const MyIterator& other)
    {
        return (m_index != other.m_index);
    }

    // Required
    const MyIterator& operator++()
    {
        m_index++;
        return *this;
    }

    // Required
    MyObject& operator*() const;

private:
    const MyContainer&      m_container;
    unsigned                m_index;
};

class MyContainer
{
public:
    MyContainer(unsigned capacity)
            : m_currentIndex(0),
              m_capacity(capacity),
              m_buffer(new MyObject [m_capacity])
    {}

    void add(const MyObject& obj)
    {
        m_buffer[m_currentIndex++] = obj;
    }

    MyObject& get(unsigned idx) const
    {
        assert(idx < m_currentIndex);

        return m_buffer[idx];
    }

    // Required
    MyIterator begin () const
    {
        return MyIterator(*this, 0);
    }

    // Required
    MyIterator end () const
    {
        return MyIterator(*this, m_currentIndex);
    }

private:
    unsigned                        m_currentIndex;
    unsigned                        m_capacity;
    std::unique_ptr<MyObject[]>     m_buffer;
};


MyObject& MyIterator::operator*() const
{
    return m_container.get(m_index);
}

//

int main(int argc, char* argv[])
{
    MyContainer     cont(10);

    cont.add(MyObject(9, "IX"));
    cont.add(MyObject(56, "LVI"));
    cont.add(MyObject(43, "XLIII"));
    cont.add(MyObject(1984, "MCMXXCIV"));

    for ( auto obj : cont)
    {
        std::cout << obj.number() << ": " << obj.description() << std::endl;
    }

    return 0;
}
