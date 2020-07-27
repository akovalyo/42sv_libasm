			section	.text
			global	_ft_write
			extern	___error
_ft_write:
			mov		rax, 0x2000004		; syscall write, param in rdi, rsi, rdx, return value in rax
			syscall
			jc		error_exit			; if rax < 0
			ret
error_exit:
			push 	rbp					; establish a stack frame
			mov 	rbp, rsp
			mov 	rdx, rax			
			call 	___error			
			mov 	[rax], rdx			
			mov 	rax, -1				; to return -1
			leave
			ret
