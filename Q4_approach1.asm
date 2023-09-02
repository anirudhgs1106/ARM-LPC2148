    area aa ,code,readonly
	entry
	ldr r0,=arr1           ;load r0 with address of first element of arr1
	ldr r6,=0x40000000     ;load r6 with 0x40000000 where output to be stored
	ldr r5,=0

comp_loop 
    mov r4,#0
	mov r1,#0
    cmp r5,#3               ;check for last element
    bge done                ;if r5>=3 (N flag equals V)
    ldr r2,=0
	ldr r3,=0
	ldr r7,[r0],#4          ;r7 is loaded with value whose address is stored in r0 using post index
loop1 cmp r2,r7         
     bge loop2
	 adds r1,r1,r7          ;r1=r1+r7 
	 add r2,r2,#1          
	 b loop1                ;r1 counts number of time value to be added to get its cube (purpose of loop1)
loop2 cmp r3,r1
     bge store              ;if r3>=r1 then result is stored
	 adds r4,r4,r7
	 add r3,r3,#1
	 b loop2                ;loop2 is for adding the value r1 timesto get its cube
store str r4,[r6],#4        ;store in r6 which contains memory address using post index
     add r5,r5,#1
     b comp_loop	 
done  
here b here
arr1 DCD 0x02, 0x04, 0x03  ;arr1 declaration 
     end	