; Everything that comes after a semicolon (;) is a comment

; Define the constants 'RED', 'GREEN' and 'BLUE'
; They must be accessible from other source files
section .rodata
global RED
RED dd 0xFF000000
    
global GREEN
GREEN dd 0x00FF0000
    
global BLUE
BLUE dd 0x0000FF00

; Define the variable 'base_color' with the default value of 0xFFFFFF00
; It must be accessible from other source files
section .data
global base_color
base_color dd 0xFFFFFF00
    
; You should implement functions in the .text section
section .text
extern combining_function

; the global directive makes a function visible to the test files
global get_color_value
get_color_value:
    mov rax, rdi
    mov eax, [rax]
    ret

global add_base_color
add_base_color:
    call get_color_value
    mov [rel base_color], eax
    ret

global make_color_combination
make_color_combination:
    mov rbx, rdi

    mov eax, [rel base_color]
    mov edi, eax

    mov eax, [rsi]
    mov esi, eax
    call combining_function

    mov [rbx], eax
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif