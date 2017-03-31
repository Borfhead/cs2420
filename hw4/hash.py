############################
## Dylan Cox
## Hash Table
############################

class fruit:
    def __init__(self, key=0, name=''):
        self.key = key
        self.name = name
        self.isDeleted = False


class hash_table:
    def __init__(self):
        self.elems = 0
        self.table_size = 10
        self.table = []

        for i in xrange(self.table_size):
            temp = fruit()
            self.table.append(temp)
        pass

    def hashFunction(self, key):
        return key % self.table_size
    
    def insert(self, data):
        toFind = self.find(data.key)
        if toFind != 'Not Found' and toFind.isDeleted:
            toFind.isDeleted = False
            self.elems += 1
            return
        
        key = data.key
        addr = self.hashFunction(key)
        if self.table[addr].key == 0:
            self.table[addr] = data
            self.elems += 1
        else:
            for d in xrange(addr + 1, self.table_size):
                if self.table[d].key == 0:
                       self.table[d] = data
                       self.elems += 1
                       break
        if self.elems >= (self.table_size / 2):
            self.rehash()
                
        pass
    
    def find(self, key):
        addr = self.hashFunction(key)
        if self.table[addr].key == 0:
            return 'Not Found'
        elif self.table[addr].key == key:
            if self.table[addr].isDeleted != True:
                print self.table[addr].name+ ' found in table[' +str(addr)+ ']'
                return self.table[addr]
            else:
                return 'Not Found'
        else:
            for d in xrange(addr + 1, self.table_size):
                if self.table[d].key == key:
                    if self.table[d].isDeleted != True:
                        print self.table[d].name+ ' found in table[' +str(d)+ ']'
                        return self.table[d]
                    else:
                        return 'Not Found'
        return 'Not Found'
    
    def delete(self, key):
        toDel = self.find(key)
        if toDel != 'Not Found':
            if toDel.isDeleted:
                print toDel.name, 'has already been deleted'
            else:
                toDel.isDeleted = True
                print 'Deleted ' +toDel.name
                self.elems -= 1
        else:
            print 'Item does not exist'
        pass
    
    def rehash(self):
        curr = self.table
        new = []
        self.table_size *= 2
        for i in xrange(self.table_size):
            temp = fruit()
            new.append(temp)
        self.elems = 0
        self.table = new
        for i in xrange(len(curr)):
            if curr[i].key != 0:
                self.insert(curr[i])
        pass
    
    def printTable(self):
        print '**********************************'
        print 'Table Size: ' +str(self.table_size)
        print 'Elems: ' +str(self.elems)
        for d in self.table:
            if d.isDeleted:
                print d.key, d.name, '(Deleted)'
            else:
                print d.key, d.name
        print '**********************************'
        pass

if __name__ == '__main__':
    apple_gala = fruit(4133, 'apple gala')
    banana = fruit(4011, 'banana')
    basil = fruit(4885, 'basil')
    beans_green = fruit(4066, 'beans green')
    black_berries = fruit(4239, 'blackberries')
    garlic = fruit(4608, 'garlic')
    cilantro = fruit(4889, 'cilantro')
    oregano = fruit(4897, 'oregano')
    limes = fruit(4048, 'limes')
    mango = fruit(4051, 'mango')
    pineapple = fruit(4430, 'pineapple')
    spinach = fruit(4090, 'spinach')
    bean_sprouts = fruit(4536, 'bean sprouts')
    bell_pepper_red = fruit(4088, 'bell pepper red')
    broccoli = fruit(4060, 'broccoli')
    carrots = fruit(4562, 'carrots')
    cherries_red = fruit(4045, 'cherries red')
    chile_jalapeno = fruit(4693, 'chile jalapeno')
    corn_yellow = fruit(4078, 'corn yellow')
    cucumber = fruit(4062, 'cucumber')

    h = hash_table()
    h.insert(apple_gala)
    h.insert(banana)
    h.insert(basil)
    h.insert(beans_green)
    h.printTable() #print after four inserts
    raw_input('Press ENTER to continue')
    h.insert(black_berries)
    h.printTable() #print after fifth insert
    raw_input('Press ENTER to continue')
    h.insert(garlic)
    h.insert(cilantro)
    h.insert(oregano)
    h.insert(limes)
    h.printTable() #print after 9th insert
    raw_input('Press ENTER to continue')
    h.insert(mango)
    h.printTable() #print after 10th insert
    raw_input('Press ENTER to continue')
    h.insert(pineapple)
    h.insert(spinach)
    h.insert(bean_sprouts)
    h.insert(bell_pepper_red)
    h.insert(broccoli)
    h.insert(carrots)
    h.insert(cherries_red)
    h.insert(chile_jalapeno)
    h.insert(corn_yellow)
    h.insert(cucumber)
    h.printTable() #print after 20th insert
    raw_input('Press ENTER to continue\n')

    print 'Finding mango, pineapple, and limes'
    h.find(4051)
    h.find(4430)
    h.find(4048)
    print ''
    raw_input('Press ENTER to continue\n')

    print 'Deleting broccoli, banana, and spinach\n'
    h.delete(4060)
    h.delete(4011)
    h.delete(4090)
    print ''
    raw_input('Press ENTER to continue\n')

    print 'Finding deleted items\n'
    print h.find(4060)
    print h.find(4011)
    print h.find(4090)
    print ''
    raw_input('Press ENTER to continue\n')
    
    print 'Printing final table:\n'
    h.printTable()

    
    
