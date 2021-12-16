#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//function untuk mengecek identitas nasabah
void cekident(asal) {
    int password;
    search = head;
    if(head == NULL){
      printf("\n\t\t\t    Tidak ada data nasabah\n");
      printf("\n\t\t\t Tekan apa saja untuk kembali\n");
      getch();
      main();
    }

   while(search!=NULL){
      if(search->nomor == asal){
         printf("\n\t\t Nama Nasabah       : %s\n", search->nama);
         printf("\n\t\t Masukkan password  : ");
         scanf("%d", &password);
         if (search->pass != password){
            printf("\n\t   Mohon maaf password salah");
            printf("\n\t Tekan apa saja untuk kembali");
            getch();
            main();
         } else if ((search->pass == password)) {
                printf("\n\t Login berhasil, \n");
                return;
           }
      } if(search->next != NULL) {
          search = search->next;
        } else {
            printf("\n\t\t\t Identitas nasabah tidak ditemukan\n");
            printf("\n\t\t\t   Tekan apa saja untuk kembali\n");
            getch();
            main();
          }
     }
}

//function untuk menghapus data nasabah pada menu kedua
void hapusdata(int delete){
   if (head == NULL){
      printf("\n\t\t\t\t Tidak ada data nasabah\n");
      return;
   }

   hapus = head;

   while(hapus!=NULL) {
      if(hapus->nomor == delete) {
         if (hapus == head) {
             head = head->next;
             free(hapus);
             hapus = head;
             printf("\n\t\t\t Data nasabah terhapus\n");
             jumlahnode--;
             return;
          } else {
                head->prev->next = hapus->next;
                free(hapus);
                printf("\n\t\t\t Data nasabah terhapus\n");
                hapus = head->prev->next;
                jumlahnode--;
              }
       } else {
            head->prev = hapus;
            hapus = hapus->next;
           }
    }
}

int main()
{
    int menu;
    do
    {
        
    
    switch(menu)
     {
        case 1:
        
        case 2:
        system("cls");
            printf("\n\n=========================::::: Hapus Data Nasabah :::::=========================\n");
            printf("\n\t Masukkan Identitas Nasabah yang ingin Dihapus\n");
            printf("\n\t\t Nomor identitas    : ");
            scanf("%d", &del);
            cekident(del);
            hapusdata(del);
            break;
        case 3:
        
        case 4:
        void update(int old, int new)
        {
           int urutan = 0;
           int plus = 1;
           if(head == NULL)
           {
              printf("|$|Tidak ada data nasabah");
              getch();
              main();
           } 

           temp3 = head;
           while(temp3!=NULL)
           {
              urutan++;

              if(temp3->nomor == old)
              {
                 temp3->saldo = temp3->saldo + new;
                 histtopup(temp3->nama, new, plus);
                 printf("\n|$|Nasabah ditemukan pada urutan %d atas nama %s, saldo ditambah menjadi %d\n", urutan, temp3->nama, temp3->saldo);
                 return;
              }

              if(temp3->next != NULL)
              {
                 temp3 = temp3->next;
              }
              else
              {
                getch();
                main();
              }
           }
           printf("|$|Maaf tidak ada nasabah dengan nomor identitas %d\n", old);
        }
        case 5 :
        
        case 6:
        
        case 7:
        
        case 8:
       
        break;
        default:
        printf("\n\t\t\t Mohon maaf menu yg anda pilih salah\n");
        break;
    }
    printf("\n=================================================================================\n");
    printf("\nApakah anda ingin mengulang program ? ");
    printf("\n\t\t 1. Ya\n");
    printf("\n\t\t 2. Tidak\n");
    printf("\n\t Masukkan Pilihan Anda  : ");
    scanf("%d", &ulang);

    } while (ulang == 1);
    return;
}
