package main

import "fmt"

func vals() (int, int) {

	return 1, 5
}

func main() {

	fmt.Println("multipleReturn")

	a, b := vals()
	fmt.Println(a)
	fmt.Println(b)

	_, c := vals()

	fmt.Println(c)
}
