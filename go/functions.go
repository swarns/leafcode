package main

import "fmt"

func plus(a int, b int) int {

	return a + b
}

func plusPlus(a, b, c int) int {

	return a + b + c
}

func main() {

	fmt.Println("functions")

	fmt.Println("plus: ", plus(1, 2))
	fmt.Println("plusPlus: ", plusPlus(1, 2, 3))

}
