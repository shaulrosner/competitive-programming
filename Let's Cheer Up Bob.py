import sys


def won(b):
    col = [0, 0, 0]
    row = [0, 0, 0]
    diag = [0, 0]
    for i in range(3):
        for j in range(3):
            row[i] += b[i][j]
            if row[i] == 3:
                return 1
            if row[i] == -3:
                return -1
            col[j] += b[i][j]
            if col[j] == 3:
                return 1
            if col[j] == -3:
                return -1
            if i==j:
                diag[0] += b[i][j]
                if diag[0] == 3:
                    return 1
                if diag[0] == -3:
                    return -1
            if i+j == 2:
                diag[1] += b[i][j]
                if diag[1] == 3:
                    return 1
                if diag[1] == -3:
                    return -1
    return 0

def printall(print_moves):
    for move in print_moves:
        print('{0} {1}'.format(move[0] + 1, move[1] + 1))
    sys.exit(0)

def next_move(b, who, doneb, doney):
    if who==1:
        for i in range(1, 9):
            if moves[i] not in doneb and moves[i] not in doney:
                b[moves[i][0]][moves[i][1]] = 1
                doneb.append(moves[i])
                break
        if won(b) == 1:
            if len(doney) not in success:
                success[len(doney)] = doney.copy()
            return
        next_move([x.copy() for x in b], 0, doneb, doney)
        return
    stuck = True
    for move in best_moves:
        if len(doney) == 0 or doney[-1] == move:
            stuck = False
        if stuck:
            continue
        if move in doneb or move in doney:
            continue
        b_copy = [x.copy() for x in b]
        done_copy = doney.copy()
        b_copy[move[0]][move[1]] = -1
        done_copy.append(move)
        if won(b_copy) == -1:
            continue
        next_move(b_copy, 1, doneb.copy(), done_copy)
if __name__ == '__main__':
    success = {}
    moves = []
    for i in range(9):
        l = input().split()
        x, y = int(l[0]) - 1, int(l[1]) - 1
        moves.append((x, y))
    b = [[0 for i in range(3)]for j in range(3)]
    best_moves = sorted(moves)
    b[moves[0][0]][moves[0][1]] = 1
    done = [moves[0]]
    next_move(b, 0, done.copy(), [])
    for i in range(9):
        if i in success:
            printall(success[i])


        
    
    