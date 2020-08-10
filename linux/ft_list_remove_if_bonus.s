				section	.text
				global	ft_list_remove_if
				extern	free
										; rdi = **begin_list, rsi = *data_ref, rdx = *cmp
ft_list_remove_if:
				push	rbp
				mov		rbp, rsp
				mov		r12, rdi		; r12 = **begin_list
				mov		r13, rsi		; r13 = *data_ref
				mov		r14, rdx		; r14 = *cmp
				cmp		r12, 0
				jz		return
				cmp		r13, 0
				jz 		return
				cmp		r14, 0
				jz		return

loop1:
				mov		r15, [r12]		; r15 = *begin_list
				cmp		r15, 0			; check if *begin_list == NULL
				jz		break1		
				mov		rdi, [r15]		; copy begin->list->data to rdi
				call	r14				; cmp(begin_list->data, data_ref)
				cmp		rax, 0		
				jnz		break1		
				mov		r15, [r12]		; r15 = *begin_list
				mov		r10, [r15 + 8]	; r10 = begin_list->next
				mov		[r12], r10		; *begin_list = begin_list->next
				mov		rdi, r15		; move *begin_list to rdi
				call	free			; free(begin_list)
				jmp		loop1		

break1:
				cmp		r15, 0			; check if *begin_list == NULL
				jz		return
				mov		r15, [r12]		; r15 = *begin_list
				
loop2:
				mov		r10, [r15 + 8]	; r10 = r15->next
				cmp		r15, 0			
				jz		return			
				cmp		r10, 0			
				jz		return			
				mov		rdi, [r10]
				mov		rsi, r13
				call	r14				; cmp(r15->data, data_ref)
				cmp		rax, 0		
				jnz		break2	
				mov		rdi, r10
				mov		r10, [r10 + 8]	; r10 = r10->next
				mov		[r15 + 8], r10	; r10->next = next->next
				call	free
				jmp		loop2

break2:
				mov		r15, r10
				jmp		loop2

return:
				mov		rdi, 0		
				leave
				ret
