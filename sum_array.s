area aa,code,readonly
entry
ldr r0,=arr
mov r4,#0
loop cmp r4,#5
     bge done
     ldr r1,[r0],#4
	 add r3,r2,r1
     mov r2,r3
	 add r4,r4,#1
     b loop
	 done
stop b stop
arr dcd 0x00000002,0x00000003,0x00000001,0x00000002,0x00000001
 end