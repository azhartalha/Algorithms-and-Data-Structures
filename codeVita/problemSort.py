if __name__ == "__main__":
    P, S = map(int, input().strip().split())
    pair = []
    for i in range(P):
        SC = list(map(int, input().strip().split()))
        NS = list(map(int, input().strip().split()))
        S = list(zip(SC, NS))
        S.sort(key=lambda x: x[0])
        pair.append([0, i+1])
        for j in range(len(S)-1):
            if S[j][1] > S[j+1][1]:
                pair[-1][0] += 1
    pair.sort(key=lambda x: x[0])
    for i in range(P):
        print(pair[i][1])