			section	.text
			global	_ft_strcpy
			default rel
_ft_strcpy:	
			mov		rax, rdi		; set pointer on dest
			xor		rcx, rcx
repeat:
			cmp 	byte [rsi+rcx], 0	; while src[i] != 0
			jz		return
			mov		dl, byte [rsi+rcx]	; copy src[i] to dst[i]
			mov		byte [rdi+rcx], dl
			inc		rcx					; i++
			jmp		repeat
return:			
			mov		byte [rdi+rcx], 0	; dst[i] = '\0'
			ret
