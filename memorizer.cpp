#include "memorizer.hpp"

void memorizer::append_new_character(char new_data)
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

int memorizer::check_node(node* n)
{
    int test = 0;
    if ((n->prev_node != NULL) && (n->next_node != NULL))
    {
        test = 1;
    }
    return test;
}

void memorizer::swap_nodes(node* a, node* b)
{

    if (check_node(a) && check_node(b))
    {
        node * apn, * ap, * an, * anp;
        
        { //protected access
            std::unique_lock<std::mutex> lock(m_mutex); 
            //insert
            (a->prev_node)->next_node = a->next_node;
            (a->next_node)->prev_node = a->prev_node;


        } //end protected access
        
    }
}

node* memorizer::find_lowest()
{
    node* inspect = head;
    node* lowest_value = head;
    for (int i = 1; i < len; i++)
    {
        inspect = inspect->next_node;
        if (inspect->data < lowest_value->data)
        {
            lowest_value = inspect;
        }
    }
    return lowest_value;
}

void memorizer::selection_sort()
{
    node* increment = head;
    for (int i = 1; i < len; i++)
    {
        swap_nodes(increment, find_lowest());
        increment = increment->next_node;
    }
}

void memorizer::swap_first_two()
{

    swap_nodes(head, head->next_node);
}

void memorizer::debug_show_memory()
{
    //node* current_node;
    //current_node = head;

    //for (int i=0; i<len; i++)
    //{
        //printf("%c %c", head->data, (head->next_node)->data);
        //current_node = current_node->next_node;
    //}
    //printf("\n");
}