#include "memorizer.hpp"

void memorizer::add_new_character(char new_data)
{
    //printf(", %d", len);
    { //protected access
        std::unique_lock<std::mutex> lock(m_mutex);
        switch(len)
        {
            case 0:
            {
                node* temp = new node;
                temp->data = new_data;
                head = temp;
                tail = temp;
                len = 1;
                //printf("%c\n", head->data);
                break;
            }
            case max_length:
            {
                tail->data = new_data;
                //printf("%c, %c\n", (tail->prev_node)->data, tail->data);
                tail = tail->next_node;
                break;
            }
            default:
            {   
                len++;
                node* temp = new node;
                temp->data = new_data;
                temp->prev_node=tail;
                temp->next_node=head;
                tail->next_node=temp;
                head->prev_node=temp;
                tail = temp;
                //printf("%c, %c\n", (tail->prev_node)->data, tail->data);
                break;
            }
        } //end switch
    } //end protected access
}

int memorizer::get_last(char* list, int length)
{
    int length_check;
    if (length > len)
    {
        length_check = 0;
    }
    else
    {
        { //protected access
            std::unique_lock<std::mutex> lock(m_mutex);
            node* current;
            current = tail;
            for(int i = 0; i < length ; i++)
            {
                list[i] = current->data;
                current = current->prev_node;
            }
            length_check = 1; 
        } //end protected access
    } // end else
    return length_check;
}