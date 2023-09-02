 area aa,code,readonly
 entry 
 ldr r0,=0x00000001
 ldr r1,=0x00000002
 mov r3,#0x04
 mov r4,#0x07
 cmp r0,r1            ;Comparing r0 and r1
 bmi elseif           ;if r0<r1, N flag is set
 mul r5,r1,r3         ;4r1
 sub r2,r0,r5         ;r2=r0-4r1
 b done
elseif cmp r0,r1      ;if r0=r1, Z flag is set
	   bne else_
	   mul r3,r1,r4   ;7r1
	   sub r2,r0,r3   ;r2=r0-7r1
	   b done
else_ mov r3,#0x02
	  mul r4,r1,r3    ;2r1
	  mov r3,r1
	  mul r5,r3,r1    ;r1^2
	  mov r3,r5
	  mul r5,r3,r1    ;r1^3
	  add r2,r4,r5    ;2r1+r1^3
	  b done
done
stop b stop
 end
