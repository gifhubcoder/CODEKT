// BÀI GIẢI THUẬT 1
//-------------------------------------------------------------------------//
// Cài đặt thuật toán quy hoạch động:
// Đầu vào
// - file input output được nhâp vào từ bàn phím
// - in ra màn hình
// - Dòng 1: Chuỗi 1
// - Dòng 2: Chuỗi 2
// Đầu ra
// - Dòng 1: chữ LSC
// - Dòng 2: chuỗi 1
// - Dòng 3: chuỗi 2
// - Dòng 4: độ dài lớn nhất
// - Dòng 5: chuỗi con có độ dài lớn nhất
//-------------------------------------------------------------------------//
// Gợi ý:
// Đầu tiên tìm độ dài của chuỗi chung
// Tiếp theo chạy ngược lại về 0 và so sánh 2 chuỗi giống nhau thì lấy không thì tìm phần khác nhau và xóa
//-------------------------------------------------------------------------//
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

char input[100], output[100];// khởi tạo biến nhập file
char lsc_string[100];// chuỗi con lớn nhất
int lsc_max; // biến đo độ dài

// Tạo Hàm max
//-------------------------------------------------------------------------//
int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

// Tạo hàm tìm chuỗi chung lớn nhất
void LSC_BUID(char x[], char y[])
{
    int a = strlen(x);
    int b = strlen(y);
    int c[100][100], i,j;
    for(i = 0; i <= a; i++)
    c[i][0] = 0;// khởi tạo vị trí xuất phát = 0
        for(j = 0; j <= b; j++)
        c[0][j] = 0;// khởi tạo vị trí xuất phát = 0
    // tính chiều dài
    for(i = 1; i <= a; i++)
        for(j = 1; j <= b; j++)
        if(x[i-1] == y[j-1]) // nếu chuỗi x = chuỗi y thì độ dài + 1
            c[i][j] = c[i-1][j-1] + 1;
        else// ngược lại thì tìm chuỗi lớn nhất
            c[i][j] = max(c[i][j-1],c[i-1][j]); 
    // sau khu tìm xong thì gán giá trị cho lsc_max
    lsc_max = c[a][b];
    int index = lsc_max;
    lsc_string[index + 1] = '\0';// chuỗi tăng lên 1 khi xuống dòng
    // bắt đầu kiểm tra ngược về 0 bằng while
    // gán độ dài của chuỗi a b cho i và j
    i = a, j = b;
    while (i >= 0 && j >= 0)
    {
        if(x[i-1] == y[j-1])
        {
            index--;
            lsc_string[index] = x[i-1];
            i--; j--;
        }
        else if(c[i-1][j]  > c[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
}
int main()
{
    FILE *Fin,*Fout;
    char x[100],y[100];
    cout <<"|-------------------------------------------------------------------------|"<<endl;
    cout <<"|                         Tim Chuoi chung lon nhat                        |"<<endl;
    cout <<"|                         CODE BUY: NHAN CODER                            |"<<endl;
    cout <<"|-------------------------------------------------------------------------|"<<endl;
    cout<< "Nhap file vao  "; gets(input);
    cout<< "Nhap file vao  "; gets(output);
    if((Fin = fopen(input,"r")) == NULL)
    {
        cout <<"Loi open";
        exit(1);
    }
    fgets(x,100,Fin);
    x[strlen(x) - 1] = '\0';
    fgets(y,100,Fin);
    y[strlen(y) - 1] = '\0';
    fclose(Fin);
    LSC_BUID(x,y);
    cout<< "\t\t\tChuỗi 1: " << x <<endl;
    cout<< "\t\t\tChuỗi 2: " << y <<endl;
    cout<< "\t\t\tMax: " << lsc_max <<endl;
    cout<< "\t\t\tLSC: " << lsc_string <<endl;
    if((Fout = fopen(output,"w")) == NULL)
    {
        cout<<"Loi open";
        exit(1);
    }
    fprintf(Fout,"|-------------------------------------------------------------------------|\n");
     fprintf(Fout,"|                         Tim Chuoi chung lon nhat                        |\n");
      fprintf(Fout,"|                         CODE BUY: NHAN CODER                            |\n");
       fprintf(Fout,"|-------------------------------------------------------------------------|\n");
        fprintf(Fout,"\n\t\t\t Chuỗi 1: %s",x);
         fprintf(Fout,"\n\t\t\t Chuỗi 2: %s",y);
          fprintf(Fout,"\n\t\t\t Max: %d",lsc_max);
           fprintf(Fout,"\n\t\t\t LSC: %s",lsc_string);
    fclose(Fout);
    cout<<"\n\n\t\t\tDONE!";
    return 0;
}
