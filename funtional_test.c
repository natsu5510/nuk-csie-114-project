#include <stdio.h>
#include <string.h>
#include <math.h>
// #pragma warning(disable:4996)

int main() {
	FILE* ans, * mine;			//檔案讀取, ans是required.txt, mine是derived.txt
	fpos_t position;			//用來紀錄mine(derived.txt)的檔案指標初始位置
	char STRans[100], STRmine[100];			//用來儲存從txt中擷取出來的單行數據
	char temp;			//用來儲存從txt中擷取出來的單一文字
	int N = 0;			//測資總筆數
	int mineN = 0;			//user得到的測資筆數
	int Correct = 0, Incorrect = 0;			//測資相同數與不相同數

	ans = fopen("required.txt", "r");			//開啟required.txt
	if (ans == NULL) {
		printf("failed to open the file1.\n");
		return 1;
	}else {
		fgetpos(ans, &position);			//紀錄ans(required.txt)的檔案指標初始位置
		while ((temp = fgetc(ans)) != EOF) {			//搜索整個檔案
			if (temp == '\n') N++;			//若遇到換行符號，行數加1
		}
		fsetpos(ans, &position);			//將檔案指標移回初始位置

		mine = fopen("derived.txt", "r");			//開啟derived.txt
		if (mine == NULL) {
			printf("failed to open the file2.\n");
			return 1;
		}else {
			fgetpos(mine, &position);			//紀錄mine(derived.txt)的檔案指標初始位置
			while ((temp = fgetc(mine)) != EOF) {			//搜索整個檔案
				if (temp == '\n') mineN++;			//若遇到換行符號，行數加1
			}
			fsetpos(mine, &position);			//將檔案指標移回初始位置

			for (int i = 0; i < N; i++) {			//跑 N 次
				fscanf(ans, "%[^\n]", STRans);			//讀取字串至換行符號
				fseek(ans, 2, SEEK_CUR);			//將檔案內指標切換到下一行
				fscanf(mine, "%[^\n]", STRmine);			//讀取字串至換行符號
				fseek(mine, 2, SEEK_CUR);			//將檔案內指標切換到下一行
				if (strcmp(STRans, STRmine) != 0) Incorrect++;			//若不相同
				else Correct++;			//若相同
			}
			double Completeness = (double)Correct / N;
			double Correctness = (double)Correct / mineN;
			double Appropriateness = (double)Correct / N;
			//printf("Correct：%d, Incorrect：%d\n", Correct, Incorrect);
			//printf("Function Completeness：%f\n", Completeness);
			//printf("Function Correctness：%f\n", Correctness);

			//printf("Function Appropriateness：%f\n", Appropriateness);

			//printf("mineN：%d, N：%d\n", mineN, N);
			if (mineN == 1 && N > 1) {
				if (Correct == 1) {
					printf("%.1f", 1.0);
				}
				else {
					printf("%.1f", 0.0);
				}
			}
			else {
				double a = Completeness * 15;
				double b = Correctness * 15;
				double c = Appropriateness * 15;
				double d = (int)(((a + b + c) / 3) * 10 + 0.5) / 10.0;	//四捨五入至小數點第一位
				printf("%.1f", d);
			}
		}
	}
	return 0;
}