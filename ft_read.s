			section	.text
			global	_ft_read
			extern	___error
_ft_read:
			mov		rax, 0x2000003		; syscall read, param in rdi, rsi, rdx, return value in rax
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
