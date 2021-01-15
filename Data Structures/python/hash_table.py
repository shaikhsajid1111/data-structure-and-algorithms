
class Hash_table:
    #table to hold elements
    table = [None]*3333
    num_items = 0 #to keep a track of number of element
    
    def resize(self):
        """resizes the able if its 80"""
        new_table = [None]*(2*len(self.table))
        new_table.extend(self.table)
        self.table = new_table

    def hash_string_to_int(self,string,table_size):
        hashed = 17
        for i in string:
            hashed = (13 * hashed * ord(i)) % table_size
        return hashed

    def add_item(self,key,value):
        self.num_items += 1
        load_factor = self.num_items / len(self.table)
        if load_factor > 0.8:
            self.resize()

        idx = self.hash_string_to_int(key,len(self.table))
        
        #if there is collision
        if self.table[idx]:
            self.table[idx].append([key,value]) 
        else:
            self.table[idx] = [[key,value]]

    def get_item(self,key):
        idx = self.hash_string_to_int(key,len(self.table))
        try:
            return self.table[idx][0][1]
        except TypeError:
            return "Not Found"

    def delete_item(self,key):
        idx = self.hash_string_to_int(key,len(self.table))
        try:
            self.table[idx] = None
        except:
            return

    def does_exist(self,key):
        idx = self.hash_string_to_int(key,len(self.table))
        if self.table[idx] is not None:
            return True
        else:
            return False
            

table = Hash_table()
table.add_item("sajid",20)
table.delete_item("sajid")
table.add_item("sajid",4000)
print(table.does_exist("sajisss"))