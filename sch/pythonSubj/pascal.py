def pascalTriangle(arr): 
    length = len(arr)
    if(length > loop): #입력 받은 루프만큼 돌았으면 재귀함수 탈출
        return 

    print(arr)
    arr.append(1)
    afterArr = list(arr)
    for i in range(1, length):
        arr[i] = afterArr[i-1] + afterArr[i]
    pascalTriangle(arr)


if __name__ == '__main__':
    loop = int(input())
    arr = [1]
    if (loop > 10 or loop < 3):
        print("3~10의 숫자만 입력 가능합니다")
    else :
        pascalTriangle(arr)