package main

import (
	"fmt"
	"time"
)

func main() {

	fmt.Println("closing channels")

	jobs := make(chan int, 5)
	done := make(chan bool)

	go func() {

		for {

			j, more := <-jobs
			if more {

				fmt.Println("received job: ", j)
			} else {

				fmt.Println("received all jobs")
				done <- true
				return
			}
		}

	}()

	for j := 0; j < 3; j++ {

		time.Sleep(100 * time.Millisecond)
		jobs <- j
		fmt.Println("sent job: ", j)
	}

	close(jobs)
	fmt.Println("sent all jobs")
	<-done

	_, ok := <-jobs
	fmt.Println("received more jobs: ", ok)

}
