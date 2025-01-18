// void updateAlat() {
//     SetColorBlock(15, 12);
//     showCursor();
//
//     gotoprinttext(140, 22, "U P D A T E  D A T A");
//     gotoxy(132, 24);
//     printf("Masukkan ID Alat : ALT");
//     gotoxy(158, 24);
//     getnum(&id, 3);  // Ambil input ID kelas
//     hideCursor();
//
//     SpecialKeyUpdateAlat(152, 26, 13, 3, &output);  // Ambil input pilihan menu update
//
//     switch (output) {
//         case 1:  // Mengupdate data kelas berdasarkan ID
//             arspalat = fopen("../Database/alatkesehatan.dat", "rb");
//             ft = fopen("../Database/temp.dat", "wb");
//             found = 0;
//             while (fread(&alt, sizeof(alt), 1, arspalat)) {
//                 if (alt.id_Alat == id) {
//                     MessageBox(NULL, "ID Kelas Ditemukan", "NOTIFICATION", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                     found = 1;
//                     break;
//                 } else {
//                     fwrite(&alt, sizeof(alt), 1, ft);  // Simpan data lama ke file sementara
//                 }
//             }
//
//             if (found == 1) {
//                 clearTengah();
//                 DashboardDetail(55, 102, 10, 24, 103, 56, 25, 11);
//                 seluruhDataAlat();  // Menampilkan data kelas saat ini
//                 gotoxy(78, 14);
//                 generateid("alt", alt.id_Alat);
//                 gotoxy(78, 16);
//                 printf("%s", 	alt.nama_Alat);
//                 gotoxy(78, 18);
//                 printf("%d", 	alt.harga_Alat);
//                 gotoxy(78, 20);
//                 printf("%d", 	alt.jumlahAlat);
//
//                 clearKanan();
//                 SetColorBlock(15, 12);
//                 gotoprinttext(140, 12, "U P D A T E  D A T A");
//                 menuUpdateDataKelas();  // Menampilkan menu opsi update
//                 SpecialkeyDashboardMenuUpdateDataAlat(&output);  // Ambil input opsi update
//
//                 switch (output) {
//                     case 1:  // Update Nama Kelas
//                         clearKanan();
//                         showCursor();
//                         fflush(stdin);
//                         gotoxy(132, 24);
//                         SetColorBlock(15, 12);
//                         printf("Masukkan Nama Alat Baru: ");
//                         gotoxy(132, 25);
//                         scanf("%s", &alt.nama_Alat);   // Ambil input nama kelas baru
//                         hideCursor();
//                         MessageBox(NULL, "Nama Kelas Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                         fwrite(&alt, sizeof(alt), 1, ft);
//                         break;
//
//                     case 2:  // Update Harga Alat
//                         clearKanan();
//                         showCursor();
//                         gotoxy(132, 24);
//                         SetColorBlock(15, 12);
//                         printf("Masukkan Harga Alat Baru: ");
//                         gotoxy(132, 25);
//                         scanf("%d", &alt.harga_Alat);  // Ambil input jumlah anak kelas baru
//                         hideCursor();
//                         MessageBox(NULL, "Jumlah Harga Alat Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                         fwrite(&alt, sizeof(alt), 1, ft);
//                     break;
//
//                     case 3:  // Update Jumlah Alat
//                         clearKanan();
//                         showCursor();
//                         gotoxy(132, 24);
//                         SetColorBlock(15, 12);
//                         printf("Masukkan Jumlah Alat Baru: ");
//                         gotoxy(132, 25);
//                         scanf("%d", &alt.jumlahAlat);  // Ambil input tingkat kelas baru
//                         hideCursor();
//                         MessageBox(NULL, "Tingkat Kelas Berhasil Diubah", "NOTIFICATION!", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
//                         fwrite(&alt, sizeof(alt), 1, ft);
//                     break;
//                 }
//             } else {
//                 MessageBox(NULL, "ID Kelas Tidak Ditemukan", "ERROR", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
//                 updateDataAlat();  // Ulangi proses jika ID tidak ditemukan
//             }
//
//             // Menyalin sisa data dari file lama ke file sementara
//             while (fread(&alt, sizeof(alt), 1, arspalat)) {
//                 fwrite(&alt, sizeof(alt), 1, ft);
//             }
//
//             fclose(arspalat);
//             fclose(ft);
//
//             // Ganti file lama dengan file sementara
//             remove("../Database/KelasFile.dat");
//             rename("../Database/temp.dat", "../Database/KelasFile.dat");
//             break;
//
//         case 2:  // Kembali ke menu data kelas
//             BlankDashboard();
//             dataAlatMenuOwner();
//             break;
//     }
// }