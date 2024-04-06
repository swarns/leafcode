package main

import (
	"fmt"
	"sync"
)

type Mlock struct {
	mu      sync.Mutex
	counter int
}

func (m *Mlock) f() {

	m.mu.Lock()
	defer m.mu.Unlock()
	m.counter++
}

func main() {

	fmt.Println("Mutexes")

	m := Mlock{

		counter: 0,
	}

	var wg sync.WaitGroup

	inc := func(n int) {

		for i := 0; i < n; i++ {

			m.counter++
		}
		wg.Done()
	}

	wg.Add(3)
	go inc(1000)
	go inc(2000)
	go inc(3000)

	wg.Wait()
	fmt.Print("counter: ", m.counter)
}
