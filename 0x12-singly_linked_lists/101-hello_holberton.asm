section .data
    hello db 'Hello, Holberton', 0
    prompt db 10, '>', ' ', 0   ; Updated prompt with newline character

section .text
    extern printf

    global main
    main:
        sub rsp, 8             ; align stack
        mov edi, hello         ; string to print
        xor eax, eax           ; clear eax
        call printf            ; call printf function

        mov edi, prompt        ; string to print (prompt)
        xor eax, eax           ; clear eax
        call printf            ; call printf function

        add rsp, 8             ; restore stack
        xor eax, eax           ; clear eax
        ret                    ; return from main
