			section	.text
			global	_ft_list_push_front
			extern	_malloc

_ft_list_push_front:
			push	rbp				; establish a stack frame
			mov		rbp, rsp
			xor		rax, rax
			push	rdi				; save ponter to begin_list on stack
			push	rsi				; save pointer to data on stack
			mov		rdi, 16
			call	_malloc			; allocate memory of size rdi, save pointer to the allocated memory in rax
			pop		rsi				; get ponter to data and save in rsi
			pop		rdi				; get ponter to begin_list and save in rdi
			cmp		rax, 0			; check if malloc fails
			jz		return
			mov		[rax], rsi		; new_node.data = data
			mov		rdx, [rdi]		; tmp = begin_list
			mov		[rax + 8], rdx	; new_node.next = tmp
			mov		[rdi], rax		; begin_list = new_node

return:
			leave					; release the stack space
			ret
