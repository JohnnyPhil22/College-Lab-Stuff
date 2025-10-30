.586
.MODEL FLAT

INCLUDE io.h            ; header file for input/output

.STACK 4096

.DATA
number1     DWORD   ?
number2     DWORD   ?
prompt1     BYTE    "Enter first number", 0
prompt2     BYTE    "Enter second number", 0
string      BYTE    40 DUP (?)
resultLbl   BYTE  "The sum is", 0
sum         BYTE    11 DUP (?), 0
arr1        DWORD   1, 3, 5, 7, 9, 11

.CODE
myPow PROC      ; Save x^y to EAX
    push EBP        ; ENTRY CODE
    mov EBP, ESP

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
    push EBP        ; ENTRY CODE
    mov EBP, ESP

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
    push EBP        ; ENTRY CODE
    mov EBP, ESP

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
        pop EBP         ; EXIT CODE
        ret
Comp3 ENDP

factNum PROC    ; Calculate factorial of n
    push EBP        ; ENTRY CODE
    mov EBP, ESP

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
        pop EBP         ; EXIT CODE
        ret
factNum ENDP

myAvg PROC      ; Calculate average of array of numbers
    push EBP        ; ENTRY CODE
    mov EBP, ESP

    push EBX
    push ECX

    mov EBX, DWORD PTR [EBP + 8]        ; get first number
    mov ECX, DWORD PTR [EBP + 12]       ; get second number
    mov EAX, 0      ; initialize sum to 0
    dec ECX

    Begin_Avg_Calc:
        add EAX, DWORD PTR[EBX+4+ECX] ; add array element to sum
        dec ECX
        cmp ECX, 0
        jl Done
        jmp Begin_Avg_Calc

    Done:
        cdq			 ; extend EAX to EDX:EAX for division
        div DWORD PTR [EBP + 12]      ; divide sum by count
    
    pop ECX
    pop EBX
    pop EBP     ; EXIT CODE
    ret
myAvg ENDP

add3    MACRO p1, p2, p3        ; Macro to add three numbers and store in p1
        push EDX
        mov EDX, p1
        add EDX, p2
        add EDX, p3
        mov p1, EDX
        ENDM

_MainProc PROC
    ; Example code for adding two numbers from user input (TB material)
    input   prompt1, string, 40      ; read ASCII characters
    atod    string          ; convert to integer
    mov     number1, EAX    ; store in memory

    input   prompt2, string, 40      ; repeat for second number
    atod    string
    mov     number2, EAX
        
    mov     EAX, number1    ; first number to EAX
    add     EAX, number2    ; add second number
    dtoa    sum, EAX        ; convert to ASCII characters
    output  resultLbl, sum          ; output label and sum

    ; Example code for x^y proc
    pushd 3         ; exponent
    pushd 2         ; base
    call myPow
    add ESP, 8

    ; Example code for comparing three numbers proc
    pushw 3         ; third number 
    pushw 2         ; second number
    pushw 1         ; first number
    call Comp3
    add ESP, 6

    ; Example code for factorial proc
    pushd 3         ; number to factorial
    call factNum
    add ESP, 4

    ; Example code for average of array proc
    pushd 6         ; number of elements
    lea ECX, arr1   ; address of array
    push ECX        ; array address
    call myAvg
    add ESP, 8

    ; Example usage of add3 macro
    add3    EAX, number1, 6

    mov     EAX, 0      ; exit with return code 0
    ret
_MainProc ENDP
END                             ; end of source code