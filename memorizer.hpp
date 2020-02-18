#pragma once
#include <iostream>
#include <string>
#include <mutex>
#include <condition_variable>
/*
Memorizer creates a circular buffer of up to length 'max_length' to store 
generated characters. 
The add_new_character function will be activated by the generator to store
new characters. 
The return_last(n) function returns the last n characters as an array which 
can be printed
*/

struct node
{
    char data;
    node* next_node;
    node* prev_node;
};


class memorizer 
{
    public:
        
        memorizer() : len(0)
        {}
        ~memorizer()
        {}

        void add_new_character(char new_data);
        int get_last(char* list, int length);


    private:
        mutable std::mutex m_mutex;
        static const int max_length = 10;
        int len;
        node* head;
        node* tail;      

};