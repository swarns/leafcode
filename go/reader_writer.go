package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

const (
	numReaders = 10
	numWriters = 2
)

type Data struct {
	value int
}

type Reader struct {
	id    int
	data  *Data
	mutex *sync.RWMutex
}

type Writer struct {
	id    int
	data  *Data
	mutex *sync.RWMutex
}

func (r *Reader) read() {

	for {

		r.mutex.RLock()
		value := r.data.value
		r.mutex.RUnlock()
		fmt.Printf("Reader %d read: %d\n", r.id, value)
		time.Sleep(time.Millisecond)
	}

}

func (w *Writer) write() {

	for {

		value := rand.Intn(100)
		w.mutex.Lock()
		w.data.value = value
		fmt.Printf("Writer %d wrote: %d\n", w.id, value)
		w.mutex.Unlock()
		time.Sleep(time.Millisecond)
	}
}

func main() {

	fmt.Println("reader writer problem")

	data := &Data{}
	mutex := &sync.RWMutex{}

	for i := 0; i < numReaders; i++ {

		writer := &Writer{
			id:    i + 1,
			data:  data,
			mutex: mutex,
		}

		go writer.write()
	}

	for i := 0; i < numWriters; i++ {

		reader := &Reader{
			id:    i + 1,
			data:  data,
			mutex: mutex,
		}

		go reader.read()
	}

	select {}
}
