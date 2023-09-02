    area aa,code,readonly
	entry
    ldr r0,=0x40000000    ;R0 holds address of string1
    ldr r1,=0x40001000    ;R0 holds address of string2
	mov r5,r1              
    ldr r3,=0
loop 
    cmp r3,#6              
    bge done1              ;if r3>=6 (N flag equals V)
	ldrb r2,[r0],#1        ;value is loaded in r2 from memory using post index (string1)
    mov r4,#0
	mov r1,r5
	adds r3,r3,#1          ;r3 and r4 used for "for" loop
loop1 cmp r4,#6
    bge k                  ;if r4>=6 (N flag equals V)
	ldrb r6,[r1],#1        ;value is loaded in r6 from memory using post index (string2)
	adds r4,r4,#1
	subs r9,r2,r6          ;r9=r2-r6 (ASCII value of both characters are subtracted)
	beq loop               ;if equal(Z flag is set)
    b loop1
k   mov r7,#-1             ;if not anagram store r7 with -1
	b done
done1
 mov r7,#0x0A              ;if anagram store r7 with A
done
stop b stop 
     end	