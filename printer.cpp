#include "printer.hpp"

void printer::print()
{

    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        //{
            //std::unique_lock<std::mutex> lock(m_mutex);
            //m_cond_var.wait(lock);
            
        //}
        sample_memory();

    } //end while
}


void printer::sample_memory()
{
    int i = 10;
    char list[i];
    int length_check;

    length_check = my_memory->get_last(list, i);
    if (length_check) 
    {
        for (int j = 0; j < i; j++)
        {
            printf("%c ", list[j]);

        }
            printf("\n"); 
    } //end if 
}

void printer::set_print_value(int j)
{
    
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        print_number = j;
    }
    m_cond_var.notify_one();
}

void printer::set_memorizer_callback(memorizer* m)
{
  my_memory = m;
}