	.name		"Lebrun"
	.comment	"Jaime"

	sti r1, %42, %1

	live %4920
	fork %42
	ld %0, r3
	zjmp %42
