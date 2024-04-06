package main

import (
	"fmt"
	"time"
)

const (
	numItems  = 5
	maxBuffer = 20
)

func producer(id int, ch chan<- int) {

	for i := 0; i < numItems; i++ {

		ch <- i
		fmt.Printf("producer %d produced: %d \n", id, i)
		time.Sleep(time.Millisecond)
	}
	close(ch)
}

func consumer(id int, ch <-chan int, done chan<- bool) {

	for item := range ch {

		fmt.Printf("consumer %d consumed: %d \n", id, item)
		time.Sleep(time.Millisecond)
	}

	done <- true
}

func main() {

	fmt.Println("producer cosumer")

	ch := make(chan int, maxBuffer)
	done := make(chan bool)

	go producer(1, ch)
	go consumer(1, ch, done)
	go consumer(2, ch, done)

	<-done
	fmt.Println("consumer finished")

}
