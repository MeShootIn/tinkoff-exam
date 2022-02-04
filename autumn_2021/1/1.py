def isCorrect(S):
    chars = {}
    
    for char in S:
        if chars.get(char) == None:
            chars[char] = 1
        else:
            chars[char] += 1
    
    if len(chars.keys()) != 2:
        return False
    
    for char in chars.keys():
        if chars.get(char) != 2:
            return False
    
    return True



if __name__ == '__main__':
    T = int(input())
    results = [False for i in range(T)]
    
    for t in range(T):
        S = input()
        results[t] = isCorrect(S)
    
    for t in range(T):
        if results[t]:
            print('Yes')
        else:
            print('No')