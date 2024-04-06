package main

import (
	"fmt"
	"time"
)

func f(num int) {

	for i := 0; i < 5; i++ {

		fmt.Println("num: ", num)
		time.Sleep(100 * time.Millisecond)
	}
}

func main() {

	fmt.Println("goroutines")

	go f(1)
	go f(2)

	time.Sleep(time.Second)

	fmt.Println("done")
}
