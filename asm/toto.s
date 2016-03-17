	.name "zork"
	.comment "just a basic living prog"
l2:
	sti r12,%1,%42
	and %12,%0,r1
live:	zjmp %:live
	zjmp %:live
