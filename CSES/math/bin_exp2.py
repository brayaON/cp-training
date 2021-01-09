MOD = pow(10, 9) + 7

def exp(a, b):
    ans = 1
    b = b % MOD
    a = a % MOD
    while b > 0:
        if b % 2 != 0:
            ans = (ans * a) % MOD
        a = (a * a) % MOD
        b = b // 2

    return ans % MOD

def main():
    t = int(input())
    for _ in range(t):
        a, b, c = (int(x) for x in input().split())
        cans = exp(b,c)
        print(exp(a,cans))

if __name__ == '__main__':
    main()
