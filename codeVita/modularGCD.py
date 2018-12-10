mod = 1000000009

def gcd(a, b):

    if a > b:
        tmp = a
        a = b
        b = tmp

    if a == 0:
        return b

    while a != 0:
        tmp = a
        a = b % a
        b = tmp

    return b


def custom_power(A, N):
    pows = [A % mod]
    for i in range(1, 64):
        pows.append((pows[i-1]*pows[i-1])%mod)
    i = 0
    res = 1
    while N:
        if N % 2:
            res = (res * pows[i]) % mod
        N //= 2
        i += 1
    return res

if __name__ == "__main__":
    T = int(input().strip())
    for a0 in range(T):
        A, B, N = map(int, input().strip().split())
        if abs(A - B):
            mod = abs(A - B)
        print(gcd(custom_power(A, N) + custom_power(B, N), abs(A - B))%1000000007)
        mod = 1000000007
