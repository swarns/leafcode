package main

import (
	"fmt"
	"time"
)

func main() {

	var x = 1
	fmt.Println(x)

	go func() {

		for i := 0; i < 999999999; i++ {

			x = i

			if x == -1 {

				break
			}
		}
	}()

	for i := 0; i < 5; i++ {

		time.Sleep(time.Millisecond)
		fmt.Println(x)
		if x > 99999 {

			x = -1
		}
	}

	fmt.Println("done")
}
