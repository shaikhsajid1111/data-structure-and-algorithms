class stack:
    array = []
    top = 0

    def __init__(self,data):
        self.top += 1
        self.array.append(data)
    


    def push(self,data):
        self.top += 1
        self.array.append(data)
    
    def pop(self):
        if self.top == 0:
            return

        self.top-=1
        del self.array[-1]

    def print_stack(self):
        for i in range(self.top):
            print(self.array[i])

    def exists(self,value):
        for i in range(self.top):
            if self.array[i] == value:
                return True
        return False


if __name__ == "__main__":
    stac = stack(10)
    stac.push(20)
    stac.push(30)
    stac.push(40)
    stac.pop()
    
    stac.print_stack()