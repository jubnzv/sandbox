def rotateImage(m): return list(zip(*m[::-1]))

if __name__ == '__main__':
    arr = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(rotateMatrix(arr))
