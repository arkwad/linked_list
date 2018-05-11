/*
 * linked_list.c
 *
 *  Created on: 09.05.2018
 *      Author: Arkadiusz Wadowski
 *		Email: wadowski.arkadiusz@gmail.com
 *
 *  Copyright (c) 2018, Arkadiusz Wadowski
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#include "linked_list.h"
#include "stddef.h"
#include "stdlib.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct node {
    void* data;
    struct node* next;
    struct node* previous;
} node_t;

struct linked_list {
    unsigned int items;
    node_t* head;
    node_t* tail;
};

linked_list_t* linked_list_new(void)
{
     linked_list_t* instance = (linked_list_t*)malloc(sizeof(linked_list_t));

     // null check
     if(!instance) {
         return instance;
     }
     // empty instance
     instance->head = NULL;
     instance->tail = NULL;
     instance->items = 0;

     return instance;
}

int linked_list_delete(linked_list_t* instance)
{
    // check if instance is valid
    if (!instance) {
        return -1;
    }
    // first remove all members
    while (instance->items) {
        linked_list_remove_first(instance);
    }
    // release memory allocated for instance structure
    free(instance);
    return 0;
}

int linked_list_add_at_first(linked_list_t* instance, void* data)
{
    // check if instance is valid
    if (!instance) {
        return -1;
    }
    node_t* node = (node_t*)malloc(sizeof(node_t));

    if (!node) {
        return -1;
    }
    // fill new member with required information
    node->data = data;
    node->next = instance->tail;
    node->previous = NULL;

    // update instance data
    instance->tail = node;
    // if first member added - tail and head are the same objects
    if (!instance->items) {
        instance->head = instance->tail;
    } else {
        // update previous member in list with information about current head
        instance->tail->next->previous = instance->tail;
    }
    instance->items++;
    return 0;
}

int linked_list_add_at_end(linked_list_t* instance, void* data)
{
    // check if instance is valid
    if (!instance) {
        return -1;
    }
    node_t* node = (node_t*)malloc(sizeof(node_t));

    if (!node) {
        return -1;
    }

    // fill new member with required information
    node->data = data;
    node->next = NULL;
    node->previous = instance->head;
    // update instance data
    instance->head = node;
    // if first element added - tail and head are the same objects
    if (!instance->items) {
        instance->tail = instance->head;
    } else {
        // update previous element with information about current head
        instance->head->previous->next = instance->head;
    }
    instance->items++;

    return 0;
}

int linked_list_insert_at_index(linked_list_t* instance, void* data, unsigned int idx)
{
    // check if instance is valid
    if (!instance) {
        return -1;
    }

    if (!idx) {
        return linked_list_add_at_first(instance, data);
    } else if ((idx + 1) <= instance->items) {
        unsigned int i = 0;
        node_t* old_node = instance->tail;
        node_t* new_node = (node_t*)malloc(sizeof(node_t));

        if (!new_node) {
            return -1;
        }
        while(i != idx) {
            old_node = old_node->next;
            i++;
        }
        // fill new member with required information
        new_node->previous = old_node->previous;
        new_node->next = old_node;
        new_node->data = data;
        // update next member information in previous member in list
        new_node->previous->next = new_node;
        // update previous member information in next member in list
        old_node->previous = new_node;
        instance->items++;
    } else {
        // add entry at first empty place
        return linked_list_add_at_end(instance, data);
    }
    return 0;
}

int linked_list_remove_first(linked_list_t* instance)
{
    // check if instance is valid
    if (!instance) {
        return -1;
    }
    // list is empty - nothing to do
    if (!instance->items) {
        return 0;
    } else if (instance->items == 1) {
        // just one member in list
        free(instance->tail);
        instance->tail = NULL;
        instance->head = instance->tail;
        instance->items = 0;
    } else {
        // move tail to next member
        instance->tail = instance->tail->next;
        // free old tail
        free(instance->tail->previous);
        instance->tail->previous = NULL;
        instance->items--;
    }
    return 0;
}

int linked_list_remove_last(linked_list_t* instance)
{
    // check if instance is valid
    if (!instance) {
        return -1;
    }
    // list is empty - nothing to do
    if (!instance->items) {
        return 0;
    } else if (instance->items == 1) {
        // just one member in list
        free(instance->head);
        instance->head = NULL;
        instance->tail = instance->head;
        instance->items = 0;
    } else {
        // move head to previous member
        instance->head = instance->head->previous;
        // free old head
        free(instance->head->next);
        instance->head->next = NULL;
        instance->items--;
    }
    return 0;
}

int linked_list_remove_from_index(linked_list_t* instance, unsigned int idx)
{
    // check if instance is valid
    if (!instance) {
        return -1;
    }

    // list is empty - nothing to do
    if (!instance->items) {
        return 0;
    } else if (instance->items == 1){
        return linked_list_remove_first(instance);
    } else if ((idx + 1) <= instance->items) {
        unsigned int i = 0;
        node_t* node_to_remove = instance->tail;

        while (i != idx) {
            node_to_remove = node_to_remove->next;
            i++;
        }
        node_to_remove->previous->next = node_to_remove->next;
        node_to_remove->next->previous = node_to_remove->previous;
        free(node_to_remove);

        instance->items--;
    } else {
        // add entry at first empty place
        return linked_list_remove_last(instance);
    }
    return 0;
}

int linked_list_get_first(linked_list_t* instance, void** data_out)
{
    // check if instance is valid
    if (!instance) {
        return -1;
    }
    // list is empty - nothing to do
    if (!instance->items) {
        data_out = NULL;
        return -1;
    } else {
        *data_out = instance->tail->data;
        return 0;
    }
}

int linked_list_get_last(linked_list_t* instance, void** data_out)
{
    // check if instance is valid
    if (!instance) {
        return -1;
    }
    // list is empty - nothing to do
    if (!instance->items) {
        data_out = NULL;
        return -1;
    } else {
        *data_out = instance->head->data;
        return 0;
    }
}

int linked_list_get_from_index(linked_list_t* instance, unsigned int idx, void** data_out)
{
    // check if instance is valid
    if (!instance) {
        return -1;
    }
    // list is empty - nothing to do or index is out of range
    if ((!instance->items) || (idx + 1 > instance->items)) {
        data_out = NULL;
        return -1;
    } else {
        unsigned int i = 0;
        node_t* wanted_node = instance->tail;

        while (i != idx) {
            wanted_node = wanted_node->next;
            i++;
        }
        *data_out = wanted_node->data;
        return 0;
    }
}

unsigned int linked_list_size(linked_list_t* instance)
{
    // check if instance is valid
    if (!instance) {
        return -1;
    }
    return instance->items;
}

#ifdef __cplusplus
}
#endif
