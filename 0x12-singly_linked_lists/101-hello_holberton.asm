section .data
    hello_msg db "Hello, Holberton", 10, 0

section .text
    global main
    extern printf

main:
    ; Set up the stack frame
    push rbp
    mov rbp, rsp

    ; Store the string address in rdi
    mov rdi, hello_msg
    ; Call printf
    call printf

    ; Clean up the stack frame
    mov rsp, rbp
    pop rbp

    ; Exit the program
    mov eax, 0
    ret
