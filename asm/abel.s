	.name "Abel"
	.comment "L'amer noir."

	sti r1, %2, %3
	live %234
	ld %0, r3
	zjmp %1
	sub r1, r2, r3
	add r1, r2, r3
