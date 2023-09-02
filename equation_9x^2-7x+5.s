;Expression evaluation 9x^2-7x+5
	area aa,code,readonly
	entry
	ldr r4,=0x00000005
	mov r2,r4
	mul r1,r2,r4 ;x^2
	mov r0,#9
	mul r2,r1,r0 ;r2=9x^2
	mov r0,#7
	mul r3,r0,r4 ;r3=7x
	add r0,r2,#5
	sub r5,r0,r3
stop b stop
	end