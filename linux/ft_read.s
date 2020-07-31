			section	.text
			global	ft_read
			extern	__errno_location
ft_read:
			mov		rax, 0				; syscall read, param in rdi, rsi, rdx, return value in rax
			syscall
			jc		error_exit			; if rax < 0
			ret
			
error_exit:
			mov 	rdx, rax			
			call 	__errno_location			
			mov 	[rax], rdx			
			mov 	rax, -1				; to return -1
			ret
