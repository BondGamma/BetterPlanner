#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "interface.hpp"

class Widget
{
    public:
        virtual ~Widget() = default;
        template <typename T>
        int handleInputOptions(int ch, std::vector<T> container);
};


template <typename T>
int Interface::handleInputOptions(int ch, std::vector<T>& container){
    switch (ch)
    {
    case 'q':
        return -2;

    case KEY_UP:
        if (m_selected > 0){
            --m_selected;
        }
        break;
    case KEY_DOWN:
        if (m_selected + 1 < static_cast<int>(container.size())){
            ++m_selected;
        }
        break;
    case '\n':

    case KEY_ENTER:
        return m_selected;
    }
    return -1;
}

#endif