# 42sv_Libasm

The aim of the project is to get familiar with assembly language.

# x86 64-bit Assembly Programming for OS X

## Syntax

1. **section .data**
	
	* to declare initialized data or constants
	
	* cannot be extended

	* remains static throuoghout the program


2. **section .bss**

	* to declare variables

	* static

	* to declare data later in the program

3. **section .text**

	* memory area to keep the actual code

	* fixed area

*Memory segments:*

A. data segment (section .data and section .bss)

B. code segment (section .text)

C. stack segment (the segment contains data values passed to functions and procedures within the programm)

## Registers

#### x86-64 CPU

* 16 general purpose registers (64-bit)

* 16 modern floating point registers (either 128- or 256-bit)

* instruction pointer register (rip) (64-bit) (contains the address of the next instruction to execute)

* floating-point control and status register

* status and control flag (rflags) (64-bit)

### General purpose registers

|64-bit|32|16|8||
|---|---|---|---|---|
|RAX|EAX|AX|AL|accumulator for numeric operations|
|RBX|EBX|BX|BL|base register (array access)|
|RCX|ECX|CX|CL|count register (string operations)|
|RDX|EDX|DX|DL|data register|
|RSI|ESI|SI|SIL|source index for string operations|
|RDI|EDI|DI|DIL|destination index for string operations|
|RBP|EBP|BP|BPL|base pointer (for function frames)|
|RSP|ESP|SP|SPL|stack pointer|
|R8|R8D|R8W|R8B||
|R9|R9D|R9W|R9B||
|R10|R10D|R10W|R10B||
|R11|R11D|R11W|R11B||
|R12|R12D|R12W|R12B||
|R13|R13D|R13W|R13B||
|R14|R14D|R14W|R14B||
|R15|R15D|R15W|R15B||

### RFLAGS register

* CF - carry flagi (set by the processor to signify  an overflow condition when performing unsigned int arithmetic)

* OF - overflow flag (signals that the result of a signed int operation is too small or too large)

* PF - parity flag (to indicate whether the least-significant byte of an arithmetic, compare, or logical operation contains an even number of 1 bits)

* SF - sign flag (to indicate negative or positive result)

* ZF - zero flag (to indicate zero result)

* DF - direction flag (defines the auto increment direction (0=low to high addresses, 1=high to low adresses) of the RDI and RSI registers during execution of string instructions

*Other flags should never be modified by an application programm*

 ## Instructions
|||
|---|---|
| adc| Integer addition with carry|
| add| Integer addition|
| and| Bitwise AND|
| bs[f\|r]| Bit scan forward, bit scan reverse|
| b[t\|tr\|ts]| Bit test; Bit test and reset; Bit test and set|
| call| Call procedure |
| cld| Clear direction flag (RFLAGS.DF)|
| cmovcc| Conditional move|
| cmp| Compare operands|
| cmps[b\|w\|d\|q]| Compare string operands|
| cupid| Query CPU identification and feature information|
| c[wd\|dq\|do]| Convert operand|
| dec| Decrement operand by 1|
| div| Unsigned integer division|
| idiv| Signed integer division|
| imul| Signed integer multiplication|
| inc| Increment operand by 1|
| jcc| Conditional jump|
| jmp| Unconditional jump|
| lahf| Load status flags into register AH|
| lea| Load effective address|
| lods[b\|w\|d\|q]| Load string operand|
| mov| Move data|
| mov[sx\|sxd]| Move integer with sign extension|
| movzx| Move integer with zero extension|
| mul| Unsigned integer multiplication|
| neg| Two’s complement negation|
| not| One’s complement negation|
| or| Bitwise inclusive OR|
| pop| Pop top-of-stack value to operand|
| popfq| Pop top-of-stack value to RFLAGS|
| push| Push operand onto stack|
| pushfq| Push RFLAGS onto stack|
| rc[l\|r]| Rotate left with RFLAGS.CF; Rotate right with RFLAGS.CF|
| ret| Return from procedure|
| re[p\|pe\|pz\|pne\|pnz]| Repeat string operation (instruction prefix)|
| ro[l\|r]| Rotate left; Rotate right|
| sahf| Store AH into status flags|
| sar| Shift arithmetic right|
| setcc| Set byte on condition|
| sh[l\|r]| Shift logical left; Shift logical right|
| sbb| Integer subtraction with borrow|
| std| Set direction flag (RFLAGS.DF)|
| stos[b\|w\|d\|q]| Store string value|
| test| Test operand (sets status flags)|
| xchg| Exchange source and destination operand values|
| xor| Bitwise exclusive OR|

***

## Branch statements

### Unconditional jump

```
jmp LABEL
```

### Conditional jump

```
j** label
```

**
| instruction | meaning | aliases | flags |
| --- | --- | --- | --- |
| jz | jump if zero | je | ZF=1 |
| jnz | jimp if not zero | jne | ZF=0 |
| jg | jump if > 0 | jnle | ZF=0 and SF=0 |
| jge | jump if >= 0 | jnl | SF=0 |
| jl | jump if > 0 | jnge js | SF=0 |
| jle | jump if <= 0 | jng | ZF=1 or SF=1 |
| jc | jump if carry | jb jnae | CF=1 |
| jnc | jump if not carry | jnb jae | |

***
## Functions

* **rax** used for integer return values

* **xmm0** used for floating point return values

* 6 first integer parameters in a function are passed in: **rdi, rsi, rdx, rcx, r8, r9**

***

## Hello World

**Using system calls**

```
	section	.data
msg:	db	"Hello, World", 10 	; the newline at the end

	section .text
	global	start
start:	mov	rax, 0x02000004		; system call for write
	mov	rdi, 1              	; file handle 1 is stdout
	mov     rsi, msg            	; address of string to output
	mov     rdx, 13            	; number of bytes
	syscall                     	; invoke operating system to do the write
	mov     rax, 0x02000001     	; system call for exit
	mov     rdi, 0          	; exit code 0
	syscall                     	; invoke operating system to exit
```

```
nasm -f macho64 hello.s && ld hello.o && ./a.out
```

**Using C printf**

```
	section .data
msg:	db	"Hello World!", 0x0a, 0

	section	.text
	global	_main
	extern	_printf
	default	rel
_main:
	push	rbp
	mov	rbp, rsp
	lea	rdi, [msg]		; loads the effective address of the message into rdi 
	xor	eax, eax		; 0 floating point parameters
	call 	_printf
	xor	eax,eax			; return 0
	pop	rbp
	ret
```

```
nasm -f macho64 hello.s && gcc hello.o && a.out
```
