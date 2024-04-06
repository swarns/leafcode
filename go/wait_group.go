package main

import (
	"fmt"
	"sync"
	"time"
)

func worker(id int) {

	fmt.Printf("worker %d starting\n", id)
	time.Sleep(time.Second)
	fmt.Printf("worker %d is done\n", id)
}

func main() {

	fmt.Println("wait group")

	var wg sync.WaitGroup

	for i := 0; i <= 5; i++ {

		wg.Add(1)

		go func() {

			defer wg.Done()
			worker(i)
		}()
	}

	wg.Wait()
}
