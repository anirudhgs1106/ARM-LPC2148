 area aa,code,readonly
 entry 
 ldr r0,=0x000001D0
 ldr r1,=0x0000012C
 ldr r3,=0x00000000
loop cmp r0,r1
	 blt loop2
	 beq loop3
	 add r3,r3,#1   ;Result
	 sub r2,r0,r1
	 movs r0,r2
	 b loop
loop2 mov r4,r0    ;Remainder
	  b done
loop3 add r3,r3,#1
	  b done
done 
stop b stop
 end