 area aa,code,readonly
 entry 
 ldr r1,=0x00000001
 mov r0,#0x00
 mov r5,#0x00
loop cmp r0,#10
	 bge done
	 add r2,r1,#10
	 mov r3,r2
	 add r4,r3,r5
	 mov r5,r4
	 add r0,r0,#1
	 b loop
done
stop b stop
 end