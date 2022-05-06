BITS 64

section .text

global ft_memset

ft_memset:
	movd xmm0, esi
	mov rax, rdi
	punpcklbw xmm0, xmm0
	punpcklwd xmm0, xmm0
	pshufd xmm0, xmm0, 0
	cmp rdx, 0x10
	jb _below_16
	cmp rdx, 0x20
	ja _above_32
	movdqu oword [rdi + rdx - 0x10], xmm0
	movdqu oword [rdi], xmm0
	ret

_above_32:
	cmp rdx, 0x800
	ja _above_2048
	cmp rdx, 0x40
	jb _loop

_above_128:
	lea rcx, [rdi + 0x40]
	movdqu oword [rdi], xmm0
	and rcx, 0xffffffffffffffc0
	movdqu oword [rdi + rdx - 0x10], xmm0
	movdqu oword [rdi + 0x10], xmm0
	movdqu oword [rdi + rdx - 0x20], xmm0
	movdqu oword [rdi + 0x20], xmm0
	movdqu oword [rdi + rdx - 0x30], xmm0
	movdqu oword [rdi + 0x30], xmm0
	movdqu oword [rdi + rdx - 0x40], xmm0
	add rdx, rdi
	and rdx, 0xffffffffffffffc0
	cmp rcx, rdx
	je _finish_memset

_loop:
	movdqa oword [rcx], xmm0
	movdqa oword [rcx + 0x10], xmm0
	movdqa oword [rcx + 0x20], xmm0
	movdqa oword [rcx + 0x30], xmm0
	add rcx, 0x40
	cmp rdx, rcx
	jne _loop
	jmp _finish_memset

_above_2048:
	mov rcx, rdx
	movzx eax, sil
	mov rdx, rdi
	mov byte [rdi], al
	rep stosb
	mov rax, rdx
	ret

_below_16:
	cmp dl, 0x8
	jae __unk_label_4
	cmp dl, 4
	jae __unk_label_3
	cmp dl, 2
	jae __unk_label_2
	jb _add_1


__unk_label_4:
	mov qword [rdi + rdx - 8], rcx
	mov qword [rdi], rcx
	ret

__unk_label_3:
	mov dword [rdi + rdx - 4], ecx
	mov dword [rdi], ecx
	ret

__unk_label_2:
	mov word [rdi + rdx - 2], cx
	mov word [rdi], cx
	ret

_add_1:
	mov byte [rdi], cl
	ret

_finish_memset:
	ret
