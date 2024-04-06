package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {

	fmt.Println("wait group")

	var wg sync.WaitGroup

	for i := 0; i <= 5; i++ {

		wg.Add(1)
		go func() {

			defer wg.Done()

			fmt.Printf("work %d started\n", i)
			time.Sleep(time.Millisecond)
			fmt.Printf("work %d done\n", i)
		}()

	}

	wg.Wait()

}
