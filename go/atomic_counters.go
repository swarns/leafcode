package main

import (
	"fmt"
	"sync"
	"sync/atomic"
)

func main() {

	fmt.Println("atomic counters")

	var ops atomic.Uint64

	var wg sync.WaitGroup

	x := 0

	for i := 0; i <= 500; i++ {

		wg.Add(1)

		go func() {

			for c := 0; c <= 1000; c++ {

				ops.Add(1)
				x++
			}

			wg.Done()
		}()

	}

	wg.Wait()
	fmt.Println("ops: ", ops.Load())
	fmt.Println("x: ", x)
}
