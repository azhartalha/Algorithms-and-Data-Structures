#problem src: https://codeforces.com/contest/1092/problem/D1

# Vova's family is building the Great Vova Wall (named by Vova himself). Vova's parents, grandparents, grand-grandparents contributed to it. Now it's totally up to Vova to put the finishing touches.
#
# The current state of the wall can be respresented by a sequence a of n integers, with ai being the height of the i-th part of the wall.
#
# Vova can only use 2×1 bricks to put in the wall (he has infinite supply of them, however).
#
# Vova can put bricks horizontally on the neighboring parts of the wall of equal height. It means that if for some i the current height of part i is the same as for part i+1, then Vova can put a brick there and thus increase both heights by 1. Obviously, Vova can't put bricks in such a way that its parts turn out to be off the borders (to the left of part 1 of the wall or to the right of part n of it).
#
# The next paragraph is specific to the version 1 of the problem.
#
# Vova can also put bricks vertically. That means increasing height of any part of the wall by 2.
#
# Vova is a perfectionist, so he considers the wall completed when:
#
# all parts of the wall has the same height;
# the wall has no empty spaces inside it.
# Can Vova complete the wall using any amount of bricks (possibly zero)?
#
# Input
# The first line contains a single integer n (1≤n≤2⋅105) — the number of parts in the wall.
#
# The second line contains n integers a1,a2,…,an (1≤ai≤109) — the initial heights of the parts of the wall.
#
# Output
# Print "YES" if Vova can complete the wall using any amount of bricks (possibly zero).
#
# Print "NO" otherwise.

n = int(input())

arr = list(map(int, input().split()))
arr = list(map(lambda x: x%2, arr))

stack = []

for i in range(n):
    if len(stack):
        if stack[-1] == arr[i]:
            stack.pop()
        else:
            stack.append(arr[i])
    else:
        stack.append(arr[i])

if len(stack) == 0 or len(stack) == 1:
    print("YES")

else:
    print("NO")
