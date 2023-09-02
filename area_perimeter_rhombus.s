 area aa,code,readonly
 entry
 ldr r0,=0x12345678  ;Side A
 mov r1,#0x04
 ldr r2,=0x00000004  ;Diagonal D1
 ldr r3,=0x12345678  ;Diagonal D2
 mov r6,#0x02
 mov r8,#0x00
 mul r7,r1,r0 ;Perimeter (4A) stored in r7
 mul r5,r3,r2 ;Area (0.5*D1*D2) stored in r8
 ;mov r5,r2
 b divide
divide cmp r5,r6
	   blo done
	   beq loop2
	   subs r9,r5,r6
	   add r8,r8,#1 ;result
	   movs r5,r9
	   b divide
loop2 add r8,r8,#1
	  b done
done 
stop b stop
 end