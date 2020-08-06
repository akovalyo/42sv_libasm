			section	.text
			global	ft_list_sort
										; rdi = **begin_list, rsi = *cmp
ft_list_sort:
			push	rbp					; estblish frame stack
			mov		rbp, rsp
			push	rbx
			push	rdx
			push	r10
			push	r11
			push	r12
			mov		rbx, [rdi]			; rbx = *begin_list
			mov		rdx, rsi			; rdx = *cmp
			cmp 	rbx, 0				; check if *begin_list = NULL
			jz		return
			cmp 	rdx, 0				; check if *cmp = NULL
			jz		return
			
loop:
			cmp		rbx, 0
			jz		return
			mov		r10, [rbx + 8]		; (r10) next_node = *begin_list->next

compare:
			cmp		r10, 0
			jz		inc_begin
			mov		rdi, [rbx]			; rdi = *begin_list->data
			mov		rsi, [r10]			; rsi = next_node->data
			mov		rax, rdx			; save pointer to strcmp in rax
			call	rax					; strcmp(begin_list->data, next_node->data);
			cmp		rax, 0
			jnle	swap
			jmp		inc_next

swap:			
			mov		r11, [rbx]			; tmp_list = *begin_list->data 
			mov		r12, [r10]			; tmp_next = next_node->data 
			mov		[rbx], r12
			mov		[r10], r11


inc_next:
			mov		r10, [r10 + 8]		; next_node = next_node->next
			jmp		compare

inc_begin:
			mov		rbx, [rbx + 8]		; *begin_list = begin_list->next
			jmp		loop

return:
			leave
			ret

