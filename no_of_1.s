 area aa,code,readonly
 entry 
 ldr r0,=0x12345678
 mov r1,#0x00
 mov r3,#0x00
loop cmp r1,#32
	 bge done
	 movs r2,r0,lsr#1
	 mov r0,r2
	 bcs loop1
	 b loop2
loop2 add r1,r1,#1  
	  b loop
loop1 add r3,r3,#1
      b loop2
done
stop b stop
 end