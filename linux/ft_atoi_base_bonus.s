				section	.text
				global	ft_atoi_base

ft_atoi_base:
				xor		r8, r8				; int base_int = 0
				xor		r9b, r9b			; int sign = 0
				xor		r10b, r10b			; flag = 0
				xor		r11, r11			; collector = 0
				xor		rcx, rcx			; i = 0
				jmp		atoi_skip_ident

atoi_ident_inc:
				inc		rcx					; i++

atoi_skip_ident:
				mov		dl, byte[rsi + rcx]
				cmp		dl, 32				; if == ' '
				jz		atoi_skip_ident
				cmp		dl, 9				; if == '\t'
				jz		atoi_skip_ident
				cmp		dl, 10 				; if == '\n'
				jz		atoi_skip_ident
				cmp		dl, 11 				; if == '\v'
				jz		atoi_skip_ident
				cmp		dl, 12 				; if == '\f'
				jz		atoi_skip_ident
				cmp		dl, 13 				; if == '\r'
				jz		atoi_skip_ident
				cmp		r10b, 1				; if flag == 1 
				jz		check_sign

base_invalid:
				mov		dl, byte[rsi + rcx]
				cmp		dl, 45				; base[i] == '-'
				jz		ret_inv
				cmp		dl, 43				; base[i] == '+'
				jz		ret_inv
				cmp		dl, 48 				; base[i] == '0'
				jz		ret_inv

atoi:
				mov		dl, byte[rsi + rcx]
				cmp		dl, 0				; check the end of string
				jz		check_base_int
											; collector *= 10 + base[i] - '0'	
				sub		dl, 48
				movzx	rax, dl
				imul	r8, 10
				add		r8, rax
				inc		rcx
				jmp		atoi

check_base_int:
				cmp		r8, 17
				jnl		ret_inv
				cmp		r8, 1
				jle		ret_inv

atoi_base:
				mov		rsi, rdi 			; rsi = str
				xor 	rcx, rcx			; i = 0
				xor		rax, rax
				inc		r10b				; flag = 1
				jmp		atoi_skip_ident

check_sign:
				cmp		byte[rsi + rcx], 45	; base[i] == '-'
				jz		sign_minus
				cmp		byte[rsi + rcx], 43	; base[i] == '+'
				jz		sign_plus
				jmp 	str_to_int

sign_minus:
				inc		r9b					; sign = 1
				inc		rcx
				jmp		str_to_int

sign_plus:
				inc		rcx
				jmp		str_to_int

char_to_int:
				movzx	r12, dl				; r12: int nbr 
				sub		r12, 48				; nbr -= 48
				cmp		r12, 9				
				jle		check_base			; if r12 <= 9 
				movzx	r12, dl
				sub		r12, 65
				cmp		r12, 5				; if r12 <= 4
				jle		convert_letter
				movzx	r12, dl
				sub		r12, 97
				cmp		r12, 5				; if r12 <= 4
				jle		convert_letter

convert_letter:
				cmp		r12, -1
				jle		return
				add		r12, 10
				jmp		check_base

str_to_int:
				mov		dl, byte[rsi + rcx] ; move str[i] to register dl
				inc		rcx					; i++
				cmp		dl, 0				; check for end of str
				jz		return
				cmp		dl, 47				
				jle		return				; if ascii < '0' then exit
				cmp		dl, 103				
				jnl		return				; if ascii > 'f' then exit
				jmp		char_to_int			

check_base:
				cmp		r12, r8
				jnl		return				; if r12 >= base_int then exit
				jmp		collect

collect:		
				imul	r11, r8				; collector = collector * base_int
				add		r11, r12			; collector += nbr
				jmp		str_to_int

return:
				mov		rax, r11
				cmp		r9b, 1
				jz		ret_neg
				ret

ret_neg:
				neg		rax
				ret

ret_inv:
				xor		rax, rax
				ret



