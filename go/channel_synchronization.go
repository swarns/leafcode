package main

import (
	"fmt"
	"time"
)

func worker(done chan int) {

	fmt.Println("working")
	time.Sleep(time.Second)
	fmt.Println("done")

	done <- 2
}

func main() {

	fmt.Println("channel synchronization")

	done := make(chan int, 1)
	go worker(done)

	<-done
}
