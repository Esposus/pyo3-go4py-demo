package main

import "C"

import (
	"fmt"
	"time"
)

//export GoLoop
func GoLoop() *C.char {
	start := time.Now()
	for i := range 1000_000_001 {
		if i%100_000_000 == 0 {
			fmt.Printf("i = %d\n", i)
		}
	}

	elapsed := time.Since(start)
	ms := float64(elapsed) / float64(time.Millisecond)
	result := fmt.Sprintf("Elapsed (Go): %.2fms", ms)

	return C.CString(result)
}

func main() {}
