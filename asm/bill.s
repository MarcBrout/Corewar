	.name "Bill"
	.comment "Equilibre"

	sti r1, %42, %1
	fork %42
	ld %100, r4
	ld %2, r5

	live %1


	sti r5, r4, r1
	add r4, r5, r4
	ld %0, r8
	zjmp %42
