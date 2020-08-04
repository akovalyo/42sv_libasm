			section	.text
			global	_ft_list_push_front
			extern	_malloc

_ft_list_push_front:
			push	rbp
			mov		rbp, rsp
			xor		rax, rax
			push	rdi
			push	rsi
			mov		rdi, 16
			call	_malloc
			cmp		rax, 0
			jz		return_error
			mov		[rax], rsi
			mov		rdx, [rdi]
			mov		[rax + 8], rdx
			mov		[rdi], rax
			leave
			ret

return_error:
			leave
			ret