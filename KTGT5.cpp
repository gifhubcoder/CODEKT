// BÀI GIẢI THUẬT 5
//-------------------------------------------------------------------------//
// CÀI ĐẶT THUẬT TOÁN THAM LAM vào bài toán xếp cái túi
// Yêu cầu
// Đầu vào file input và output được nhập vào từ bàn phím
// Đầu ra
// - Dòng đầu là trọng lượng của balo
// - Những dòng tiếp theo lần lượt là
// - ID | số lượng | giá trị của cái túi đã xếp tối ưu
// GỢI Ý
// Sử dụng struct
// thuật toán nổi bọt 2 chiều
//-------------------------------------------------------------------------//
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

char input[100],output[100];

// Tạo cấu trúc cái túi
//-------------------------------------------------------------------------//
typedef struct
{
    int ID;
    float trongluong;
    float giatri;
    float dongia;
    int soluong;
} BALO;

// Tạo hàm đổi chỗ
//-------------------------------------------------------------------------//
void swap(BALO *x, BALO *y)
{
    BALO temp = *x;
    *x = *y;
    *y = temp;
}

// Tạo Hàm Tính đơn giá
//-------------------------------------------------------------------------//
void Tinhdongia(BALO arr[], long n)
{
    for(int i = 0; i < n; i++)
    arr[i].dongia = arr[i].giatri / arr[i].trongluong; // Đơn giá = giá trị / trọng lượng
}

// Tạo Hàm sắp xếp theo kiểu nổi bọt 2 chiều
//-------------------------------------------------------------------------//
void ShakerSort(BALO arr[], long n)
{
    int L = 0;
    int R = n - 1;
    int i = 0;
    while(L < R)
    {
        for ( i = L; i < R; i++)
            if(arr[i].dongia < arr[i + 1].dongia) 
            swap(&arr[i],&arr[i + 1]); 
            R--;
        for ( i = R; i > L; i--)
            if(arr[i].dongia > arr[i - 1].dongia) 
            swap(&arr[i],&arr[i - 1]); 
            L++;
    }
}

// Tạo Hàm xếp cái túi
//-------------------------------------------------------------------------//
float Xepbalo(BALO arr[], long n, long w)
{
    int i = 0;
    float toiuu = 0;
    while (w > 0 && i < n)
    {
        // Tính số lượng lần lượt theo i tăng dần sau mỗi vòng
        arr[i].soluong = (int)w / arr[i].trongluong;
        // Tính trọng lượng balo còn lại để tìm kiếm tiếp
        w -= arr[i].soluong * arr[i].trongluong;
        // Tính tổng trọng lượng của cái túi (giá trị tối ưu)
        toiuu += arr[i].soluong * arr[i].giatri;
        i++;
    }
    return toiuu; // trả về kết quả đã được tối ưu
}

// Chương trình chính
//-------------------------------------------------------------------------//
int main()
{
    cout <<"\t\t\t|-------------------------------------------------------------------------|"<<endl;
    cout <<"\t\t\t|                      Xep Cai Tui bang noi bot 2 chieu                   |"<<endl;
    cout <<"\t\t\t|                          CODE BUY: NHAN                                 |"<<endl;
    cout <<"\t\t\t|-------------------------------------------------------------------------|"<<endl;
    FILE *Fin,*Fout;
    BALO C[100];
    int num = 0, i = 0, n = 0;
    float caitui = 0, toiuu ;
    cout <<"\t\t\tMoi ban nhap file vao: "; gets(input);
    cout <<"\t\t\tMoi ban nhap file ra: "; gets(output);
    if((Fin = fopen(input,"r")) == NULL)
    {
        cout<<"\t\t\tFILE LOI!"; exit(1);
    }
    if((Fout = fopen(output,"w")) == NULL)
    {
        cout<<"\t\t\tFILE LOI!"; exit(1);
    }
    fscanf(Fin,"%f",&caitui);
    cout <<"\t\t\tTrong Luong cai tui la: " << caitui <<endl; 
    while (fscanf(Fin,"%d",&num) != EOF)
    {
        if(i%3 == 2)
        {
            C[n].giatri = num;
            cout <<"\t\t\tGia Tri: " << num;
        }
        else if (i%3 == 1)
        {
            C[n].trongluong = num;
            cout <<"\t\t\tTrong Luong: " << num;
        }
        else
        {
            C[n].ID = num;
            cout <<"\t\t\tID: " << num;
        }
        i++;
        if(i%3 == 0) 
        {
            cout<<"\n"; n++;
        }
    }
    cout <<"\t\t\tTong so luong do vat: " << n <<endl;
    Tinhdongia(C,n);
    ShakerSort(C,n);
     for(i=0;i<n;i++)
    {
        printf("\t\t\tID: %d \tDon Gia: %10.2f\tTrong Luong: %10.2f\tGia Tri: %10.2f \n",C[i].ID,C[i].dongia,C[i].trongluong,C[i].giatri);
    }
    toiuu = Xepbalo(C,n,caitui);
    printf("\t\t\tTong gia tri toi uu %10.2f\n",toiuu);
    fprintf(Fout,"\t\t\tTong gia tri toi uu %10.2f\n",toiuu);
    for(i=0;i<n;i++)
    {
        if(C[i].soluong * C[i].giatri == toiuu)// nếu trọng lượng túi là chẵn
        {
            printf("\t\t\tID: %d\tSo Luong: %d\t\tTrong Luong: %10.2f\t\tGia Tri: %10.2f \n",C[i].ID,C[i].soluong,C[i].trongluong,C[i].giatri);
            fprintf(Fout,"\t\t\tID: %d\tSo Luong: %d\t\tTrong Luong: %10.2f\t\tGia Tri: %10.2f \n",C[i].ID,C[i].soluong,C[i].trongluong,C[i].giatri);
        }
        else if(C[i].soluong > 0) // nếu trọng lượng túi là lẻ
        {
            printf("\t\t\tID: %d\tSo Luong: %d\t\tTrong Luong: %10.2f\t\tGia Tri: %10.2f \n",C[i].ID,C[i].soluong,C[i].trongluong,C[i].giatri);
            fprintf(Fout,"\t\t\tID: %d\tSo Luong: %d\t\tTrong Luong: %10.2f\t\tGia Tri: %10.2f \n",C[i].ID,C[i].soluong,C[i].trongluong,C[i].giatri);
        }
    }
    fclose(Fin);
    fclose(Fout);
    cout<<"\t\t\tDONE!";
    return 0;
}
