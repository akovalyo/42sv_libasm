			section	.text
			global	_ft_list_size

_ft_list_size:
			xor 	rcx, rcx
counter:
			cmp 	rdi, 0x00		; check if begin_list = NULL
			jz		return
			mov		rdi, [rdi + 8]
			inc		rcx
			jmp		counter


return:
			mov rax, rcx
			ret