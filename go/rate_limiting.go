package main

import (
	"fmt"
	"time"
)

func main() {

	fmt.Println("Rate Limiting")

	requests := make(chan int, 5)

	for i := 1; i <= 5; i++ {

		requests <- i
	}
	close(requests)

	limiter := time.Tick(2000 * time.Millisecond)

	for req := range requests {

		<-limiter
		fmt.Println("request ", req, time.Now())
	}
}
