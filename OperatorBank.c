#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
    int menu;
    do
    {
        
    
    switch(menu)
     {
        case 1:
        
        case 2:
        
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
        printf("Mohon maaf menu yg anda pilih salah");
        break;
    }
    printf("\nApakah anda ingin mengulang? Input 1 jika ya : ");
    scanf("%d", &ulang);

    } while (ulang == 1);

    return;
}
