package main

import (
	"fmt"
	"os"
	"time"
)

func main() {

	fmt.Println("exit")

	defer fmt.Println("!!!")

	time.Sleep(time.Second)
	os.Exit(3)

	fmt.Println("exited")
}
