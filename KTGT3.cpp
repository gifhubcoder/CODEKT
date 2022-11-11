// BÀI GIẢI THUẬT 3
//-------------------------------------------------------------------------//
// CÀI ĐẶT THUẬT TOÁN THAM LAM vào bài toán xếp lịch học
// Yêu cầu
// Đầu vào file input và output được nhập vào từ bàn phím
// Đầu ra
// - Dòng đầu là số lớp tối ưu
// - Những dòng tiếp theo lần lượt là
// - ID | Start | Finish của các lớp đã xếp tối ưu
// GỢI Ý
// Sử dụng struct
// thuật toán nổi bọt
//-------------------------------------------------------------------------//
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

typedef struct 
{
    int ID;
    int Start;
    int Finish;
} lophoc;

char input[100],output[100];// Biến để nhập tiên file

// Cài đặt thuật toán nổi bọt
//-------------------------------------------------------------------------//
void BuleSort(lophoc arr[], long n)
{
    long i,j;
    lophoc x;
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - 1 - i;j++)
            if(arr[j].Finish > arr[j+1].Finish)
            x = arr[j];
}
// Chương trình chính
//-------------------------------------------------------------------------//
int main()
{
    cout <<"|-------------------------------------------------------------------------|"<<endl;
    cout <<"|                     Sap xep noi bot cho lich hoc                        |"<<endl;
    cout <<"|                         CODE BUY: NHAN CODER                            |"<<endl;
    cout <<"|-------------------------------------------------------------------------|"<<endl;
    cout<< "Nhap file vao  "; gets(input);
    cout<< "Nhap file ra  "; gets(output);
    FILE *Fin,*Fout;
    if((Fin = fopen(input,"r")) == NULL)
    {
        cout<< "FILE KHONG TON TAI";
        exit(1);
    }
    int n = 0; // số lượng tổng thể các lớp
    // Thêm mảng C chứa các  lớp theo kiểu lophoc
    // Thêm mảng O chứa các lớp theo kiểu lophoc
    lophoc C[1000],O[1000];
    cout<<"\n\t\t\tDu lieu duoc nhap vao tu file:";
    int i = 0, num = 0;
    while(fscanf(Fin,"%d",&num) != EOF)
    {
        if(i%3 == 2)
        {
            C[n].Finish = num;
            cout<<"\n\t\t\tKet Thuc: " << num;
        }
        else if (i%3 == 1)
        {
            C[n].Start = num;
            cout<<"\n\t\t\tBat Dau: "<< num;
        }
        else
        {
            C[n].ID = num;
            cout<<"\n\t\t\tID LOP: "<<num;
        }
        i++;
        if(i%3 == 0) n++;
    }
    fclose(Fin);
    // in ra màn hình kết quả đã tính xong
    cout<<"\n\t\t\tTong So Cac Lop La:"<<n;
    BuleSort(C,n);// thực hiện sắp xếp
    cout<<"\n\t\t\tCac Lop Theo Thu tu tang dan la:\n";
    for(i = 0; i < n; i++)
    {
        cout<<"\t\t\tID LOP: "<<C[i].ID<<"\tBat Dau: "<<C[i].Start<<"\tKet Thuc: "<<C[i].Finish<<endl;
    }
    // Khởi tạo vị trí bắt đầu chọn lọc
    O[0] = C[0];
    int k = C[0].Finish;
    int dem = 1;
    // bắt đầu tối ưu
    for(i = 1; i < n; i++)
    {
        if(C[i].Start > k)// nếu thời gian bắt đầu tiếp theo là i+1 lớn hơn thời gian mốc
        {
            O[dem] = C[i];// Mảng O sẽ được gán = mảng C {ID:Start:Finish}
            k = O[dem].Finish;// mốc cũ sẽ được gán thành mốc mới
            dem++;// đếm số lớp đc tăng thêm 1
        }
    }
    cout<<"\n\t\t\tWriting...............";
    if((Fout = fopen(output,"w")) == NULL)
    {
        cout<<"FILE Khong ton tai"; exit(1);
    }
    cout<<"\n\t\t\tSo lop da toi uu la: "<< dem<<endl;
    fprintf(Fout,"|-------------------------------------------------------------------------|\n");
     fprintf(Fout,"|                         XAP SEP LICH HOC                                |\n");
      fprintf(Fout,"|                         CODE BUY: NHAN CODER                            |\n");
       fprintf(Fout,"|-------------------------------------------------------------------------|\n");
        fprintf(Fout,"\n\t\t\t Số Lớp Tối Ưu là: %d\n",dem);
         for(i = 0; i < n; i++)
         {
            cout<<"\t\t\tID LOP: "<<O[i].ID<<"\tBat Dau: "<<O[i].Start<<"\tKet Thuc: "<<O[i].Finish<<endl;
            fprintf(Fout,"\n\t\t\tID LOP: %d\t Bat Dau: %d\t Ket Thuc: %d",O[i].ID,O[i].Start,O[i].Finish);
         }
    fclose(Fout);
    return 0;
}
