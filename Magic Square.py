n = int(input())
matrix = []
for i in range(n):
    row = [int(x) for x in input().split(' ')]
    matrix.append(row)
main_diag_sum = 0
anti_diag_sum = 0
row_sums = []
col_sums = []
for i in range(n):
    main_diag_sum += matrix[i][i]
    anti_diag_sum += matrix[i][n-1-i]
    row_sums.append(sum([matrix[i][x] for x in range(n)]))
    col_sums.append(sum([matrix[x][i] for x in range(n)]))
bad = []

for i in range(n):
    if col_sums[n-i-1] != main_diag_sum:
        bad.append(-(n - i))
if anti_diag_sum != main_diag_sum:
    bad.append(0)
for i in range(n):
    if row_sums[i] != main_diag_sum:
        bad.append(i+1)
print(len(bad))
for b in bad:
    print(b)
