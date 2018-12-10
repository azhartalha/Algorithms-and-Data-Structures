def mindistance(fileStream, firstWord, secondWord):
    fl, sl = len(firstWord), len(secondWord)
    for i in range(len(fileStream)-(fl+sl)+1):
        for j in range(len(fileStream)-i-(fl + sl)+1):
            if (fileStream[j:j+fl] == firstWord and fileStream[j + i + fl: j + i + fl + sl] == secondWord) or (
                    fileStream[j:j+sl] == secondWord and fileStream[j + i + sl: j + i + fl + sl] == firstWord):
                return i

    return -1


file = input()

firstWord = input()
secondWord = input()

print(mindistance(file, firstWord, secondWord))