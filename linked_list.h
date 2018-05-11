/*
 *  linked_list.h
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

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#ifdef __cplusplus
extern "C" {
#endif
typedef struct linked_list linked_list_t;

linked_list_t* linked_list_new(void);
int linked_list_delete(linked_list_t* instance);
int linked_list_add_at_first(linked_list_t* instance, void* data);
int linked_list_add_at_end(linked_list_t* instance, void* data);
int linked_list_insert_at_index(linked_list_t* instance, void* data, unsigned int idx);
int linked_list_remove_first(linked_list_t* instance);
int linked_list_remove_last(linked_list_t* instance);
int linked_list_remove_from_index(linked_list_t* instance, unsigned int idx);
int linked_list_get_first(linked_list_t* instance, void** data_out);
int linked_list_get_last(linked_list_t* instance, void** data_out);
int linked_list_get_from_index(linked_list_t* instance, unsigned int idx, void** data_out);
unsigned int linked_list_size(linked_list_t* instance);

#ifdef __cplusplus
}
#endif
#endif /* LINKED_LIST_H_ */
