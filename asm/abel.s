	.name "Abel"
	.comment "L'amer noir."

	sti r1, %2, r3
	live r1
	ld %1, r3
	zjmp %10
	sub r1, r2, r3
	add r1, r2, r3
	zjmp %:bb
bb:	live %22
