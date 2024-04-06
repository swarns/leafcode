package main

import (
	"fmt"
	"time"
)

func main() {

	fmt.Println("channel buffering")

	message_chan := make(chan string, 2)

	message_chan <- "buffered"
	message_chan <- "channel"

	fmt.Println(<-message_chan)
	time.Sleep(time.Millisecond)
	fmt.Println(<-message_chan)
	//fmt.Println(<-message_chan)
}
