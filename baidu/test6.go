import (
	"sync"
	"fmt"
)

int bufferSize = 10
var buffer []int

int start = 0
int end = 0

 end ----> start

-->start    end-->

var mu sync.Mutex

func isEmpty() bool {
	return start == end
}

func consumer()  {
	mu.Lock()
	if !isEmpty() {
		fmt.Println(buffer[end])
		end = end+1
		if end>=bufferSize {
			end = 0
		}
	}
	mu.Unlock()
}

func isFull() bool {
	if start == end-1 || (start==bufferSize-1 && end==0) {
		return true
	}
	return false
}
func producer(int x) {
	mu.Lock()
	if !isFull() {
		buffer[start+1] = x
		start = start + 1
		if start>=bufferSize {
			start = 0
		}
	}
	mu.Unlock()
}
