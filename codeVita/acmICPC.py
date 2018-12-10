def RoboGame(s):
    x, y = -1, -1
    for i in range(len(s)):
        if s[i].isdigit():
            if x == -1:
                x = i
                y = i + int(s[i])
            else:
                tmp = int(s[i])
                if y >= i - tmp:
                    return False
                x = i
                y = i + int(s[i])
    return True

T = int(input())
for a0 in range(T):
    s = input().strip()
    if RoboGame(s):
        print("safe")
    else:
        print("unsafe")