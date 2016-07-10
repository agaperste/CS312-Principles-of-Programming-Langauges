#! /usr/bin/python3

#Yingzhu Zhang 
#CS312-03 A2

import string
import sys
import getopt

def main():
    #command line parsing: assume that stdin is never corrupted (provided)
    #totally would not be true in the real world
    #but for purposes of this project, allowed to make this assumption
    '''
    try:
        opts, args = getopt.getopt(sys.argv[1], "l")
    except getopt.GetoptError as err:
        print(err)
        sys.exit(2)
    for o, a in opts:
        if o in ("-l"):
            N = int(a)
            print(a)
        else:
            N = 3
    '''
    N = 3
    N = int(sys.argv[1][2])
    file_name = sys.argv[2]
    
    #prompt user to input for desired length and file name 
    #definitely an easier way to populate N and file_name
    """
    N = int(input("Length: "))
    file_name = input("File name: ") 
    """
    
    #initiate variables
    rules = dict()
    i = 0 
    worklist = []
    generated = []
    file = open(file_name, "r")
    
    #read and store all the productions 
    line = file.readline()
    while line != "":
        i += 1
        one_rule = line.split()
        
        if one_rule[0] not in rules.keys():
            rules[one_rule[0]] = []
        new = []
        j = 2 #rhs starts at index 2
        while j <= (len(one_rule) -1):
            new.append(one_rule[j])
            j += 1
        rules[one_rule[0]].append(new)
        line = file.readline()
    
    #find the start symbol
    file.seek(0) 
    cur_line = file.readline()
    cur_line = cur_line.split()
    
    #push the start symbol onto the worklist 
    worklist.append([cur_line[0]])
    
    file.close()
    
    #while the worklist is not empty 
    while len(worklist) != 0:
        
        #get and delete one potential sentence s from the worklist
        s = worklist.pop()
        
        #if the |s|>N, continue 
        if len(s) > N:
            continue 
        
        count = 0
        first_key = 0
        for z in range(len(s)):
            if str(s[z]) not in rules:
                count += 1
            else: #if non-terminal, save the position and break 
                first_key = z
                break
            
        #no nonterminals, print s and continue
        if count == len(s):
            for el in s:
                print (el, end=" ")
            print ()
        else:
            #choose the leftmost nonterminal NT
            key = s[first_key] 
            tmp = list(s)
            tmp.pop(first_key)
            
            #for all productions NT -> rhs
            for m in range(len(rules[key])):
                #replace NT in s with rhs; call it tmp
                tmp = list(s)
                tmp.pop(first_key)
                
                #store tmp on worklist
                for n in range(len(rules[key][m])):
                    tmp.insert(first_key + n, rules[key][m][n])
                worklist.append(tmp)
            
if __name__ == "__main__":
    main()