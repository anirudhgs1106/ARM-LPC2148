area aa,code,readonly
entry
 ldr r4,=arr           ;r4 is stored with address of arr
 ldr r8,=0x40000000	   ;load r8 with 0x40000000
 loop4 mov r3,#0				
	  cmp r7,#3
	  bge done         ;if r7>=3 (N flag equals V)
	  ldr r0,[r4],#4   ;load r0 with first element of arr using post index 
	  mov r1,r0
	  mov r2,r0 
loop1 cmp r1,#0        ;if r1=0 then Z flag is set
	  beq loop3        
	  sub r1,r1,#1     ;r1 and r2 used for "for" loops
	  mov r2,r0
loop2 cmp r2,#0
	  beq loop1        ;if r1=0 then Z flag is set
	  sub r2,r2,#1
	  add r3,r3,r0     ;r3=r3+r0 
	  b loop2
loop3 strh r3,[r8],#2  ;store in r8 which contains memory address using post index
	  add r7,r7,#1     
	  b loop4
done 
stop b stop
arr dcd 0x02,0x03,0x05  ;array (arr) declaration
 end