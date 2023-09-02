 area aa,code,readonly
 entry
 ldr r0,=0x00000005
 mov r1,r0
loop cmp r1,#1
	 beq done
	 sub r1,#1
	 mul r2,r0,r1
	 mov r0,r2
	 b loop
done 
 mov r3,r0
stop b stop
 end
 