#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void kiemTraSoNguyen()
{
	printf("Kiem Tra So Nguyen");
	printf("\n");
}
void tinhTrungBinhTongCacSoChiaHetCho3()
{


	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);


	int mang[100];
	int i;
	for (i = 0; i < n; i++) {
		printf("Nhap phan tu thu %d: ", i);
		scanf("%d", &mang[i]);
	}


	float tong = 0;
	int count = 0;


	for (i = 0; i < n; i++) {

		if (mang[i] % 3 == 0) {
			tong = tong + mang[i];
			count++;
		}
	}


	if (count > 0) {
		float tb = tong / count;
		printf("Trung binh tong cac so chia het cho 3 la: %.2f\n", tb);
	}
	else {
		printf("Trong mang khong co so nao chia het cho 3.\n");
	}

	return 0;

}
void sapXepPhanTuMang()
{
	int integerArray[100];
	int tmp;
	int length;
	printf("Nhap kich thuoc mang: ");
	scanf("%d", &length);
	printf("Nhap du lieu cho mang %d phan tu\n", length);
	for (int i = 0; i < length; i++)
	{
		printf("mang[%d] =", i);
		scanf("%d", &integerArray[i]);
	}
	printf("Xuat du lieu mang %d phan tu\n", length);
	for (int i = 0; i < length; i++)
	{
		if (integerArray[i] > integerArray[i + 1])
		{
			tmp = integerArray[i];
			integerArray[i] = integerArray[i + 1];
			integerArray[i + 1] = tmp;
		}
	}
	printf("Xuat du lieu mang %d phan tu\n", length);
	for (int i = 0; i < length; i++)
	{
		printf("mang[%d] = %d\n", i, integerArray[i]);
	}
}
void mangHaiChieu()
{
	//string - string.h
	char mangKyTu[10] = { 'A', 'N', 'H' };
	//scanf

	// printf("%C
	//gets(mangKyTu);
	for (int i = 0; i < 3; i++)
	{
		scanf("%c", &mangKyTu[i]);
	}
	//scanf("%C\n'
	for (int i = 0; i < 10; i++)
	{
		scanf(" %c", &mangKyTu);
	}
	int array[2][3];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("mang[%d][%d] = ", i, j);
			scanf("%d", &array[i][j]);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d, ", array[i][j]);
		}
		printf("\n");
	}
}
void demoString()
{
	//string
	char mangKyTu[10] = "ANH";
	//scanf("%c"
	//gets(mangKyTu);
	while (getchar() != '\n');
	printf("Nhap du lieu String: ");
	fgets(mangKyTu, sizeof(mangKyTu), stdin);
	//loop + printf("%c\n"
	printf("%s", mangKyTu);
	printf("\n");
	// put(mangKyTu);
	printf("%d", strlen(mangKyTu) - 1);
	printf("\n");

	printf("%d", strcmp("A", "B"));
	printf("\n");
	char str[5] = "ABC";
	printf("%s", strrev(str));
	printf("\n");

	printf("%s", strlwr(str));
	printf("\n");

	printf("%s", strupr(str));
	printf("\n");

	printf(strstr("ABC", "D"));
	printf("\n");

}




void lapChucNang(int chonChucNang)
{
	int tiepTuc = 1;
	while (tiepTuc == 1)
	{
		switch (chonChucNang)
		{
		case 1:
			kiemTraSoNguyen();
			break;
		case 2:
			tinhTrungBinhTongCacSoChiaHetCho3();
			break;
		case 3:
			sapXepPhanTuMang();
			break;
		case 4:
			mangHaiChieu();
			break;
		case 5:
			demoString();
			break;
		default:
			printf("Chon sai. Chuc nang hop le [0-3]");
			break;
		}

		printf("Tiep tuc thuc hien chuc nang nay? [1=Co | 0=Khong]: ");
		scanf("%d", &tiepTuc);
		system("cls");
	}

}

int main()
{
	int chonChucNang;
	do
	{
		printf("Menu");
		printf("\n");
		printf("1. Kiem Tra So Nguyen");
		printf("\n");
		printf("2. TEN chuc nang 2");
		printf("\n");
		printf("3. TEN chuc nang 3");
		printf("\n");
		printf("4. mangHaiChieu");
		printf("\n");
		printf("5. demoString");
		printf("\n");
		printf("0. Thoat");
		printf("\n");
		printf("Hay chon chuc nang [0-3]: ");
		scanf("%d", &chonChucNang);
		lapChucNang(chonChucNang);
	} while (chonChucNang != 0);
}
