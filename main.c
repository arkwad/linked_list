/*
 * main.c
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
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"



int main()
{
    bool s = true;
    bool f = true;
    bool v = s+f;
    static int a = 21;//21;
    static int b = 69;
    static int c = 65;
    static int* out = NULL;
    linked_list_t* list = linked_list_new();
    linked_list_add_at_first(list, (void*)&a);
    linked_list_add_at_end(list, (void*)&b);
    linked_list_insert_at_index(list, (void*)&c, 1);
    linked_list_get_first(list, (void*)&out);
    printf("Out: %i\r\n", *out);
    linked_list_get_last(list, (void*)&out);
    printf("Out: %i\r\n", *out);
    linked_list_get_from_index(list, 0, (void*)&out);
    printf("Out: %i\r\n", *out);
    linked_list_get_from_index(list, 1, (void*)&out);
    printf("Out: %i\r\n", *out);
    linked_list_get_from_index(list, 2, (void*)&out);
    printf("Out: %i\r\n", *out);
    unsigned int d = linked_list_size(list);
    printf("Size: %i\r\n", d);
    linked_list_delete(list);

    return 0;
}
