#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include "memorizer.hpp"

class printer
{
    public: 

        printer() : print_number(0)
        {}
        ~printer()
        {}

    void print();
    void set_print_value(int j);
    void sample_memory();
    void set_memorizer_reference(memorizer* m);

    private:

        mutable std::mutex m_mutex;
        int print_number;
        memorizer* my_memory;
        std::condition_variable m_cond_var;
};