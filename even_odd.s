 area aa,code,readonly
 entry
 ldr r0,=0x12345678
 movs r1,r0,lsr#1
 bcs odd
 mov r2,#0x0A ;Even
 b last
odd mov r3,#0x0F ;Odd
	b last
last
stop b stop
 end
