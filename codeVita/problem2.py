T = int(input())

for a0 in range(T):
    n, k = map(int, input().split())
    a = sorted(list(map(int, input().split())))

    if n == 1:
        print(a[0])
        continue

    res = 0
    tmp = 0
    for i in range(n):
        if a[i] > k:
            tmp += a[i] - k

    for i in range(n - 1):
        if a[i] <= k:
            res += a[i]
        else:
            res += k
            tmp -= (a[i] - k)*2

    print(res+tmp, tmp)

