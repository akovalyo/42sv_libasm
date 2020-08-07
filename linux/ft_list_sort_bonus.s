			section	.text
			global	ft_list_sort
										; rdi = **begin_list, rsi = *cmp
ft_list_sort:
			push	rbp					; estblish frame stack
			mov		rbp, rsp
			push	r15
			push	r13
			push	r14
			mov		r14, [rdi]			; r14 = *begin_list
			mov		r15, rsi			; r15 = *cmp
			cmp 	r14, 0				; check if *begin_list = NULL
			jz		return
			cmp 	r15, 0				; check if *cmp = NULL
			jz		return
						
loop:
			cmp		r14, 0
			jz		return
			mov		r13, [r14 + 8]		; (r13) next_node = *begin_list->next

compare:
			cmp		r13, 0
			jz 		inc_begin
			mov		rdi, [r14]			; rdi = *begin_list->data
			mov		rsi, [r13]			; rsi = next_node->data
			mov		rax, r15			; save pointer to strcmp in rax
			call	rax					; strcmp(begin_list->data, next_node->data);
			cmp		rax, 0
			jnle	swap
			jmp		inc_next

swap:			
			; mov		rax, 1		
			; leave
			; ret	
			mov		rbx, [r14]			; tmp_list = *begin_list->data 
			mov		rcx, [r13]			; tmp_next = next_node->data 
			mov		[r14], rcx
			mov		[r13], rbx



inc_next:
			mov		r13, [r13 + 8]		; next_node = next_node->next
			jmp		compare

inc_begin:	
			mov		r14, [r14 + 8]		; *begin_list = begin_list->next
			jmp		loop

return:
			leave
			ret

