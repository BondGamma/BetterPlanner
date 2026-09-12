#ifndef TASK_HPP
#define TASK_HPP

class Task{
    public:
        std::string m_value;
        Task* next;

        Task(std::string_view value)
            : m_value(value), next(nullptr)
        {
        }
};
#endif
