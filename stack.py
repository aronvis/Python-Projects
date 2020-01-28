class Stack:
	def __init__(self):
		self.stack = []
	# Insert item on top of the stack (end of array)
	def appendItem(self, value):
		self.stack.append(value)
	# Remove item on top of the stack (end of array)
	def popItem(self):
		return self.stack.pop()
	# Prints the items inside the stack
	def printStack(self):
		for index in reversed(range(-1, len(self.stack)+1)):
			if index == -1:
				print("-------bottom------")
			elif index == len(self.stack):
				print("--------Top--------")
			else:
				print("	 " + str(self.stack[index]) + "	")

	def size(self):
		return len(self.stack)

def main():
	myStack = Stack()
	myStack.appendItem(1)
	myStack.appendItem(2)
	myStack.appendItem(3)
	myStack.printStack()
	print(myStack.popItem())
	myStack.size()
main()







