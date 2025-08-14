.code64
.section	.text

.global	rand
.type	rand,	@function
rand:
	push	%rbp
	mov	%rsp,	%rbp

	mov	seed(%rip),	%rax
	mov	$1103515245,	%rdi
	mul	%rdi
	add	$12345,	%rax
	and	$0x7fffffff,	%rax
	mov	%rax,	seed(%rip)

	mov	%rbp,	%rsp
	pop	%rbp
	ret

.section	.data

seed:	.quad	1234566789