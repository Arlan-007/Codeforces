package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod int64 = 1000000007
const maxN = 100005

func power(a, b int64) int64 {
	result := int64(1)
	for b > 0 {
		if b%2 == 1 {
			result = result * a % mod
		}
		a = a * a % mod
		b /= 2
	}
	return result
}

func main() {
	in := bufio.NewReaderSize(os.Stdin, 1<<20)
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	fact := make([]int64, maxN+1)
	invFact := make([]int64, maxN+1)

	fact[0] = 1
	for i := 1; i <= maxN; i++ {
		fact[i] = fact[i-1] * int64(i) % mod
	}

	invFact[maxN] = power(fact[maxN], mod-2)
	for i := maxN; i > 0; i-- {
		invFact[i-1] = invFact[i] * int64(i) % mod
	}

	var t int
	fmt.Fscan(in, &t)
	for ; t > 0; t-- {
		var n int
		fmt.Fscan(in, &n)

		a := make([]int64, n)
		b := make([]int64, n+1)

		for i := 1; i <= n; i++ {
			fmt.Fscan(in, &b[i])
		}

		for i := n; i >= 1; i-- {
			mask := b[i]
			if mask == 0 {
				continue
			}

			for j := 0; j < i; j++ {
				a[j] |= mask
			}

			for j := 1; j <= i; j++ {
				C := fact[i] * invFact[j] % mod * invFact[i-j] % mod
				b[j] = (b[j] - mask*C%mod + mod) % mod
			}
		}

		for _, x := range a {
			fmt.Fprint(out, x, " ")
		}
		fmt.Fprintln(out)
	}
}
