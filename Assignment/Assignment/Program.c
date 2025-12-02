#include <stdio.h>
#include <math.h>

void kiemTraSoNguyen()
{
    int chon;
    do
    {
        printf("Thuc hien kiem tra so nguyen\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        scanf("%d", &chon);

        printf("\n");
    } while (chon == 1);
}

void timUocSoVaBoiSoChung2So()
{
    int chon;
    do
    {
        printf("Thuc hien tim uoc so va boi so chung\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        scanf("%d", &chon);

        printf("\n");
    } while (chon == 1);
}

void chuongTrinhTinhTienKaraoke()
{
    int chon;
    do
    {
        printf("Thuc hien kiem tra so nguyen\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        scanf("%d", &chon);

        printf("\n");
    } while (chon == 1);
}

void tinhTienDien()
{
    int chon;
    do
    {
        printf("Thuc hien tinh tien dien\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        scanf("%d", &chon);

        printf("\n");
    } while (chon == 1);
}

void doiTien()
{
    int chon;
    do
    {
        printf("Thuc hien doi tien\n");

        printf("Tiep tuc thuc hien CN nay? [5 = Co | Khac = Khong]: ");
        scanf("%d", &chon);

        printf("\n");
    } while (chon == 1);
}

void tinhLaiSuatVayNganHangVayTraGop()
{
    int chon;
    do
    {
        printf("Thuc hien tinh lai suat vay ngan hang vay tra gop\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        scanf("%d", &chon);

        printf("\n");
    } while (chon == 1);
}

void chuongTrinhVayTienMuaXe()
{
    int chon;
    do
    {
        printf("Thuc hien chuong trinh vay tien mua xe\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        scanf("%d", &chon);

        printf("\n");
    } while (chon == 1);
}

void sapXepThongTinSinhVien()
{
    int chon;
    do
    {
        printf("Thuc hien sap xep thong tin sinh vien\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        scanf("%d", &chon);

        printf("\n");
    } while (chon == 1);
}

void xayDungGameFPOLY()
{
    int chon;
    do
    {
        printf("Thuc hien xay dung game FPOLY\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        scanf("%d", &chon);

        printf("\n");
    } while (chon == 1);
}

void tinhToanPhanSo()
{
    int chon;
    do
    {
        printf("Thuc hien tinh toan\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        scanf("%d", &chon);

        printf("\n");
    } while (chon == 1);
}

int main()
{
    int chon;
    do
    {
        system("cls");
        printf("Menu\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim uoc so chung va boi so chung cua 2 so\n");
        printf("3. Chuong trinh tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Chuong trinh vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Xay dung game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang tren Menu: ");

        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            kiemTraSoNguyen();
            break;
        case 2:
            timUocSoVaBoiSoChung2So();
            break;
        case 3:
            chuongTrinhTinhTienKaraoke();
            break;
        case 4:
            tinhTienDien();
            break;
        case 5:
            doiTien();
            break;
        case 6:
            tinhLaiSuatVayNganHangVayTraGop();
            break;
        case 7:
            chuongTrinhVayTienMuaXe();
            break;
        case 8:
            sapXepThongTinSinhVien();
            break;
        case 9:
            xayDungGameFPOLY();
        case 10:
            tinhToanPhanSo();
            break;
        case 0:
            printf("Thoat\n");
            break;
        default:
            printf("Hay chon CN tren Menu [1-10]");
            break;
        }
    } while (chon != 0);
}