    area aa,code,readonly
	entry
    ldr r0,=str1                ;Load r0 with address of first value present in str1
    ldr r1,=str2                ;Load r1 with address of first value present in str2
	mov r5,r1
    ldr r3,=0
loop 
    cmp r3,#6                   ;if r3>=6 (N flag is equals to V)
    bge done1             
	ldrb r2,[r0],#1             ;value is loaded in r2 from memory using post index
	mov  r1,r5
	adds r3,r3,#1               ;r3 is incremented till 6 (for loop)
	ldr r8,=0
loop2 cmp r8,#6
    bge k
    ldrb r4,[r1],#1             ;value is loaded in r4 from memory using post index
	cmps r2,r4                  ;comparision of character 
	beq loop                    ;Z flag is set if both characters are equal
	adds r8,r8,#1               ;r8 is incremented till 6 (for loop)
	b loop2
k mov r7,#-1                     ;if not anagram r7 is stored with -1
  b done
done1
   mov r7,#0x0A                  ;if anagram r7 is stored with A
done
stop b stop 
str1 DCB 's','i','l','e','n','t' ;str1 declaration
str2 DCB 'l','i','s','t','e','n' ;str2 declaration
     end	