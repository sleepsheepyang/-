#include<stdio.h>
#include<math.h>
int map[9][9];
#define INF 0x3f3f3f3f
int main(){
	int ax = 2,ay = 4;
	int bx = 5,by = 3;
	int cx = 6,cy = 6;
	int curdes = 0;
	int mindes = INF,minx = -1,miny = -1;
	
	for(int i = 0;i<=8;i++){
		for(int j = 0;j<=8;j++){
			curdes = abs(ax - i) + abs(ay - j) + abs(bx - i) + abs(by - j) + abs(cx - i) + abs(cy - j);
			if(curdes<mindes){
				mindes = curdes;
				minx = i;
				miny = j;
			}
		}
	}
	printf("仓库位置为（%d,%d），商店到仓库的路程和为：%d",minx,miny,mindes);
	return 0;
} 
