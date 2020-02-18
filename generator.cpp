#include "generator.hpp"

void generator::generate()
{
  while(1)
  {
    
    char c;
    c = (rand() % 26) + 97;
    //printf("%c", c);
    //my_printer->set_print_value(i);

    my_memory->add_new_character(c);
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }
}

void generator::set_printer_callback(printer* p)
{
  my_printer = p;
}

void generator::set_memorizer_callback(memorizer* m)
{
  my_memory = m;
}