package main

import "fmt"

func mayPanic() {

	panic("a problem occured panic")
}

func main() {

	fmt.Println("Recover")

	defer func() {

		if r := recover(); r != nil {

			fmt.Println("Recovered Error: \n", r)
		}
	}()

	mayPanic()

	fmt.Print("after mayPanic()")
}
