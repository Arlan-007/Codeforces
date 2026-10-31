package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t, n int
	fmt.Fscan(in, &t)
	for ; t > 0; t-- {
		fmt.Fscan(in, &n)

		last := 4
		if n%3 == 1 {
			last = 2
		}

		fmt.Fprintln(out, 3*(n-last/2+1))

		for i := 0; i < 3; i++ {
			for v := 2 * n; v >= last; v -= 2 {
				fmt.Fprint(out, v, " ")
			}
		}
		fmt.Fprintln(out)
	}
}
