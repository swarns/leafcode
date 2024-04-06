package main

import "fmt"

func zeroval(ival int) {

	ival = 0
}

func zeroptr(iptr *int) {

	*iptr = 0
	iptr = iptr + sizeof(int)
}

func main() {

	fmt.Println("pointers")
	i := 1

	fmt.Println("initval: ", i)
	zeroval(i)
	fmt.Println("zeroval: ", i)

	fmt.Println("pointer: ", &i)
	zeroptr(&i)
	fmt.Println("zeroptr: ", i)

	fmt.Println("pointer: ", &i)
}
