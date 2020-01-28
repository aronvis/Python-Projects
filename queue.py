from collections import deque
class Queue:
	def __init__(self):
		self.items = deque()
	def push_back(self, value):
		self.items.append(value)
	def pop(self):
		return self.items.popleft()
	def size(self):
		return len(self.items)
	def print(self):
		for index in range(-1, self.size()+1):
			if index == -1:
				print("Front ||", end="")
			elif index == self.size():
				print("|| Back")
			else:
				print(str(self.items[index]) + "  ", end="")
		print("")
def main():
	queue = Queue()
	queue.push_back(5)
	queue.push_back(6)
	queue.print()
	queue.pop()
	queue.print()
main()



