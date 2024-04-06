package main

import "fmt"

func main() {

	fmt.Println("for")

	for i := 0; i < 3; i++ {

		fmt.Println("i = ", i)
	}

	for i := range 5 {

		fmt.Println("range i = ", i)
	}
}
