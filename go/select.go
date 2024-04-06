package main

import (
	"fmt"
	"time"
)

func main() {

	fmt.Println("select")

	c1 := make(chan int)
	c2 := make(chan int)

	go func() {

		for i := 0; i < 3; i++ {

			time.Sleep(1 * time.Millisecond)
			c1 <- i
		}

	}()

	go func() {

		for i := 1; i < 3; i++ {

			time.Sleep(2 * time.Millisecond)
			c2 <- i
		}

	}()

	for i := 0; i < 5; i++ {

		select {

		case msg1 := <-c1:
			fmt.Println("received from c1: ", msg1)

		case msg2 := <-c2:
			fmt.Println("received from c2: ", msg2)
		}
	}

	fmt.Println("done")
}
