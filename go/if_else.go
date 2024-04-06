package main

import "fmt"

func main() {

	fmt.Println("if else")

	if num := 12; num == 9 {

		fmt.Println("num = ", num)
	} else if num%3 == 0 {

		fmt.Println("divisible by 3")
	}
}
