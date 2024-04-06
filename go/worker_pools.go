package main

import (
	"fmt"
	"time"
)

func worker(id int, jobs <-chan int, results chan<- int) {

	for j := range jobs {

		fmt.Println("worker ", j, "started job ", j)
		time.Sleep(time.Millisecond)
		fmt.Println("worker ", j, " finished job ", j)
		results <- j * 2
	}
}

func main() {

	fmt.Println("worker pools")
	const numJobs = 5
	jobs := make(chan int, numJobs)
	results := make(chan int, numJobs)

	for w := 1; w < 3; w++ {

		go worker(w, jobs, results)
	}

	for j := 1; j < numJobs; j++ {

		jobs <- j
	}
	close(jobs)

	time.Sleep(2 * time.Second)

	for a := 1; a < numJobs; a++ {

		fmt.Println(<-results)
	}

	fmt.Println("done")
}
