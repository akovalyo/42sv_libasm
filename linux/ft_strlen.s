			section	.text
			global	ft_strlen

ft_strlen:
			cld					; clear flags
			mov 	rcx, -1
			xor		al, al
			repne	scasb		; repeatedly scan string for 0
			mov		rax, -2
			sub		rax, rcx	; place value in rax to return
			ret
