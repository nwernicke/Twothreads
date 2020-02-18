//A Simple C++ Program

#include "Twothreads.hpp"

using namespace std;

int main()
{
  printer p;
  generator g;
  memorizer m;
  g.set_printer_callback(&p);
  g.set_memorizer_callback(&m);
  p.set_memorizer_callback(&m);


  std::thread t1(&printer::print, &p);
  std::thread t2(&generator::generate, &g);

  while(1)
  {


  }
  return 0;


}
