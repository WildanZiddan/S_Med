#ifndef DEKLARASITIPEDATA_H
#define DEKLARASITIPEDATA_H
#include <stdio.h>

#endif //DEKLARASI_H

/*==================== FUNCTION BUTTONS ====================*/
#define ENTER 13
#define TAB 9
#define BCKSPC 8
#define ESC 27

/*==================== ARROW BUTTONS ====================*/
#define UP_KEY 72
#define DWN_KEY 80
#define RGHT_KEY 77
#define LEFT_KEY 75

#define STATIC_NUMB 18
#define STATIC_NUMB_LOGIN 62

int a;
int b;
int id;
int i,j,x,y;
int lebar, tinggi;
int input,inputId,output;
int count;
int found;
int find;
int out;
int cancel;
int findUser;
int jumlahData;
int setuju;
int cekstok;
int cekbulan, cektahun;

float tunai;
float total;
float kembali;

/*Temporary Variable*/
char key;
char tempId[20];
char tempUser[255];
char inputUsername[255];
char inputPassword[50];
char username[255][10] = {"Owner"};
char password[30][10] = {"Owner"};
char role[30][10] = {"Owner"};
char kdStaff[10];
char choice;
char *audioFile;
char inputrp[80];
char persen[10];
char namaFile[100];
char ans, uang[25],biaya[25];
char namaStaff[100];
char namabulan[20];

/* ========================================================= */


/* ==================== TANGGAL & WAKTU ==================== */
/*Tipe Data Tanggal*/
struct date {
    int tahun;
    int bulan;
    int hari;
};
float jan,feb,mar,apr,mei,jun,jul,aug,sep,okt,nov,des;

/*Tipe Data Waktu*/
struct time {
    int jam;
    int menit;
    int detik;
};
/* ========================================================= */


/* ==================== STRUCT ID STAFF ==================== */
// struct id {
//     int id_owner;
//     int id_kasir;
//     int id_apoteker;
// };
// typedef struct akun{
//     char username[255];
// };
// struct akun ak;
// FILE *akun;
/* ============================================================ */


/* ==================== TABLE MASTER STAFF ==================== */
typedef struct staff{
    int idStaff;
    char FName[100];
    char No_telp[13];
    struct date tanggalLahir;
    char username[50];
    char password[20];
    char role[10];
};
struct staff unew;
struct staff tempk;
struct staff k;
FILE *arspstaff;
/* ============================================================ */


/* ==================== TABLE MASTER SUPPLIER ==================== */
typedef struct supplier{
    int id_Supplier;
    char nama_Supplier[100];
    char company[50];
    char alamat[100];
    int status;
};
struct supplier sp;
FILE *arspsupplier;
/* ============================================================= */


/* ==================== TABLE MASTER OBAT ==================== */
typedef struct jenis_obat{
    int id_JenisObat;
    char nama_Jenis[100];
};
struct jenis_obat jns_obt;
FILE *arspjenisobat;

typedef struct obat{
    int id_Obat;
    char nama_Obat[100];
    int id_JenisObat;
    char nama_Jenis[100];
    float harga_Obat;
    struct date tanggalKedaluwarsa;
    int jumlahObat;
};
struct obat obt;
FILE *arspobat;
/* ============================================================ */


/* ==================== TABLE MASTER ALAT KESEHATAN ==================== */
typedef struct alatKesehatan{
    int id_Alat;
    char nama_Alat[100];
    float harga_Alat;
    int jumlahAlat;
};
struct alatKesehatan alt;
struct alatKesehatan tempalt;
FILE *arspalat;
/* ==================================================================== */


/* ==================== TABLE TRANSAKSI PENJUALAN OBAT ==================== */
typedef struct tJual{
    int id_transaksi;
    struct date tgl_pembelian;
    int id_Obat;
    int idStaff;
    char nama_Staff[100];
    float sub_total;
    float total_harga;
};
struct tJual temptrsjo;
struct tJual trsjo;
FILE *arspjualobat;

//DETAIL TRANSAKSI PENJUALAN OBAT
typedef struct{
    int id_transaksi;
    int id_Obat;
    char nama_Obat[100];
    char jenis_Obat[100];
    float harga;
    int qty;
    float subtotal;
}detailTjualobat;
detailTjualobat dtjo;
FILE *arsdetailobat;

typedef struct tBeliObat{
    int id_transaksi;
    struct date tgl_pembelian;
    int id_Obat;
    int idStaff;
    char FName[100];
    float sub_total;
    float total_harga;
};
struct tBeliObat temptrsbo;
struct tBeliObat trsbo;
FILE *arspbeliobat;

//DETAIL TRANSAKSI PENJUALAN OBAT
typedef struct detailTbeliobat{
    int id_transaksi;
    int id_Obat;
    char nama_Obat[100];
    int id_JenisObat;
    char nama_Jenis[100];
    float harga_Obat;
    int jumlahObat;
    float subtotal;

};
struct detailTbeliobat dtbo;
FILE *arsdetailbeliobat;

/* ==================== TABLE TRANSAKSI PENJUALAN ALAT ==================== */
typedef struct tJualAlat{
    int id_transaksi;
    struct date tgl_pembelian;
    int id_Alat;
    int idStaff;
    char nama_Staff[100];
    float sub_total;
    float total_harga;
};
struct tJualAlat temptrsja;
struct tJualAlat trsja;
FILE *arspjualobat;

//DETAIL TRANSAKSI PENJUALAN ALAT
typedef struct{
    int id_transaksi;
    int id_Alat;
    char nama_Alat[100];
    float harga;
    int qty;
    float subtotal;
}detailTjual;
detailTjual dtja;
FILE *arsdetailalat;

/* ==================== TABLE KERANJANG ==================== */
typedef struct keranjang{
    char nama [25];
    int qty;
};
struct keranjang krj;
FILE *arskrj;

FILE *fp,*ft,*Temp;