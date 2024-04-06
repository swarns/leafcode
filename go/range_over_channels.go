package main

import (
	"fmt"
	"time"
)

func main() {

	fmt.Println("range over channels")

	q := make(chan string, 6)
	q <- "str1"
	q <- "str2"
	q <- "str3"
	close(q)

	go func() {

		for x := range q {

			fmt.Println(x)
		}
	}()

	time.Sleep(time.Second)
}
