			section	.text
			global	_ft_strdup
			extern	_malloc, _ft_strlen, _ft_strcpy
			default	rel
_ft_strdup:	
			xor		rax, rax	; set rax to 0
			push	rdi			; save str			
			call	_ft_strlen	; call ft_strlen to calculate the length of str and save result in rax
			inc		rax
			mov		rdi, rax
			call	_malloc		; allocate memory of size rdi, save pointer to the allocated memory in rax
			cmp		rax, 0		; check if malloc fails
			jz		return_error
			pop		rsi			; get pointer to str and save in rsi
			mov		rdi, rax	
			call	_ft_strcpy	; call ft_strcpy and copy from memory pointed by rsi to allocated memory pointed by rdi and save address in rax
			ret
return_error:
			xor		rax, rax
			ret

