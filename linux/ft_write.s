			section	.text
			global	ft_write
			extern	__errno_location
ft_write:
			mov		rax, 1				; syscall write, param in rdi, rsi, rdx, return value in rax
			syscall
			cmp		rax, 0
			jl		error_exit
			ret
error_exit:
			neg		rax
			mov 	rdx,rax
			call 	__errno_location
			mov 	[rax], rdx
			mov 	rax, -1
			ret
