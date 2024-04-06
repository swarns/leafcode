package main

import (
	"fmt"
)

func main() {

	fmt.Println("non blocking channel operations")

	msg_chan := make(chan string)
	signal_chan := make(chan bool)

	select {

	case msg := <-msg_chan:
		fmt.Println("received message: ", msg)

	default:
		fmt.Println("no messages received")
	}

	msg := "hii"

	select {

	case msg_chan <- msg:
		fmt.Println("sent message: ", msg)
	default:
		fmt.Println("no messages sent")
	}

	select {

	case msg := <-msg_chan:
		fmt.Println("reveiced message: ", msg)

	case sig := <-signal_chan:
		fmt.Println("received signal: ", sig)
	default:
		fmt.Println("no activity")
	}

	fmt.Println("done")
}
