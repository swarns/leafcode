package main

import (
	"fmt"
	"time"
)

func main() {

	fmt.Println("time formatting")

	t := time.Now()
	fmt.Println(t)

	fmt.Printf("year %d month %d day %d hour %d minute %d second %d millisecond %d", t.Year(), t.Month(), t.Day(), t.Hour(), t.Minute(), t.Second(), t.UnixMilli())
}
