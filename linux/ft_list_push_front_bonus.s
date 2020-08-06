			section	.text
			global	ft_list_push_front
			extern	malloc

ft_list_push_front:
			push	rbp				; establish a stack frame
			mov		rbp, rsp
			xor		rax, rax
			push	rdi				; save ponter to begin_list on stack
			push	rsi				; save pointer to data on stack
			mov		rdi, 16
			call	malloc			; allocate memory of size rdi, save pointer to the allocated memory in rax
			pop		rsi				; get ponter to data and save in rsi
			pop		rdi				; get ponter to begin_list and save in rdi
			cmp		rax, 0			; check if malloc fails
			jz		return
			mov		[rax], rsi		; new_node.data = data
			cmp 	rdi, 0			; check if begin_list = NULL
			jz		null_begin
			mov		rdx, [rdi]		; tmp = begin_list
			mov		[rax + 8], rdx	; new_node.next = tmp
			mov		[rdi], rax		; begin_list = new_node

return:
			leave					; release the stack space
			ret

null_begin:
			mov		byte [rax + 8], 0  ; new_node.next = NULL
			mov		[rdi], rax
			leave
			ret
