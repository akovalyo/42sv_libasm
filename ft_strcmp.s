			section	.text
			global	_ft_strcmp
			default rel
_ft_strcmp:	
			cmp 	byte [rdi], 0	; check end of s1
			jz		return
			cmp 	byte [rsi], 0	; check end of s2
			jz		return
			cmpsb					; compares the byte addressed by rdi to the byte addressed by rsi
			jnz		not_equal		; if equal, repeati
			jmp		_ft_strcmp
not_equal:
			dec		rdi
			dec		rsi
			jmp		return
return:			
			movzx	eax, byte [rdi]
			movzx	ecx, byte [rsi]
			sub		rax, rcx
			ret
