package main

import "fmt"

func intSeq() func() int {

	i := 0

	return func() int {

		i++
		return i
	}

}

func main() {

	fmt.Println("closures")

	nextInt := intSeq()

	fmt.Println(nextInt())
	fmt.Println(nextInt())
	fmt.Println(nextInt())

	newInt := intSeq()
	fmt.Println(newInt())
}
