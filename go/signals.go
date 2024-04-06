package main

import (
	"fmt"
	"os"
	"os/signal"
	"syscall"
)

func main() {

	fmt.Println("signals")

	sigs := make(chan os.Signal, 2)

	signal.Notify(sigs, syscall.SIGINT, syscall.SIGTERM)

	done := make(chan bool, 2)

	go func() {

		sig := <-sigs
		fmt.Println(sig)
		done <- true
	}()

	fmt.Println("awaiting signal")
	<-done
	fmt.Println("exiting")

}
