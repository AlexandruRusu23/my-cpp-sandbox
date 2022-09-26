#include <stack>

class MyQueue
{
public:
    std::stack<int> m_container;
    std::stack<int> m_swap;

    MyQueue()
    {
    }

    void push(int x)
    {
        m_container.push(x);
    }

    int internal_pop(bool erase)
    {
        int n = m_container.size();

        while (n-- > 1)
        {
            m_swap.push(m_container.top());
            m_container.pop();
        }

        int output = 0;

        if (m_container.size())
        {
            output = m_container.top();
            if (!erase)
                m_swap.push(output);
            m_container.pop();
        }

        while (!m_swap.empty())
        {
            m_container.push(m_swap.top());
            m_swap.pop();
        }

        return output;
    }

    int pop()
    {
        return internal_pop(true);
    }

    int peek()
    {
        return internal_pop(false);
    }

    bool empty()
    {
        return m_container.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

