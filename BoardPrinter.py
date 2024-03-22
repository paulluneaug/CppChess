def PrintBoard(width : int, height : int):
    boardSize = width * height
    largestNumberLen = len(str(width * height - 1))
    lineSeparator = f"+{('-' * (largestNumberLen + 2) + '+') * width}"
    
    print(lineSeparator)
    for y in range(height):
        line = "|"
        for x in range(width):
            n = y * width + x
            line += f" {(largestNumberLen - len(str(n))) * ' '}{n} |"
        print(line)
        print(lineSeparator)
        
PrintBoard(8, 8)
            
             
    