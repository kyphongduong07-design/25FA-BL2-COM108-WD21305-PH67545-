#include <stdio.h>
#include <string.h>

// CN1
void thongTinThuCung() 
{
    char maThuCung[50];
    char tenThuCung[50];
    int namSinh;

    printf("\n--- NHAP THONG TIN THU CUNG ---\n");
    printf("Nhap ma thu cung: ");
    scanf("%s", maThuCung);

    printf("Nhap ten thu cung: ");
    scanf("%s", tenThuCung);

    printf("Nhap nam sinh: ");
    scanf("%d", &namSinh);

    printf("\n--- KET QUA ---\n");
    printf("Thong tin vua nhap:\n -Ma: %s \n -Ten: %s \n -Nam sinh: %d\n", maThuCung, tenThuCung, namSinh);

    // Tinh tuoi
    int tuoi = 2025 - namSinh;
    printf("Tuoi cua thu cung: %d\n", tuoi);
}

// CN 2
void tinhTong() 
{
    int n, tong = 0;

    printf("\n--- TINH TONG ---\n");
    // Yeu cau nhap n > 3
    do {
        printf("Nhap so nguyen duong n (n > 3): ");
        scanf("%d", &n);
        if (n <= 3) 
        {
            printf("Vui long nhap n lon hon 3!\n");
        }
    } while (n <= 3);

    // Tinh tong cac so le tu 1 den n
    for (int i = 1; i <= n; i++) 
    {
        if (i % 2 != 0) 
        {
            tong += i;
        }
    }
    printf("Tong cac so le tu 1 den %d la: %d\n", n, tong);

    // Kiem tra chia het cho 5
    if (n % 5 == 0) 
    {
        printf("So %d chia het cho 5.\n", n);
    }
    else {
        printf("So %d KHONG chia het cho 5.\n", n);
    }
}

// CN 3
void thongTinCuaHang() {
    int soLuong, demDuoiTB = 0;
    float canNang[100];
    float tongCanNang = 0, trungBinh, thapNhat;

    printf("\n--- THONG TIN CUA HANG ---\n");
    printf("Nhap so luong thu cung: ");
    scanf("%d", &soLuong);

    // Nhap mang
    for (int i = 0; i < soLuong; i++) 
    {
        printf("Nhap can nang thu cung thu %d: ", i + 1);
        scanf("%f", &canNang[i]);
        tongCanNang += canNang[i];
    }

    // Tinh trung binh
    trungBinh = tongCanNang / soLuong;

    // Tim can nang thap nhat
    thapNhat = canNang[0];
    for (int i = 1; i < soLuong; i++) 
    {
        if (canNang[i] < thapNhat) 
        {
            thapNhat = canNang[i];
        }
    }

    // Dem so thu cung duoi muc trung binh
    for (int i = 0; i < soLuong; i++) 
    {
        if (canNang[i] < trungBinh) 
        {
            demDuoiTB++;
        }
    }

    // In ket qua
    printf("\n--- KET QUA ---\n");
    printf("Can nang trung binh: %.2f\n", trungBinh);
    printf("Can nang thap nhat: %.2f\n", thapNhat);
    printf("So thu cung nang duoi muc trung binh: %d\n", demDuoiTB);
}

void lapChucNang(int chonChucNang)
{
    int tiepTuc = 1;
    tiepTuc == 1;
    while (tiepTuc == 1)
    {
        switch (chonChucNang)
        {
        case 1:
            system("cls");
            thongTinThuCung();
            break;
        case 2:
            system("cls");
            tinhTong();
            break;
        case 3:
            system("cls");
            thongTinCuaHang();
            break;
        default:
            printf("Chon sai. Vui long chon chuc nang hop le [0-3]");
            break;
        }

        printf("Tiep tuc thuc hien chuc nang nay? [1 = Co | 0 = Khong]: ");
        scanf("%d", &tiepTuc);
        system("cls");
    }

}

int main()
{
    int chonChucNang;
    do
    {
        printf("============MENU============\n");
        printf("   1. Thong tin thu cung\n");
        printf("   2. Tinh tong\n");
        printf("   3. Thong tin cua hang\n");
        printf("   0. Thoat\n");
        printf("============================\n");
        printf("Hay chon chuc nang [0-3]: ");
        scanf("%d", &chonChucNang);
        if (chonChucNang != 0)
        {
            lapChucNang(chonChucNang);
        }
    } while (chonChucNang != 0);
    printf("Da thoat chuong trinh.\n");
    return 0;
}