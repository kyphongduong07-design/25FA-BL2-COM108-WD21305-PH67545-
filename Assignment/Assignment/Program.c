#include <stdio.h>
#include <math.h>
#include <stdlib.h> // Can thiet cho system("cls")
#include <stdbool.h> // Can thiet cho kieu du lieu bool

// ===========================================
//             CAC HAM XU LY CHINH
// ===========================================

// ---------------------------
// 1. CHUC NANG KIEM TRA SO NGUYEN
// ---------------------------

// Ham kiem tra so nguyen to
bool isPrime(int n)
{
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Ham kiem tra so chinh phuong
bool isPerfectSquare(int n)
{
    if (n < 0) {
        return false;
    }
    long long root = round(sqrt(n));
    return root * root == n;
}

void kiemTraSoNguyen()
{
    int chon;
    do
    {
        printf("--- THUC HIEN KIEM TRA SO NGUYEN ---\n");
        double x_double;
        int x;

        printf("Nhap mot so x: ");
        if (scanf("%lf", &x_double) != 1)
        {
            printf("Loi nhap lieu. Vui long chi nhap so.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("--------------------------------------\n");

        if (x_double == (int)x_double)
        {
            x = (int)x_double;
            printf("Ket qua: %.0lf LA so nguyen.\n", x_double);

            if (isPrime(x))
            {
                printf("So %d LA so nguyen to.\n", x);
            }
            else
            {
                printf("So %d KHONG phai la so nguyen to.\n", x);
            }

            if (isPerfectSquare(x))
            {
                printf("So %d LA so chinh phuong.\n", x);
            }
            else
            {
                printf("So %d KHONG phai la so chinh phuong.\n", x);
            }

        }
        else
        {
            printf("Ket qua: %.2lf KHONG phai la so nguyen.\n", x_double);
            printf("  -> KHONG the kiem tra so nguyen to/so chinh phuong.\n");
        }
        printf("--------------------------------------\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        if (scanf("%d", &chon) != 1)
        {
            while (getchar() != '\n');
            chon = 0;
        }

        printf("\n");
    } while (chon == 1);
}

// ----------------------------------------------------
// 2. CHUC NANG TIM USCLN VA BSCNN CUA 2 SO
// ----------------------------------------------------

// Ham tim Uoc So Chung Lon Nhat (USCLN) su dung thuat toan Euclid
int USCLN(int a, int b)
{
    // Chuyen ve gia tri tuyet doi de xu ly ca so am (neu co)
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Ham tim Boi So Chung Nho Nhat (BSCNN)
// BSCNN(a, b) = (|a * b|) / USCLN(a, b)
long long BSCNN(int a, int b) {
    if (a == 0 || b == 0) return 0;
    long long result = (long long)abs(a) * abs(b) / USCLN(a, b);
    return result;
}

void timUocSoVaBoiSoChung2So()
{
    int chon;
    do
    {
        printf("--- THUC HIEN TIM USCLN VA BSCNN ---\n");
        int x, y;

        printf("Nhap so nguyen x: ");
        if (scanf("%d", &x) != 1) {
            printf("Loi nhap lieu.\n");
            while (getchar() != '\n'); continue;
        }
        printf("Nhap so nguyen y: ");
        if (scanf("%d", &y) != 1) {
            printf("Loi nhap lieu.\n");
            while (getchar() != '\n'); continue;
        }

        printf("--------------------------------------\n");

        // Kiem tra truong hop dac biet
        if (x == 0 && y == 0) {
            printf("Ca hai so deu bang 0. USCLN va BSCNN khong xac dinh.\n");
        }
        else {
            int uscln = USCLN(x, y);
            long long bscnn = BSCNN(x, y);

            printf("1. USCLN cua %d va %d la: %d\n", x, y, uscln);
            printf("2. BSCNN cua %d va %d la: %lld\n", x, y, bscnn);
        }

        printf("--------------------------------------\n");
        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

// ----------------------------------------------------
// 3. CHUC NANG TINH TIEN KARAOKE
// ----------------------------------------------------

void chuongTrinhTinhTienKaraoke()
{
    int chon;
    do
    {
        printf("--- THUC HIEN TINH TIEN KARAOKE ---\n");
        int gioBatDau, gioKetThuc;
        const int GIA_3H_DAU = 150000;
        const float GIAM_SAU_3H = 0.30; // 30%
        const float GIAM_KHUNG_GIO = 0.10; // 10%
        float tongTien = 0;
        int soGioThue;

        printf("Nhap gio bat dau (tu 12 den 23): ");
        if (scanf("%d", &gioBatDau) != 1 || gioBatDau < 12 || gioBatDau > 23) {
            printf("Gio bat dau khong hop le (trong khoang 12-23).\n");
            while (getchar() != '\n'); continue;
        }

        printf("Nhap gio ket thuc (sau gio bat dau, toi da 23): ");
        if (scanf("%d", &gioKetThuc) != 1 || gioKetThuc > 23 || gioKetThuc <= gioBatDau) {
            printf("Gio ket thuc khong hop le.\n");
            while (getchar() != '\n'); continue;
        }

        printf("--------------------------------------\n");

        // Kiem tra gio hoat dong
        if (gioBatDau < 12 || gioKetThuc > 23) {
            printf("Loi: Quan chi hoat dong tu 12h den 23h.\n");
        }
        else {
            soGioThue = gioKetThuc - gioBatDau;
            printf("Tong so gio thue: %d gio\n", soGioThue);

            if (soGioThue <= 3) {
                // Truong hop 3 gio dau
                tongTien = GIA_3H_DAU;
            }
            else {
                // Truong hop hon 3 gio
                int soGioSau = soGioThue - 3;
                float giaMoiGio = GIA_3H_DAU / 3.0; // Gia moi gio ban dau

                // Gia 3 gio dau
                tongTien = GIA_3H_DAU;

                // Gia cac gio sau: giam 30%
                float giaSau3H = giaMoiGio * (1.0 - GIAM_SAU_3H);
                tongTien += soGioSau * giaSau3H;
            }

            printf("Tong tien truoc khi giam khung gio: %.0f VND\n", tongTien);

            // Kiem tra khung gio giam gia (14h den 17h)
            if (gioBatDau >= 14 && gioBatDau <= 17) {
                float tienGiam = tongTien * GIAM_KHUNG_GIO;
                tongTien -= tienGiam;
                printf("Ap dung giam gia 10%% (gio bat dau 14h-17h): -%.0f VND\n", tienGiam);
            }
            else {
                printf("Khong ap dung giam gia 10%% (gio bat dau 14h-17h).\n");
            }

            printf("======================================\n");
            printf("TONG TIEN CAN THANH TOAN: %.0f VND\n", tongTien);
            printf("======================================\n");
        }

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

// ----------------------------------------------------
// 4. CHUC NANG TINH TIEN DIEN
// ----------------------------------------------------

void tinhTienDien()
{
    int chon;
    do
    {
        printf("--- THUC HIEN TINH TIEN DIEN ---\n");
        int kwh;
        long long tongTienDien = 0;

        // Bang gia (dong/kWh)
        const int GIA_BAC[] = { 1678, 1734, 2014, 2536, 2834, 2927 };
        // So kWh toi da cua moi bac (tru bac 6)
        const int MUC_BAC[] = { 50, 50, 100, 100, 100, 0 };

        printf("Nhap so kWh dien da su dung: ");
        if (scanf("%d", &kwh) != 1 || kwh < 0) {
            printf("So kWh nhap khong hop le.\n");
            while (getchar() != '\n'); continue;
        }

        printf("--------------------------------------\n");

        int kwhConLai = kwh;

        for (int i = 0; i < 6 && kwhConLai > 0; i++) {
            int kwhBac = MUC_BAC[i];
            int soKwhTinhTien;

            if (i == 5) { // Bac 6 (tu 401 tro len)
                soKwhTinhTien = kwhConLai;
            }
            else {
                // Tinh so kWh trong bac hien tai
                soKwhTinhTien = (kwhConLai > kwhBac) ? kwhBac : kwhConLai;
            }

            if (soKwhTinhTien > 0) {
                long long tienBac = (long long)soKwhTinhTien * GIA_BAC[i];
                tongTienDien += tienBac;
                kwhConLai -= soKwhTinhTien;

                printf("Bac %d (%d kWh): %d x %d = %lld VND\n", i + 1, soKwhTinhTien, soKwhTinhTien, GIA_BAC[i], tienBac);
            }
        }

        printf("======================================\n");
        printf("TONG TIEN DIEN PHAI TRA: %lld VND\n", tongTienDien);
        printf("======================================\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

// ----------------------------------------------------
// 5. CHUC NANG DOI TIEN
// ----------------------------------------------------

void doiTien()
{
    int chon;
    do
    {
        printf("--- THUC HIEN CHUC NANG DOI TIEN ---\n");
        int soTienCanDoi;
        // Cac menh gia tien (Don vi: nghin dong)
        const int MENH_GIA[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
        const int SO_MENH_GIA = sizeof(MENH_GIA) / sizeof(MENH_GIA[0]);

        printf("Nhap so tien can doi (don vi nghin dong, vi du: 500): ");
        if (scanf("%d", &soTienCanDoi) != 1 || soTienCanDoi <= 0) {
            printf("So tien nhap khong hop le.\n");
            while (getchar() != '\n'); continue;
        }

        printf("--------------------------------------\n");
        printf("Doi %d nghin dong thanh:\n", soTienCanDoi);

        int tienConLai = soTienCanDoi;

        for (int i = 0; i < SO_MENH_GIA; i++) {
            int menhGia = MENH_GIA[i];
            int soTo = tienConLai / menhGia; // Tinh so to cua menh gia hien tai

            if (soTo > 0) {
                printf(" - %d to %d nghin\n", soTo, menhGia);
                tienConLai %= menhGia; // Cap nhat so tien con lai
            }
        }

        printf("--------------------------------------\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

// ----------------------------------------------------
// 6. CHUC NANG TINH LAI SUAT VAY NGAN HANG
// ----------------------------------------------------

void tinhLaiSuatVayNganHangVayTraGop()
{
    int chon;
    do
    {
        printf("--- THUC HIEN TINH LAI SUAT VAY TRA GOP ---\n");
        long long soTienVay;
        const float LAI_SUAT_THANG = 0.05; // 5% / thang
        const int KY_HAN_THANG = 12;

        printf("Nhap so tien muon vay (VND, vi du: 12000000): ");
        if (scanf("%lld", &soTienVay) != 1 || soTienVay <= 0) {
            printf("So tien vay khong hop le.\n");
            while (getchar() != '\n'); continue;
        }

        printf("--------------------------------------\n");
        printf("Thong tin vay:\n");
        printf(" - Tien vay: %lld VND\n", soTienVay);
        printf(" - Lai suat co dinh: %.0f%% / thang\n", LAI_SUAT_THANG * 100);
        printf(" - Ky han: %d thang\n", KY_HAN_THANG);
        printf("--------------------------------------\n");

        // Tinh goc hang thang phai tra
        long long gocHangThang = soTienVay / KY_HAN_THANG;

        long long tongTienTra = 0;
        long long duNoConLai = soTienVay;

        printf("Chi tiet thanh toan trong 12 thang:\n");

        for (int thang = 1; thang <= KY_HAN_THANG; thang++) {
            // Lãi được tính dựa trên số dư nợ còn lại của tháng trước
            long long tienLai = (long long)(duNoConLai * LAI_SUAT_THANG);

            // Số tiền phải trả hàng tháng (gốc + lãi)
            long long tienTraThangNay = gocHangThang + tienLai;

            // Cập nhật dư nợ còn lại
            duNoConLai -= gocHangThang;
            tongTienTra += tienTraThangNay;

            printf("Thang %-2d | Goc: %-10lld | Lai (5%%): %-10lld | Tong tra: %-10lld | Du no con lai: %lld\n",
                thang, gocHangThang, tienLai, tienTraThangNay, duNoConLai);
        }

        printf("======================================\n");
        printf("TONG TIEN VAY PHAI TRA SAU %d THANG: %lld VND\n", KY_HAN_THANG, tongTienTra);
        printf("======================================\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

// ----------------------------------------------------
// 7-10. CAC CHUC NANG KHAC (GIU NGUYEN KHUNG)
// ----------------------------------------------------

void chuongTrinhVayTienMuaXe()
{
    int chon;
    do
    {
        printf("Thuc hien chuong trinh vay tien mua xe (Chua trien khai)\n");
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
        printf("Thuc hien sap xep thong tin sinh vien (Chua trien khai)\n");
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
        printf("Thuc hien xay dung game FPOLY-LOTT (Chua trien khai)\n");
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
        printf("Thuc hien tinh toan phan so (Chua trien khai)\n");
        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        scanf("%d", &chon);
        printf("\n");
    } while (chon == 1);
}

// ===========================================
//             HAM MAIN (MENU)
// ===========================================

int main()
{
    int chon;
    do
    {
        system("cls"); // Xoa man hinh
        printf("============ MENU CHUONG TRINH =============\n");
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
        printf("============================================\n");
        printf("Chon chuc nang tren Menu: ");

        scanf("%d", &chon);
        // Xoa buffer cho lan scanf tiep theo
        if (chon != 0) while (getchar() != '\n');

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
            break;
        case 10:
            tinhToanPhanSo();
            break;
        case 0:
            printf("Thoat chuong trinh. Cam on!\n");
            break;
        default:
            printf("Hay chon CN tren Menu [1-10]\n");
            // Tam dung de nguoi dung doc thong bao loi
            printf("Nhan phim bat ky de quay ve Menu chinh...");
            getchar();
            break;
        }

    } while (chon != 0);
    return 0;
}