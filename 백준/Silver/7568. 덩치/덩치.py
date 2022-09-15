N = int(input()) # N을 받고
덩치 = [] # 비교해야 하니까 x, y 값을 저장할 리스트도 만들자
for i in range(N):
    x, y = map(int, input().split()) # x, y도 받는다.
    덩치.append([x, y])

for i in range(N): 
    rank = 1 # 비교대상이 없으면 1등이니까
    for j in range(N):
        if(덩치[i][0])<덩치[j][0] and 덩치[i][1]<덩치[j][1]:
            rank += 1 # 덩치의 인자값을 비교해서 다 작으면 1을 더한다.
    print(rank, end = " ") # 결과값이 한 줄이니까 end를 바꿔준다.