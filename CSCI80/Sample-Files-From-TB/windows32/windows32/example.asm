; Example assembly language program -- adds two numbers
; Author:  R. Detmer
; Date:    1/2008

.586
.MODEL FLAT

INCLUDE io.h            ; header file for input/output

.STACK 4096

.DATA
number1 DWORD   ?
number2 DWORD   ?
prompt1 BYTE    "Enter first number", 0
prompt2 BYTE    "Enter second number", 0
string  BYTE    40 DUP (?)
resultLbl BYTE  "The sum is", 0
sum     BYTE    11 DUP (?), 0

.CODE
myPow PROC      ; Save x^y to EAX
    push EBP
    mov EBP, ESP        ; ENTRY CODE

    mov EBX, DWORD PTR [EBP + 8]        ; get exponent y
    mov ECX, DWORD PTR [EBP + 12]       ; get base x

    mov EAX, 1      ; initialize result to 1
    LBEGIN:
        mul EBX     ; EAX = EAX * x
        loop LBEGIN

    pop EBP     ; EXIT CODE
    ret
myPow ENDP

Comp2 PROC     ; Compare two numbers
    push EBP
    mov EBP, ESP        ; ENTRY CODE

    mov EBX, DWORD PTR [EBP + 8]        ; get number a
    mov ECX, DWORD PTR [EBP + 12]       ; get number b

    cmp EBX, ECX
    je  EQUAL
    jl  LESS
    mov EAX, 1      ; a > b
    jmp DONE
    LESS:
        mov EAX, -1     ; a < b
        jmp DONE
    EQUAL:
        mov EAX, 0      ; a == b
    DONE:
        pop EBP     ; EXIT CODE
        ret
Comp2 ENDP

Comp3 PROC     ; Compare three numbers
    push EBP
    mov EBP, ESP        ; ENTRY CODE

    mov AX, [EBP + 8]         ; get number a
    mov BX, [EBP + 10]        ; get number b
    mov CX, [EBP + 12]        ; get number c

    cmp AX, BX
    jge Chk_AC
    mov AX, BX

    Chk_AC:
    cmp AX, CX
    jge A_Max
    mov AX, CX
    
    A_Max:
        pop EBP
        ret         ; EXIT CODE
Comp3 ENDP

factNum PROC
    push EBP
    mov EBP, ESP        ; ENTRY CODE

    cmp DWORD PTR [EBP + 8], 1
    jg RECURSE
    mov EAX, 1
    jmp EXIT

    RECURSE:
        mov EBX, DWORD PTR [EBP + 8]
        dec EBX
        push EBX
        call factNum
        add ESP, 4
        inc EBX
        mul EBX

    EXIT:
        pop EBP
        ret         ; EXIT CODE
factNum ENDP

_MainProc PROC
        pushd 3
        pushd 2
        call myPow
        add ESP, 8

        pushw 3
        pushw 2
        pushw 1
        call Comp3
        add ESP, 6

        pushd 3
        call factNum
        add ESP, 4

        COMMENT #
        input   prompt1, string, 40      ; read ASCII characters
        atod    string          ; convert to integer
        mov     number1, eax    ; store in memory

        input   prompt2, string, 40      ; repeat for second number
        atod    string
        mov     number2, eax
        
        mov     eax, number1    ; first number to EAX
        add     eax, number2    ; add second number
        dtoa    sum, eax        ; convert to ASCII characters
        output  resultLbl, sum          ; output label and sum
        #

        mov     eax, 0  ; exit with return code 0
        ret
_MainProc ENDP
END                             ; end of source code

