.code64
.section	.text

.global	rand
.type	rand,	@function
rand:
	push    %rbp
	mov %rsp,   %rbp

	mov	seed(%rip),	%r12
	mov	multiplier(%rip),	%r13
	mov	increment(%rip),	%r14
	mov	mod(%rip),	%r15

	mov	%r12,	%rax
	mul	%r13
	add	%r14,	%rax
	and	%r15,	%rax
	mov	%rax,	seed(%rip)
	
	mov	%rbp,	%rsp
	pop	%rbp
	ret

.section	.data

seed:	.quad	1234566789
multiplier:	.quad   1103515245
increment:	.quad   12345
mod:	.quad   0x7fffffff
