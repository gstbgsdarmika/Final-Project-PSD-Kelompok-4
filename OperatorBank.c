#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define max 5

struct History {
  char nama[50];
};
struct History riwayat[max];

//function untuk mengecek identitas nasabah
void checkIdentity(asal){
    int password;
    search = head;
    if(head == NULL){
      printf("\n\t\t\t    Tidak ada data nasabah\n");
      printf("\n\t\t\t Tekan apa saja untuk kembali\n");
      getch();
      main();
    }
    while(search!=NULL){
        if(search->nomor == asal) {
         printf("\n\t\t Nama Nasabah       : %s\n", search->nama);
         printf("\n\t\t Masukkan password  : ");
         scanf("%d", &password);
         if (search->pass != password){
            printf("\n\t   Mohon maaf password salah");
            printf("\n\t Tekan apa saja untuk kembali");
            getch();
            main();
           } else if ((search->pass == password)){
               printf("\n\t Login berhasil, \n");
               return;
               }
        } if(search->next != NULL) {
               search = search->next;
             }  else {
                 printf("\n\t\t\t Identitas nasabah tidak ditemukan\n");
                 printf("\n\t\t\t   Tekan apa saja untuk kembali\n");
                 getch();
                 main();
                }
     }
}


//function untuk menghapus data nasabah pada menu kedua
void deleteData(int delete)
{
   if (head == NULL) {
       printf("\n\t\t\t\t Tidak ada data nasabah\n");
       return;
     }

   hapus = head;

   while(hapus!=NULL){
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
         }else{
            head->prev = hapus;
            hapus = hapus->next;
            }
     }
}

void transferData(int asal, int tujuan, int transferData)
{
    temp4 = head;
    char tf[50];
    if(head == NULL)
   {
      printf("\n\t\t\t   Tidak ada data nasabah\n");
      printf("\n\t\t\t Tekan apa saja untuk kembali\n");
      getch();
      main();
   }

   while(temp4!=NULL)
   {
      if(temp4->nomor == asal)
      {
         printf("\n\t Nasabah atas nama %s\n", temp4->nama);
         if (temp4->saldo < transferData)
         {
            printf("\n\t\t\t Mohon maaf saldo nasabah tidak cukup\n");
            printf("\n\t\t\t    Tekan apa saja untuk kembali\n");
            getch();
            main();
         }
         temp4->saldo = temp4->saldo - transferData;
         history(temp4->nama);
      }
      if(temp4->next != NULL)
      {
         temp4 = temp4->next;
      }
      else
      {
         break;
      }
   }

   temp4 = head;
   while(temp4!=NULL)
   {
      if(temp4->nomor == tujuan)
      {
         temp4->saldo = temp4->saldo + transferData;
         printf("\n\t akan mentransfer dana kepada nasabah lain atas nama %s\n", temp4->nama);
         printf("\n\t\t\t   Transfer berhasil dilakukan!\n");
         return;
      }
      if(temp4->next != NULL)
      {
         temp4 = temp4->next;
      }
      else
      {
         getch();
         main();
      }
   }
}

//Fungsi implementasi queue
void history(char nasabah[50])
{
			if(rear==max-1 && front == 0 || rear+1==front)
         {
            front2++;
            if (front==rear)
            {
               front=-1;
               rear=-1;
            }
            else
            {
               front=(front+1)%max;
            }
            history(nasabah);
			}
			else
         {
				if(front==-1)
            {
					front=0;
				}
				rear = (rear+1)%max;
				rear2++;
            strcpy(riwayat[rear2].nama, nasabah);
			}
}

//Fungsi mencetak history
void showHistory()
{
   if(front!=-1)
         {
	        for(i=front2; i<=rear2; i++)
           {
				 printf("\n\t\t Nama Nasabah    : %s  (Transfer)\n", riwayat[i].nama);
			  }
			}
			else
         {
				printf("\n\t\t\t\t History kosong\n");
			}
}


int main()
{
    int menu;
    do
    {
        int menu,ulang,lama,baru,asal,transf,jumlah,del,topup;
    do
    {
    system("cls");
    printf("\n\n==========================::::: PROGRAM MENU BANK :::::==========================\n");
    printf("\n Pilihan Menu :\n");
    printf("\n\t 1. Tambah Data Nasabah\n");
    printf("\n\t 2. Hapus Data Nasabah\n");
    printf("\n\t 3. Tampilkan Data Nasabah\n");
    printf("\n\t 4. Top Up Saldo Nasabah\n");
    printf("\n\t 5. Tarik  Saldo Nasabah\n");
    printf("\n\t 6. Transfer Saldo ke Nasabah Lain\n");
    printf("\n\t 7. Cek Riwayat Transfer\n");
    printf("\n\t 8. Cek Riwayat Transaksi\n");
    printf("\n=================================================================================\n");
    printf("\n\t Masukkan Pilihan Anda : ");
    scanf("%d", &menu);  
    
    switch(menu)
     {
        case 1:
        
        case 2:
            system("cls");
            printf("\n\n=========================::::: Hapus Data Nasabah :::::=========================\n");
            printf("\n\t Masukkan Identitas Nasabah yang ingin Dihapus\n");
            printf("\n\t\t Nomor identitas    : ");
            scanf("%d", &del);
            checkIdentity(del);
            deletedata(del);
            break;
        case 3:
        
        case 4:
            system("cls");
            printf("\n\n========================::::: Top Up Saldo Nasabah :::::========================\n");
            printf("\n\t\t Nomor identitas  : ");
            scanf("%d", &lama);
            checkIdentity(lama);
            printf("\n\t\t Masukkan nominal top up : ");
            scanf("%d", &baru);
            updateData(lama, baru);
            break;
        case 5 :
        
        case 6:
        
        case 7:
            system("cls");
            printf("\n\n=========================:::: Cek Riwayat Transaksi :::::========================\n");
            showHistory();
            break;
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
