package main

import (
	"fmt"
	"math"
)

const (
	PI float64 = 3.141592
)

func main() {

	// A := 128.0
	// f := 1.0
	// B := 128.0 / 2
	// B := PI / 128

	// for i := 0; i < 256; i++ {
	// 	y := A * math.Sin(B*float64(i))
	// 	// fmt.Println(y)
	// }

	{
		// A := 128.0
		// f := 0.04

		a := -1.0 // how hi
		b := 22.0 // how long
		steps := 10

		max := 128.0
		{
			x := b * .5
			b = (max - a*x*x) / x
		}

		fmt.Println(a, b, steps, max, "------")

		for i := 0; i < steps; i++ {
			x := b * (float64(i) / float64(steps))
			// y := A * math.Sin(f*float64(i))
			y := a*x*x + b*x

			fmt.Print(int(math.Round(y)))
			for j := 0; j < int(math.Round(y)); j++ {
				fmt.Print(".")
			}
			fmt.Println()
			// fmt.Println(math.Round(y))
		}
	}

	fmt.Println("DONE!")
}
