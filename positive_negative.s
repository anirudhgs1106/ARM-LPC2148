 area aa,code,readonly
 entry
 ldr r0,=-0x12345678
 cmp r0,#0
 beq zero
 movs r1,r0
 bmi odd
 b even
even mov r1,#0x10 ;even
	 b last
odd mov r1,#0x11 ;odd
	b last
zero mov r1,#0x01 ;Zero
     b last
last
stop b stop
 end