;Find misisng element from 2nd array on comparision with 1st array 
	area aa,code,readonly
	entry
	ldr r0,=0x40000000
	ldr r1,=arr1
	mov r6,#5
loop cmp r6,#0
	 ble done
	 ldr r2,=arr2
	 mov r5,r2
	 ldrb r4,[r1],#1
	 sub r6,r6,#1
	 mov r3,#5
loop1 cmp r3,#0
	  ble store
	 ldrb r5,[r2],#1
	 sub r3,r3,#1
	 cmp r4,r5
	 beq loop
	 bne loop1
store strb r4,[r0],#1
	  b loop
done
stop b stop
arr1 dcb 0x01,0x02,0x03,0x04,0x11
arr2 dcb 0x01,0x03,0x05,0x07,0x10
	end
;0x4000000-0x4FFFFFFF