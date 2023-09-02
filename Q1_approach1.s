 area aa,code,readonly
 entry
 ldr r0,=0x0000001A    ;a 
 ;(i)
 mov r1,r0
 mul r2,r1,r0          ;a*a
 mov r8,r2             ;a*a is stored r0
 
 ;(ii)
 ldr r1,=0x0000002A    ;x
 mov r2,r1             ;x is als stored in r2
 mul r3,r2,r1          ;x*x
 mov r2,r3
 mov r3,#0x06
 mov r4,#0x09
 mul r5,r2,r3          ;6*x^2
 add r5,r5,#2          ;6*x^2+2
 mul r3,r1,r4          ;9*x
 sub r9,r5,r3          ;6*x^2+2-9*x
 
stop b stop
 end
	 