#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h>
#include <time.h>

// CN 1
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

        printf("Nhap mot so nguyen: ");
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
            printf("Ket qua: %.0lf la so nguyen.\n", x_double);

            if (isPrime(x))
            {
                printf("So %d la so nguyen to.\n", x);
            }
            else
            {
                printf("So %d khong phai la so nguyen to.\n", x);
            }

            if (isPerfectSquare(x))
            {
                printf("So %d la so chinh phuong.\n", x);
            }
            else
            {
                printf("So %d khong phai la so chinh phuong.\n", x);
            }

        }
        else
        {
            printf("Ket qua: %.2lf khong phai la so nguyen.\n", x_double);
            printf("  -> Khong the kiem tra so nguyen to/so chinh phuong.\n");
        }
        printf("--------------------------------------\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | 0 = Khong]: ");
        if (scanf("%d", &chon) != 1)
        {
            while (getchar() != '\n');
            chon = 0;
        }

        printf("\n");
    } while (chon == 1);
}

// CN 2
// Ham tim Uoc So Chung Lon Nhat (USCLN)
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
        printf("Tiep tuc thuc hien CN nay? [1 = Co | 0 = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

//CN 3
void chuongTrinhTinhTienKaraoke()
{
    int chon;
    do
    {
        printf("--- THUC HIEN TINH TIEN KARAOKE ---\n");
        int gioBatDau, gioKetThuc;
        const int GIA_3H_DAU = 150000;
        const float GIAM_SAU_3H = 0.30; 
        const float GIAM_KHUNG_GIO = 0.10; 
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

                // Gia cac gio sau
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

        printf("Tiep tuc thuc hien CN nay? [1 = Co | 0 = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

// CN 4
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

        printf("Tiep tuc thuc hien CN nay? [1 = Co | 0 = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

// CN 5
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

        printf("Tiep tuc thuc hien CN nay? [1 = Co | 0 = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

//CN 6
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
            // Lai duoc tinh dua tren so du no con lai cua thang truoc
            long long tienLai = (long long)(duNoConLai * LAI_SUAT_THANG);

            // So tien phai tra hang thang (goc + lai)
            long long tienTraThangNay = gocHangThang + tienLai;

            // Cap nhat du no con lai
            duNoConLai -= gocHangThang;
            tongTienTra += tienTraThangNay;

            printf("Thang %-2d | Goc: %-10lld | Lai (5%%): %-10lld | Tong tra: %-10lld | Du no con lai: %lld\n",
                thang, gocHangThang, tienLai, tienTraThangNay, duNoConLai);
        }

        printf("======================================\n");
        printf("TONG TIEN VAY PHAI TRA SAU %d THANG: %lld VND\n", KY_HAN_THANG, tongTienTra);
        printf("======================================\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | 0 = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

// CN 7 
void chuongTrinhVayTienMuaXe()
{
    int chon;
    do
    {
        printf("--- THUC HIEN CHUONG TRINH VAY TIEN MUA XE ---\n");
        int phanTramVay;
        const long long TONG_TIEN_VAY_CO_DINH = 500000000; // 500 trieu
        const int THOI_HAN_NAM = 24;
        const float LAI_SUAT_NAM = 0.072; // 7.2% / nam
        const int KY_HAN_THANG = THOI_HAN_NAM * 12; // 24 nam * 12 thang = 288 thang

        printf("Nhap phan tram vay toi da (vi du: 80): ");
        if (scanf("%d", &phanTramVay) != 1 || phanTramVay < 0 || phanTramVay > 100) {
            printf("Phan tram vay khong hop le.\n");
            while (getchar() != '\n'); continue;
        }

        printf("--------------------------------------\n");

        float phanTramTraTruoc = (100.0 - phanTramVay) / 100.0;
        long long tienTraTruoc = (long long)(TONG_TIEN_VAY_CO_DINH * phanTramTraTruoc);

        long long soTienVay = TONG_TIEN_VAY_CO_DINH - tienTraTruoc;

        float laiSuatThang = LAI_SUAT_NAM / 12.0;

        // Tinh toan goc va lai theo phuong phap du no giam dan 
        // Goc hang thang co dinh
        long long gocHangThang = soTienVay / KY_HAN_THANG;

        // So tien phai tra lan dau (Tra truoc)
        printf("1. SO TIEN PHAI TRA LAN DAU (TRA TRUOC %.0f%%): %lld VND\n", phanTramTraTruoc * 100, tienTraTruoc);
        printf("   (So tien vay: %lld VND)\n", soTienVay);
        printf("--------------------------------------\n");

        printf("2. SO TIEN PHAI TRA HANG THANG (%d THANG):\n", KY_HAN_THANG);

        long long duNoConLai = soTienVay;
        long long tongTienPhaiTra = 0;

        for (int thang = 1; thang <= KY_HAN_THANG; thang++) {
            long long tienLai = (long long)(duNoConLai * laiSuatThang);
            long long tienTraThangNay = gocHangThang + tienLai;

            // Chi hien thi chi tiet cho thang dau va thang cuoi
            if (thang == 1 || thang == KY_HAN_THANG) {
                printf("Thang %-3d | Goc: %-10lld | Lai (%.2f%%): %-10lld | Tong tra: %lld\n",
                    thang, gocHangThang, laiSuatThang * 100, tienLai, tienTraThangNay);
            }
            else if (thang == 2) {
                printf("...\n");
            }

            tongTienPhaiTra += tienTraThangNay;
            duNoConLai -= gocHangThang;
        }

        printf("======================================\n");
        printf("TONG TIEN GOC VA LAI PHAI TRA TRONG %d NAM: %lld VND\n", THOI_HAN_NAM, tongTienPhaiTra);
        printf("======================================\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | Khac = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

// CN 8
#define MAX_SV 100
// Dinh nghia struct cho Sinh Vien
struct SinhVien {
    char hoTen[50];
    float diem;
    char hocLuc[20];
};

// Ham xac dinh hoc luc
void xepHocLuc(struct SinhVien* sv) {
    if (sv->diem >= 9.0) {
        strcpy(sv->hocLuc, "Xuat sac");
    }
    else if (sv->diem >= 8.0) {
        strcpy(sv->hocLuc, "Gioi");
    }
    else if (sv->diem >= 6.5) {
        strcpy(sv->hocLuc, "Kha");
    }
    else if (sv->diem >= 5.0) {
        strcpy(sv->hocLuc, "Trung binh");
    }
    else {
        strcpy(sv->hocLuc, "Yeu");
    }
}

// Ham hoan doi 2 sinh vien
void swapSV(struct SinhVien* a, struct SinhVien* b) {
    struct SinhVien temp = *a;
    *a = *b;
    *b = temp;
}

// Ham sap xep noi bot (Bubble Sort) theo diem giam dan
void sapXepDiemGiamDan(struct SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Sap xep giam dan
            if (sv[j].diem < sv[j + 1].diem) {
                swapSV(&sv[j], &sv[j + 1]);
            }
        }
    }
}

void sapXepThongTinSinhVien()
{
    int chon;
    do
    {
        printf("--- THUC HIEN SAP XEP THONG TIN SINH VIEN ---\n");
        int n;
        struct SinhVien danhSachSV[MAX_SV];

        printf("Nhap so luong sinh vien (toi da %d): ", MAX_SV);
        if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SV) {
            printf("So luong sinh vien khong hop le.\n");
            while (getchar() != '\n'); continue;
        }

        while (getchar() != '\n'); // Xoa buffer sau khi nhap so

        // Nhap thong tin sinh vien
        for (int i = 0; i < n; i++) {
            printf("\n--- Nhap thong tin Sinh vien thu %d ---\n", i + 1);
            printf("Ho ten: ");
            fgets(danhSachSV[i].hoTen, 50, stdin);
            danhSachSV[i].hoTen[strcspn(danhSachSV[i].hoTen, "\n")] = 0; // Xoa ky tu '\n'

            printf("Diem: ");
            if (scanf("%f", &danhSachSV[i].diem) != 1 || danhSachSV[i].diem < 0 || danhSachSV[i].diem > 10) {
                printf("Diem khong hop le. Thoat nhap.\n");
                while (getchar() != '\n'); n = i; break; // Giam so luong SV hop le
            }
            while (getchar() != '\n'); // Xoa buffer

            xepHocLuc(&danhSachSV[i]);
        }

        if (n > 0) {
            // Sap xep
            sapXepDiemGiamDan(danhSachSV, n);

            // Hien thi ket qua
            printf("\n======================================================\n");
            printf("           DANH SACH SINH VIEN (SAP XEP GIAM DAN)\n");
            printf("======================================================\n");
            printf("| %-20s | %-5s | %-12s |\n", "HO TEN", "DIEM", "HOC LUC");
            printf("------------------------------------------------------\n");
            for (int i = 0; i < n; i++) {
                printf("| %-20s | %-5.1f | %-12s |\n",
                    danhSachSV[i].hoTen, danhSachSV[i].diem, danhSachSV[i].hocLuc);
            }
            printf("======================================================\n");
        }


        printf("Tiep tuc thuc hien CN nay? [1 = Co | 0 = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

// CN 9
void xayDungGameFPOLY()
{
    int chon;
    do
    {
        printf("--- THUC HIEN XAY DUNG GAME FPOLY-LOTT ---\n");
        srand(time(NULL)); // Khoi tao bo sinh so ngau nhien

        int soTrung1 = (rand() % 15) + 1; // Sinh so ngau nhien tu 1 den 15
        int soTrung2 = (rand() % 15) + 1;

        // Dam bao 2 so ngau nhien khac nhau
        while (soTrung2 == soTrung1) {
            soTrung2 = (rand() % 15) + 1;
        }

        int soNguoiDung1, soNguoiDung2;

        printf("Nhap so thu nhat (01 - 15): ");
        if (scanf("%d", &soNguoiDung1) != 1 || soNguoiDung1 < 1 || soNguoiDung1 > 15) {
            printf("So nhap vao khong hop le.\n");
            while (getchar() != '\n'); continue;
        }

        printf("Nhap so thu hai (01 - 15, khac so thu nhat): ");
        if (scanf("%d", &soNguoiDung2) != 1 || soNguoiDung2 < 1 || soNguoiDung2 > 15 || soNguoiDung2 == soNguoiDung1) {
            printf("So nhap vao khong hop le hoac trung voi so thu nhat.\n");
            while (getchar() != '\n'); continue;
        }

        printf("--------------------------------------\n");

        int soLanTrung = 0;

        // Kiem tra so 1
        if (soNguoiDung1 == soTrung1 || soNguoiDung1 == soTrung2) {
            soLanTrung++;
        }
        // Kiem tra so 2
        if (soNguoiDung2 == soTrung1 || soNguoiDung2 == soTrung2) {
            soLanTrung++;
        }

        // Hien thi ket qua
        printf("Ket qua Xo so la: %02d va %02d\n", soTrung1, soTrung2);
        printf("Ban da chon: %02d va %02d\n", soNguoiDung1, soNguoiDung2);

        printf("======================================\n");
        if (soLanTrung == 2) {
            printf("Chuc mung ban da TRUNG GIAI NHAT! (Trung 2 so)\n");
        }
        else if (soLanTrung == 1) {
            printf("Chuc mung ban da TRUNG GIAI NHI! (Trung 1 so)\n");
        }
        else {
            printf("Chuc ban may man lan sau! (Trung 0 so)\n");
        }
        printf("======================================\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | 0 = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

// CN 10 
// Dinh nghia struct cho Phan So
struct PhanSo {
    int tu;
    int mau;
};

// Ham rut gon phan so
void rutGon(struct PhanSo* ps) {
    if (ps->mau == 0) return; // Khong the rut gon neu mau = 0
    if (ps->tu == 0) {
        ps->mau = 1;
        return;
    }

    int ucln = USCLN(ps->tu, ps->mau); // Su dung ham USCLN tu Chuc nang 2
    ps->tu /= ucln;
    ps->mau /= ucln;

    // Dam bao mau so luon duong
    if (ps->mau < 0) {
        ps->tu = -ps->tu;
        ps->mau = -ps->mau;
    }
}

// Ham cong 2 phan so
struct PhanSo congPS(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    rutGon(&ketQua);
    return ketQua;
}

// Ham tru 2 phan so
struct PhanSo truPS(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    rutGon(&ketQua);
    return ketQua;
}

// Ham nhan 2 phan so
struct PhanSo nhanPS(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.tu;
    ketQua.mau = ps1.mau * ps2.mau;
    rutGon(&ketQua);
    return ketQua;
}

// Ham chia 2 phan so
struct PhanSo chiaPS(struct PhanSo ps1, struct PhanSo ps2) {
    struct PhanSo ketQua;
    // Chia ps1/ps2 = ps1 * (ps2.mau / ps2.tu)
    ketQua.tu = ps1.tu * ps2.mau;
    ketQua.mau = ps1.mau * ps2.tu;
    rutGon(&ketQua);
    return ketQua;
}

void tinhToanPhanSo()
{
    int chon;
    do
    {
        printf("--- THUC HIEN TINH TOAN PHAN SO ---\n");
        struct PhanSo ps1, ps2;

        printf("Nhap phan so thu nhat (Tu Mau, vi du: 1 2): ");
        if (scanf("%d %d", &ps1.tu, &ps1.mau) != 2 || ps1.mau == 0) {
            printf("Nhap phan so khong hop le (Mau so phai khac 0).\n");
            while (getchar() != '\n'); continue;
        }

        printf("Nhap phan so thu hai (Tu Mau, vi du: 3 4): ");
        if (scanf("%d %d", &ps2.tu, &ps2.mau) != 2 || ps2.mau == 0) {
            printf("Nhap phan so khong hop le (Mau so phai khac 0).\n");
            while (getchar() != '\n'); continue;
        }

        // Rut gon ban dau de hien thi dep hon
        rutGon(&ps1);
        rutGon(&ps2);

        printf("--------------------------------------\n");
        printf("Hai phan so da rut gon: %d/%d va %d/%d\n", ps1.tu, ps1.mau, ps2.tu, ps2.mau);
        printf("--------------------------------------\n");

        // 1. Cong
        struct PhanSo tong = congPS(ps1, ps2);
        printf("1. Tong (%d/%d + %d/%d) = %d/%d\n", ps1.tu, ps1.mau, ps2.tu, ps2.mau, tong.tu, tong.mau);

        // 2. Tru
        struct PhanSo hieu = truPS(ps1, ps2);
        printf("2. Hieu (%d/%d - %d/%d) = %d/%d\n", ps1.tu, ps1.mau, ps2.tu, ps2.mau, hieu.tu, hieu.mau);

        // 3. Nhan
        struct PhanSo tich = nhanPS(ps1, ps2);
        printf("3. Tich (%d/%d * %d/%d) = %d/%d\n", ps1.tu, ps1.mau, ps2.tu, ps2.mau, tich.tu, tich.mau);

        // 4. Chia
        if (ps2.tu != 0) {
            struct PhanSo thuong = chiaPS(ps1, ps2);
            printf("4. Thuong (%d/%d / %d/%d) = %d/%d\n", ps1.tu, ps1.mau, ps2.tu, ps2.mau, thuong.tu, thuong.mau);
        }
        else {
            printf("4. Thuong: KHONG THE CHIA cho 0.\n");
        }

        printf("--------------------------------------\n");

        printf("Tiep tuc thuc hien CN nay? [1 = Co | 0 = Khong]: ");
        if (scanf("%d", &chon) != 1) { while (getchar() != '\n'); chon = 0; }
        printf("\n");
    } while (chon == 1);
}

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
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Hay chon CN tren Menu [1-10]\n");
            // Tam dung de nguoi dung doc thong bao loi
            printf("Nhan phim bat ky de quay ve Menu chinh.");
            getchar();
            break;
        }

    } while (chon != 0);
    return 0;
}

