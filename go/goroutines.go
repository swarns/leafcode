package main

import (
	"fmt"
	"time"
)

func f(from string) {

	for i := 0; i < 3; i++ {

		fmt.Println(from, ":", i)
	}
}

func main() {

	fmt.Println("Goroutines")

	f("direct")

	go f("goroutine")

	go func(msg string) {

		for i := 0; i < 3; i++ {

			fmt.Println(msg)
		}
	}("going")

	time.Sleep(time.Second)

	fmt.Println("done")
}
