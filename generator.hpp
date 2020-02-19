#pragma once

#include <iostream>
#include <string>
#include <thread>
#include "printer.hpp"
#include "memorizer.hpp"

class generator
{
    public:

        void generate();
        void set_printer_callback(printer* p);
        void set_memorizer_reference(memorizer* m);

    private:

        printer* my_printer;
        memorizer* my_memory;
        mutable std::mutex m_mutex;
        std::condition_variable m_cond_var;
};