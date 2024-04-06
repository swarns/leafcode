package main

import (
	"fmt"
)

func main() {

	fmt.Println("channels")

	msg_chan := make(chan string)

	go func() { msg_chan <- "ping1" }()
	go func() { msg_chan <- "ping2" }()
	go func() { msg_chan <- "ping3" }()

	msg := <-msg_chan

	fmt.Println(msg)
}
