#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define max 5

int jumlahnode = 0;

struct node
{
   char nama[50];
   long int nomor, saldo, pass;
   struct node *prev;
   struct node *next;
} * head, *temp, *temp1, *temp2, *temp3, *temp4, *temp5, *hapus, *hps, *search, *tarik;

struct History
{
   char nama[50];
};
struct History riwayat[max];

// function membuat/menambah node
void createNode()
{
   int nomor, saldo, pass;
   char nama[30];
   temp = (struct node *)malloc(sizeof(struct node));
   temp->prev = NULL;
   temp->next = NULL;
   printf("\n\t Masukkan nama nasabah        : ");
   scanf(" %49[^\n]", &nama);
   printf("\n\t Masukkan nomor identitas     : ");
   scanf("%d", &nomor);
   printf("\n\t Masukkan password identitas  : ");
   scanf("%d", &pass);
   printf("\n\t Masukkan jumlah top up saldo : ");
   scanf("%d", &saldo);
   temp->nomor = nomor;
   temp->pass = pass;
   temp->saldo = saldo;
   strcpy(temp->nama, nama);
   jumlahnode++;
}

// function menambah node kedalam linked list
void addData()
{
   printf("\n\n=========================::::: Tambah Data Nasabah :::::=========================\n");
   if (head == NULL)
   {
      createNode();
      head = temp;
      temp1 = head;
   }
   else
   {
      createNode();
      temp1->next = temp;
      temp->prev = temp1;
      temp1 = temp;
   }
}

// function untuk mengecek identitas nasabah
void checkIdentity(asal)
{
   int password;
   search = head;
   if (head == NULL)
   {
      printf("\n\t\t\t    Tidak ada data nasabah\n");
      printf("\n\t\t\t Tekan apa saja untuk kembali\n");
      getch();
      main();
   }
   while (search != NULL)
   {
      if (search->nomor == asal)
      {
         printf("\n\t\t Nama Nasabah       : %s\n", search->nama);
         printf("\n\t\t Masukkan password  : ");
         scanf("%d", &password);
         if (search->pass != password)
         {
            printf("\n\t   Mohon maaf password salah");
            printf("\n\t Tekan apa saja untuk kembali");
            getch();
            main();
         }
         else if ((search->pass == password))
         {
            printf("\n\t Login berhasil, \n");
            return;
         }
      }
      if (search->next != NULL)
      {
         search = search->next;
      }
      else
      {
         printf("\n\t\t\t Identitas nasabah tidak ditemukan\n");
         printf("\n\t\t\t   Tekan apa saja untuk kembali\n");
         getch();
         main();
      }
   }
}

// function untuk menghapus data nasabah pada menu kedua
void deleteData(int delete)
{
   if (head == NULL)
   {
      printf("\n\t\t\t\t Tidak ada data nasabah\n");
      return;
   }

   hapus = head;

   while (hapus != NULL)
   {
      if (hapus->nomor == delete)
      {
         if (hapus == head)
         {
            head = head->next;
            free(hapus);
            hapus = head;
            printf("\n\t\t\t Data nasabah terhapus\n");
            jumlahnode--;
            return;
         }
         else
         {
            head->prev->next = hapus->next;
            free(hapus);
            printf("\n\t\t\t Data nasabah terhapus\n");
            hapus = head->prev->next;
            jumlahnode--;
         }
      }
      else
      {
         head->prev = hapus;
         hapus = hapus->next;
      }
   }
}

void updateData(int old, int new)
{
   int urutan = 0;
   int plus = 1;
   if (head == NULL)
   {
      printf("\n\t\t\t\t Tidak ada data nasabah\n");
      getch();
      main();
   }

   temp3 = head;
   while (temp3 != NULL)
   {
      urutan++;

      if (temp3->nomor == old)
      {
         temp3->saldo = temp3->saldo + new;
         historyTopup(temp3->nama, new, plus);
         printf("\n\t Nasabah ditemukan pada urutan %d atas nama %s, saldo ditambah menjadi %d\n", urutan, temp3->nama, temp3->saldo);
         return;
      }

      if (temp3->next != NULL)
      {
         temp3 = temp3->next;
      }
      else
      {
         getch();
         main();
      }
   }
   printf("\n\t\t Maaf tidak ada nasabah dengan nomor identitas %d\n", old);
}

void updateData2(int old, int new)
{
   int urutan = 0;
   int min = 0;

   if (head == NULL)
   {
      printf("\n\t\t\t Tidak ada data nasabah");
      getch();
      main();
   }

   tarik = head;
   while (tarik != NULL)
   {
      urutan++;

      if (tarik->nomor == old)
      {
         if (tarik->saldo < new)
         {
            printf("\n\t\t\t Mohon maaf saldo nasabah tidak cukup\n");
            printf("\n\t\t\t    Tekan apa saja untuk kembali\n");
            getch();
            main();
         }
         tarik->saldo = tarik->saldo - new;
         historyTopup(tarik->nama, new, min);
         printf("\n\t Nasabah ditemukan pada urutan %d atas nama %s, saldo dikurangi menjadi %d\n", urutan, tarik->nama, tarik->saldo);
         return;
      }

      if (tarik->next != NULL)
      {
         tarik = tarik->next;
      }
      else
      {
         getch();
         main();
      }
   }
   printf("\n\t\t Maaf tidak ada nasabah dengan nomor identitas %d\n", old);
}

void transferData(int asal, int tujuan, int transferData)
{
   temp4 = head;
   char tf[50];
   if (head == NULL)
   {
      printf("\n\t\t\t   Tidak ada data nasabah\n");
      printf("\n\t\t\t Tekan apa saja untuk kembali\n");
      getch();
      main();
   }

   while (temp4 != NULL)
   {
      if (temp4->nomor == asal)
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
      if (temp4->next != NULL)
      {
         temp4 = temp4->next;
      }
      else
      {
         break;
      }
   }

   temp4 = head;
   while (temp4 != NULL)
   {
      if (temp4->nomor == tujuan)
      {
         temp4->saldo = temp4->saldo + transferData;
         printf("\n\t akan mentransfer dana kepada nasabah lain atas nama %s\n", temp4->nama);
         printf("\n\t\t\t   Transfer berhasil dilakukan!\n");
         return;
      }
      if (temp4->next != NULL)
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

// Fungsi implementasi queue
void history(char nasabah[50])
{
   if (rear == max - 1 && front == 0 || rear + 1 == front)
   {
      front2++;
      if (front == rear)
      {
         front = -1;
         rear = -1;
      }
      else
      {
         front = (front + 1) % max;
      }
      history(nasabah);
   }
   else
   {
      if (front == -1)
      {
         front = 0;
      }
      rear = (rear + 1) % max;
      rear2++;
      strcpy(riwayat[rear2].nama, nasabah);
   }
}

// Fungsi mencetak history
void showHistory()
{
   if (front != -1)
   {
      for (i = front2; i <= rear2; i++)
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
      int menu, ulang, lama, baru, asal, transf, jumlah, del, topup;
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

         switch (menu)
         {
         case 1:
            system("cls");
            addData();
            break;
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
         case 5:
            system("cls");
            printf("\n\n=========================::::: Tarik Saldo Nasabah :::::========================\n");
            printf("\n\t\t Nomor identitas    : ");
            scanf("%d", &lama);
            checkIdentity(lama);
            printf("\n\t\t Nominal yang ingin ditarik nasabah   : ");
            scanf("%d", &baru);
            updateData2(lama, baru);
         case 6:
            system("cls");
            printf("\n\n====================::::: Transfer Saldo ke Nasabah Lain :::::===================\n");
            printf("\n\t\t Nomor identitas    : ");
            scanf("%d", &asal);
            checkIdentity(asal);
            printf("\n\t\t Masukkan nomor identitas tujuan transfer : ");
            scanf("%d", &transf);
            checkIdentity2(transf);
            printf("\n\t\t Masukkan jumlah transfer : ");
            scanf("%d", &jumlah);
            transferData(asal, transf, jumlah);
            break;
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
