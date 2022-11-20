//# 打飞机

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#define T 10
#define R 23
#define C 49
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
int difficulty = 1, tim, score, HP, asd;
char ch;
int xx, yy, cnt, p1, p2, q1, q2;
bool bul[R+5][C+5], Bul[R+5][C+5];
int occ[R+5][C+5];
char board[R+5][80], last[R+5][80];
int llast;
bool ls, t2, t3;

void gotoxy(int x, int y) {
   COORD coord = {y, x};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printxy(int x, int y, char ch) {
   COORD coord = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
   putchar(ch);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a > b ? b : a;
}

struct enemy {
    bool dead;
    int x, y;
    int type;
    int blood;
}enemies[1000010];

int gtt, gtx, gty;

int rand_gt_type(void) {
    switch (rand() % 5) {
        case 0: case 1: {
            switch (rand() % 10) {
                case 0: case 1: {
                    return 3;
                    break;
                }
                case 2: case 3: case 4: {
                    return 2;
                    break;
                }
                case 5: case 6: case 7: case 8: case 9: {
                    return 1;
                    break;
                }
            }
            break;
        }
        case 2: case 3: {
            switch (rand() % 3) {
                case 0: case 1: {
                    return 4;
                    break;
                }
                case 2: {
                    return 5;
                    break;
                }
            }
            break;
        }
        case 4: {
            return 6;
            break;
        }
    }
}

void draw_gt(int x, int y, int type) {
    if (type == 0) return;
    if (gtx >= 0) for (int i = 0; i <= 4; i++) board[x][y+i] = '-';
    for (int i = 0; i <= 4; i++) board[x+2][y+i] = '-';
    if (gtx >= -1)board[x+1][y] = board[x+1][y+4] = '|';
    if (gtx >= -1) switch (type) {
        case 1: case 2: case 3: {
            board[x+1][y+1] = '+';
            board[x+1][y+2] = 49 + (1 << (type - 1));
            board[x+1][y+3] = '0';
            break;
        }
        case 4: case 5: {
            board[x+1][y+1] = '^';
            board[x+1][y+2] = 'x';
            board[x+1][y+3] = 46 + type;
            break;
        }
        case 6: {
            board[x+1][y+1] = '1';
            board[x+1][y+2] = 'U';
            board[x+1][y+3] = 'P';
            break;
        }
    }
}

void RND(void) {
    srand(time(0));
    int ASDFGHJKL = rand();
    while (ASDFGHJKL--) srand(rand());
}

void start(void) {
    system("cls");
    tim = score = HP = asd = ch = xx = yy = cnt = p1 = p2 = q1 = q2 = llast = ls = t2 = t3 = 0;
    memset(bul, 0, sizeof(bul));
    memset(Bul, 0, sizeof(Bul));
    memset(occ, 0, sizeof(occ));
    memset(board, 0, sizeof(board));
    memset(last, 0, sizeof(last));
    memset(enemies, 0, sizeof(enemies));
    system("cls");
    for (int i = 0; i <= R+1; i++) {
        for (int j = 0; j <= 78; j++) {
            if (i == 0 || j == 0 || i == R+1 || j == 78) putchar('#');
            else putchar(32);
        }
        if (i != R+1) putchar(10);
    }
    gotoxy(7, 34);
    printf("请选择难度");
    gotoxy(10,35);
    printf("简单模式");
    gotoxy(13,35);
    printf("中等模式");
    gotoxy(16,35);
    printf("困难模式");
    gotoxy(difficulty * 3 + 7, 33);
    putchar('>');
    while ((ch = getch()) != 10 && ch != 13) {
        if (ch == -32) {
            ch = getch();
            if (ch == 72) if (difficulty != 1) {
                gotoxy(difficulty * 3 + 7, 33);
                putchar(' ');
                gotoxy((--difficulty) * 3 + 7, 33);
                putchar('>');
            }
            if (ch == 80) if (difficulty != 3) {
                gotoxy(difficulty * 3 + 7, 33);
                putchar(' ');
                gotoxy((++difficulty) * 3 + 7, 33);
                putchar('>');
            }
        }
    }
    switch(difficulty) {
        case 1: {
            tim = 12;
            p1 = 7;
            q1 = 1;
            p2 = 5;
            q2 = 1;
            break;
        }
        case 2: {
            tim = 10;
            p1 = 6;
            q1 = 1;
            p2 = 4;
            q2 = 1;
            break;
        }
        case 3: {
            tim = 8;
            p1 = 5;
            q1 = 1;
            p2 = 3;
            q2 = 1;
            break;
        }
    }
    system("cls");
}

int length(int type) {
    return 2 + (1 << (type - 1));
}

int width(int type) {
    return 3 + (1 << type);
}

int blood(int type) {
    if (type == 3) return 5;
    return type;
}

bool GAMEOVER(void) {
    for (int i = yy-2; i <= yy+2; i++) {
        if (occ[xx+1][i] || Bul[xx+1][i]) return 1;
    }
    for (int i = yy-1; i <= yy+1; i++) {
        if (occ[xx+2][i] || Bul[xx+2][i]) return 1;
    }
    return 0;
}

bool create_enemy(int pos, int type) {
    for (int i = max(pos, 1); i <= min(pos + width(type) - 1, C); i++) if (occ[1][i]) return 0;
    cnt++;
    enemies[cnt].x = 2 - length(type);
    enemies[cnt].y = pos;
    enemies[cnt].dead = 0;
    enemies[cnt].type = type;
    enemies[cnt].blood = blood(type);
    return 1;
}

void attack_enemy(int a) {
    enemies[a].blood--;
}

void paint(int x, int y, int xx, int yy, char ch) {
    x = max(x, 1);
    y = max(y, 1);
    xx = min(xx, R);
    yy = min(yy, C);
    for (int i = x; i <= xx; i++) {
        for (int j = y; j <= yy; j++) {
            board[i][j] = ch;
        }
    }
}

void draw_plane(int x, int y) {
    board[x][y] = '|';
    paint(x+1, y-2, x+1, y+2, '*');
    board[x+2][y] = '*';
    board[x+1][y-3] = board[x+2][y-1] = '\\';
    board[x+1][y+3] = board[x+2][y+1] = '/';
}

void draw_enemy(int x, int y, int type, bool broken) {
    paint(x, y, x, y, '/');
    paint(x+length(type)-1, y+width(type)-1, x+length(type)-1, y+width(type)-1, '/');
    paint(x+length(type)-1, y, x+length(type)-1, y, '\\');
    paint(x, y+width(type)-1, x, y+width(type)-1, '\\');
    paint(x, y+1, x, y+width(type)-2, '-');
    paint(x+length(type)-1, y+1, x+length(type)-1, y+width(type)-2, '-');
    paint(x+1, y, x+length(type)-2, y, '|');
    paint(x+1, y+width(type)-1, x+length(type)-2, y+width(type)-1, '|');
    paint(x+1, y+1, x+length(type)-2, y+width(type)-2, ' ');
    if (broken) {
        if (type == 2) {
            paint(x, y+2, x, y+2, 'v');
            paint(x, y+4, x, y+4, 'v');
            paint(x+1, y, x+1, y, '>');
            paint(x+1, y+4, x+1, y+4, '*');
            paint(x+2, y+2, x+2, y+2, '*');
            paint(x+2, y+6, x+2, y+6, '<');
            paint(x+3, y+2, x+3, y+2, '^');
            paint(x+3, y+4, x+3, y+4, '^');
        } else {
            paint(x, y+2, x, y+2, 'v');
            paint(x, y+5, x, y+5, 'v');
            paint(x, y+8, x, y+8, 'v');
            paint(x+1, y, x+1, y, '>');
            paint(x+3, y, x+3, y, '>');
            paint(x+1, y+8, x+1, y+8, '*');
            paint(x+2, y+2, x+2, y+2, '*');
            paint(x+2, y+6, x+2, y+6, '*');
            paint(x+3, y+4, x+3, y+4, '*');
            paint(x+3, y+8, x+3, y+8, '*');
            paint(x+4, y+2, x+4, y+2, '*');
            paint(x+2, y+10, x+2, y+10, '<');
            paint(x+4, y+10, x+4, y+10, '<');
            paint(x+5, y+2, x+5, y+2, '^');
            paint(x+5, y+5, x+5, y+5, '^');
            paint(x+5, y+8, x+5, y+8, '^');
        }
    }
}

void kill_enemy(void) {
    for (int i = 1; i <= cnt; i++) {
        if (!enemies[i].dead && enemies[i].blood <= 0) score += blood(enemies[i].type), asd++;
        if (!enemies[i].dead && (enemies[i].blood <= 0 || enemies[i].x == R+1)) enemies[i].dead = 1;
    }
}

void show_enemy(void) {
    memset(occ, 0, sizeof(occ));
    for (int i = 1; i <= cnt; i++) {
        if (!enemies[i].dead) {
            for (int x = max(enemies[i].x, 1); x <= min(enemies[i].x + length(enemies[i].type) - 1, R); x++) {
                for (int y = max(enemies[i].y,  1); y <= min(enemies[i].y + width(enemies[i].type) - 1, C); y++) {
                    occ[x][y] = i;
                }
            }
        }
    }
}

void move_enemy() {
    for (int i = 1; i <= cnt; i++) {
        if (!enemies[i].dead) {
            enemies[i].x++;
            if (enemies[i].type == 1) {
                if (rand() % 30 == 0) Bul[enemies[i].x + 3][enemies[i].y + 2] = 1;
            }
            if (enemies[i].type == 2) {
                if (rand() % 20 == 0) Bul[enemies[i].x + 4][enemies[i].y + 3] = 1;
            }
            if (enemies[i].type == 3) {
                if (rand() % 10 == 0) Bul[enemies[i].x + 6][enemies[i].y + 4] = 1;
                if (rand() % 10 == 0) Bul[enemies[i].x + 6][enemies[i].y + 6] = 1;
            }
        }
    }
}

void draw_score(void) {
    board[3][58] = -75;
    board[3][59] = -61;
    board[3][60] = -73;
    board[3][61] = -42;
    board[3][62] = -93;
    board[3][63] = -70;
    int arr[10];
    memset(arr, 0, sizeof(arr));
    if (score == 0) board[3][64] = '0';
    else {
        int t = 0;
        int s = score;
        while (s) {
            arr[++t] = s % 10;
            s /= 10;
        }
        for (int i = t; i >= 1; i--) {
            board[3][64+t-i] = 48 + arr[i];
        }
    }
    board[6][58] = -61;
    board[6][59] = -4;
    board[6][60] = -54;
    board[6][61] = -3;
    board[6][62] = -93;
    board[6][63] = -70;
    int c = HP+1;
    while (c--) board[6][c+64] = 3;
}

void draw_line(void) {
    for (int i = 0; i <= R+1; i++) board[i][0] = board[i][C+1] = board[i][78] = '#';
    for (int i = 0; i <= 78; i++) board[0][i] = board[R+1][i] = '#';
    for (int i = C+2; i <= 78; i++) board[9][i] = '#';
}

void draw(void) {
    memcpy(last, board, sizeof(board));
    memset(board, 32, sizeof(board));
    draw_plane(xx, yy);
    for (int i = 1; i <= cnt; i++) {
        if (!enemies[i].dead) draw_enemy(enemies[i].x, enemies[i].y, enemies[i].type, (enemies[i].type != 1 && enemies[i].blood <= enemies[i].type * 2 - 3));
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (bul[i][j]) board[i][j] = '^';
            if (Bul[i][j]) board[i][j] = 'v';
        }
    }
    draw_gt(gtx, gty, gtt);
    draw_score();
    draw_line();
}

void create_gt(void) {
    gtt = rand_gt_type();
    gtx = -1;
    gty = rand() % (C-4) + 1;
}

bool in_gt(int x, int y) {
    return (x >= gtx && x <= gtx + 2 && y >= gty && y <= gty + 4);
}

bool get_gt(void) {
    if (in_gt(xx, yy)) return 1;
    for (int i = yy-1; i <= yy+1; i++) if (in_gt(xx+1, i)) return 1;
    for (int i = yy-1; i <= yy+1; i++) if (in_gt(xx+2, i)) return 1;
    return 0;
}

void use_gt(void) {
    switch(gtt) {
        case 1: {
            score += 20;
            break;
        }
        case 2: {
            score += 30;
            break;
        }
        case 3: {
            score += 50;
            break;
        }
        case 4: {
            score += 10;
            t2 = 1;
            break;
        }
        case 5: {
            score += 10;
            t3 = 1;
            break;
        }
        case 6: {
            score += 10;
            HP++;
            break;
        }
    }
    gtt = 0;
}

void move_gt(void) {
    gtx++;
    if (gtx == R+1) gtt = 0;
}

void print(void) {
    for (int i = 0; i <= R+1; i++) {
        for (int j = 0; j <= 79; j++) {
            if (board[i][j] != last[i][j]) {
                printxy(j, i, board[i][j]);
            }
        }
    }
}

bool end(void) {
    system("cls");
    for (int i = 0; i <= R+1; i++) {
        for (int j = 0; j <= 78; j++) {
            if (i == 0 || j == 0 || i == R+1 || j == 78) putchar('#');
            else putchar(32);
        }
        if (i != R+1) putchar(10);
    }
    gotoxy(5, 35);
    switch(difficulty) {
        case 1: {
            printf("简单模式");
            break;
        }
        case 2: {
            printf("中等模式");
            break;
        }
        case 3: {
            printf("困难模式");
            break;
        }
    }
    gotoxy(8, 35);
    printf("得分:%d", score);
    gotoxy(11, 34);
    printf("击落敌机%d架", asd);
    gotoxy(14, 33);
    printf("继续游戏?(Y/N)");
    while (1) {
        switch(getch()) {
            case 'Y': case 'y': {
                return 1;
                break;
            }
            case 'N': case 'n': {
                return 0;
                break;
            }
        }
    }
}

void game(void) {
    xx = 21;
    yy = 25;
    int t = 0;
    HP = 4 - difficulty;
    draw();
    for (int i = 0; i <= R+1; i++) {
        for (int j = 0; j <= 78; j++) {
            putchar(board[i][j]);
        }
        if (i != R+1) putchar(10);
    }
    while (HP--) {
    xx = 21;
    yy = 25;
    t = 0;
    llast = 0;
    ls = 0;
    while (!GAMEOVER()) {
        t++;
        if (KEY_DOWN(VK_MENU)) {
            exit(0);
        }
        if (KEY_DOWN(VK_CONTROL)) {
            getch();
        }
        if (t - llast >= 3) {
            if (KEY_DOWN(VK_RIGHT) && yy != 46) yy++, llast = t;
            if (KEY_DOWN(VK_LEFT) && yy != 4) yy--, llast = t;
        }
        if (t - llast >= 6) {
             if (KEY_DOWN(VK_DOWN) && xx != 21) xx++, llast = t;
            if (KEY_DOWN(VK_UP) && xx != 1) xx--, llast = t;
        }
        if (KEY_DOWN(VK_SPACE)) {
            if (!ls) 
            if (t3) bul[xx][yy] = bul[xx][yy-2] = bul[xx][yy+2] = 1;
            else if (t2) bul[xx][yy-1] = bul[xx][yy+1] = 1;
            else bul[xx][yy] = 1;
            ls = 1;
        } else ls = 0; 
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (i != 1) bul[i-1][j] = bul[i][j];
                bul[i][j] = 0;
                if (bul[i-1][j]) {
                    if (occ[i-1][j]) {
                        attack_enemy(occ[i-1][j]);
                        bul[i-1][j] = 0;
                    } else if (occ[i][j]) {
                        attack_enemy(occ[i][j]);
                        bul[i-1][j] = 0;
                    }   
                }
            }
        }
        if (get_gt()) use_gt();
        kill_enemy();
        show_enemy();
        draw();
        print();
        if (t % (tim>>1) == 0) {
            for (int i = R; i >= 1; i--) {
                for (int j = 1; j <= C; j++) {
                    if (i != R) Bul[i+1][j] = Bul[i][j];
                    Bul[i][j] = 0;
                }
            }
        }
        if (t % tim == 0) {
            if (gtt) move_gt();
            move_enemy();
            if (rand() % p1 < q1) {
                int type;
                switch(rand() % 13) {
                    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: {
                        type = 1;
                        break;
                    }
                    case 9: case 10: case 11: {
                        type = 2;
                        break;
                    }
                    default: {
                        type = 3;
                        break;
                    }
                }
                create_enemy(1 + rand() % (C - width(type) + 1), type);
            }
            show_enemy();
            if (rand() % p2 < q2) {
                int type;
                switch(rand() % 13) {
                    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: {
                        type = 1;
                        break;
                    }
                    case 9: case 10: case 11: {
                        type = 2;
                        break;
                    }
                    default: {
                        type = 3;
                        break;
                    }
                }
                create_enemy(1 + rand() % (C - width(type) + 1), type);
            }
        } 
        if (t % (1000 * (difficulty + 2)) == 0) create_gt();
        Sleep(10);
    }
    gtx = gty = gtt = 0;
    t2 = t3 = 0;
    draw();
    if (occ[xx][yy] || Bul[xx][yy]) board[xx][yy] = '+';
    for (int i = yy-3; i <= yy+3; i++) if (occ[xx+1][i] || Bul[xx+1][i]) board[xx+1][i] = '+';
    for (int i = yy-1; i <= yy+1; i++) if (occ[xx+2][i] || Bul[xx+2][i]) board[xx+2][i] = '+';
    print();
    Sleep(500);
    memset(occ, 0, sizeof(occ));
    memset(enemies, 0, sizeof(enemies));
    memset(bul, 0, sizeof(bul));
    memset(Bul, 0, sizeof(Bul));
    cnt = 0;
    draw();
    print();
    }
}

void work(void) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
    RND();
    do {
        start();
        game();
    } while (end());
}
int main(){
	SetConsoleTitle("打飞机");
    work();
}

