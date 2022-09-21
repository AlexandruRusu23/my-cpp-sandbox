#include <thread>
#include <mutex>
#include <functional>

class Foo
{
public:
    std::mutex m_first;
    std::mutex m_second;

    Foo()
    {
        m_first.lock();
        m_second.lock();
    }

    void first(std::function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m_first.unlock();
    }

    void second(std::function<void()> printSecond)
    {
        m_first.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m_first.unlock();
        m_second.unlock();
    }

    void third(std::function<void()> printThird)
    {
        m_second.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m_second.unlock();
    }
};

