import sys

N = int(sys.stdin.readline())       # 단어 길이 최대 50
word = [sys.stdin.readline().rstrip() for _ in range(N)]

word = list(set(word))

# for i in range(len(word)-1, -1, -1):
#     for j in range(i):
#         if len(word[j]) > len(word[j+1]):
#             word[j], word[j+1] = word[j+1], word[j]
#
# for i in range(len(word)-1):
#     if len(word[i]) == len(word[i+1]):
#         if ord(word[i][0]) > ord(word[i+1][0]):
#             word[i], word[i+1] = word[i+1], word[i]
#
# for i in word:
#     print(i, end='')
# print()

cnt = [[] for _ in range(51)]
for i in word:
    cnt[len(i)].append(i)

for i in range(51):
    if cnt[i]:
        cnt[i].sort()

for i in range(51):
    if cnt[i]:
        for j in range(len(cnt[i])):
            print(cnt[i][j])

    # if len(word[i]) == len(word[i+1]):
    #     if ord(word[i][0]) > ord(word[i+1][0]):
    #         word[i], word[i+1] = word[i+1], word[i]

# for i in range(len(word)):
#     print(word[i])