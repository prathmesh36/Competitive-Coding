#include <stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define toLower(c) ((c >= 'A' && c <= 'Z') ? (c-'A'+'a') : (c))
int t, n, i, j, k;
void find(char str[], char map[][60]) {
    static int D[][2] = {{0,1},{1,0},{0,-1},
                        {1,1},{1,-1},{-1,1},{-1,-1}};
    int i, j, k, x, y, idx;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < 7; k++) {
                x = i, y = j, idx = 0;
                while(map[x][y] == str[idx]) {

	                    x += D[k][0], y += D[k][1];
	                    idx++;
	                    if(str[idx] == '\0') {

	                        printf("%d,%d %d,%d\n", i+1, j+1,x+1-D[k][0],y+1-D[k][1]);
	                        return;
	                    }
	                    if(x < 0 || y < 0 || x >= n || y >= n)
	                    {
	                        break;
	                    }
                  }
                }
            }
        }
    printf("Not found\n");
}
int main() {
        scanf("%d", &n);
        char map[60][60], str[60];
        for(i = 0; i < n; i++) {
            scanf("%s", &map[i]);
        }
        scanf("%s", str);
        while(strcmp(str,"0")) {
            find(str, map);
            scanf("%s", str);
        }

    return 0;
}

/*
#include <stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define toLower(c) ((c >= 'A' && c <= 'Z') ? (c-'A'+'a') : (c))
int t, n, i, j, k;
void find(char str[], char map[][60]) {
    static int D[][2] = {{0,1},{1,0},{0,-1},
                        {1,1},{1,-1},{-1,1},{-1,-1}};
    int i, j, k, x, y, idx;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < 7; k++) {
                x = i, y = j, idx = 0;
                if(map[x][y] == str[idx]) {
                	idx++;
            	       if(str[idx] == '\0') {

	                        printf("%d,%d %d,%d\n", i+1, j+1,x+1,y+1);
	                        return;
	                    }
                   while(true)
                   {
	                    x += D[k][0], y += D[k][1];
	                    if(map[x][y] == str[idx])
	                    idx++;
	                    if(str[idx] == '\0') {

	                        printf("%d,%d %d,%d\n", i+1, j+1,x+1,y+1);
	                        return;
	                    }
	                    if(x < 0 || y < 0 || x >= n || y >= n)
	                    {
	                        break;
	                    }
                  }
                }
            }
        }
    }
    printf("Not found\n");
}
int main() {
        scanf("%d", &n);
        char map[60][60], str[60];
        for(i = 0; i < n; i++) {
            scanf("%s", &map[i]);
        }
        scanf("%s", str);
        while(strcmp(str,"0")) {
            find(str, map);
            scanf("%s", str);
        }

    return 0;
}
*/
