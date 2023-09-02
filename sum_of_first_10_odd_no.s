;Sum of first 10 odd numbers
	 area aa,code,readonly
	 entry
	 ldr r0,=0x00000000
	 ldr r1,=0x00000000
loop cmp r1,#10
	 bge done
	 add r0,r0,#1
	 movs r2,r0,LSR #1
	 bcs odd
	 b loop
odd  add r4,r3,r0
	 mov r3,r4
	 add r1,r1,#1
	 mov r2,#0
	 b loop
done
stop b stop
	 end