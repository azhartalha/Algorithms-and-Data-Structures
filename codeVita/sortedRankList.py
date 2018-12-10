
def maxIndex(marks):
    maxi = marks[0][-1]
    index = 0
    for i in range(1, len(marks)):
        if maxi < marks[i][-1]:
            maxi = marks[i][-1]
            index= i
    return index

if __name__ == '__main__':
    N = int(input().strip())
    M = int(input().strip())
    names = []
    marks = []
    for i in range(N):
        names.append([])
        marks.append([])
        for j in range(M):
            tmp = input().strip().split()
            names[-1].append(tmp[0])
            marks[-1].append(eval(tmp[1]))
        marks[-1].reverse()
        names[-1].reverse()

    while len(marks)!=0:
        index = maxIndex(marks)
        print(names[index].pop(), marks[index].pop())
        if len(marks[index]) == 0:
            marks.pop(index)
            names.pop(index)

    # for i in range(N):
    #     for j in range(M):
    #         print(names[i][j], marks[i][j])
