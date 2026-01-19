; Everything that comes after a semicolon (;) is a comment

; Assembler-time constants may be defined using 'equ'
EXPECTED_TIME equ 40
TIME_PER_LAYER equ 2

section .text

; You should implement functions in the .text section

; the global directive makes a function visible to the test files
global expected_minutes_in_oven
expected_minutes_in_oven:
    mov rax, EXPECTED_TIME
    ret

global remaining_minutes_in_oven
remaining_minutes_in_oven:
    mov rax, EXPECTED_TIME
    sub rax, rdi
    ret

global preparation_time_in_minutes
preparation_time_in_minutes:
    mov rax, rdi
    imul rax, TIME_PER_LAYER
    ret

global elapsed_time_in_minutes
elapsed_time_in_minutes:
    ; obtain preparation time in minutes
    call preparation_time_in_minutes
    mov rbx, rax

    ; add them up and return
    add rbx, rsi
    mov rax, rbx
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
