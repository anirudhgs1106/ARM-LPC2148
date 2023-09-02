 area aa,code,readonly
 entry
 ldr r0,=0x00000002 
 ldr r1,=0x00000001
 subs r2,r0,r1  	; r2=r0-r1
 bpl if_  			;if r1>r0 i.e r2 is positive (N flag is clear) 
 beq elseif_  		;if r1=r0 i.e r2 is zero (Z flag is set) 

 ;else 
 mov r2,#0x02  		;if r1<r0 i.e r2 is negative (N flag is set)
 mul r3,r1,r2  
 mov r2,r1     
 mul r4,r2,r1
 mov r2,r4      	;r2=2r1+r1^3
 mul r4,r2,r1
 add r2,r3,r4
 b done

if_ mov r2,#0x04
	mul r3,r1,r2
	sub r2,r0,r3  	;r2=r0-4r1
	b done

elseif_ mov r2,#0x07
		mul r3,r1,r2
		sub r2,r0,r3  ;r2=r0-7r1
		b done 
done
stop b stop
 end