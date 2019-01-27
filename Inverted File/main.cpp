#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int col;
int row;
int cout_D;
float a[100][100];
/**
            col
             j

    row    a[i;j]
     i
*/
void Input_data()
{
    cin>>col;
    cin>>row;
    cin>>cout_D;
    for(int i=1; i<=row; i++)
    {
        for(int j =1; j<=col; j++)
        {
            cin>>a[i][j];
        }
    }
}
void Output_data()
{
    for(int i=1; i<=row; i++)
    {
        for(int j =1; j<=col; j++)
        {
            cout<<setw(10)<<a[i][j];
        }
        cout<<endl;
    }
}
/// Làm tròn Số Thực
double Roundf(double Real_Numbers, int result_Round)
{
    int Decimal_Number = 1;
    for(int i=1; i<=result_Round; i++)
    {
        Decimal_Number = Decimal_Number *10;
    }
    return roundf(Real_Numbers*Decimal_Number)/Decimal_Number;
}
/**
    Chuẩn hóa về bảng tần số.
    CT : a[i][j] = a[i][j] / sum (a[1->col][j])
*/
int *Sum_col;
void Arrays_Sum_Col()
{
    Sum_col = new int [col];
    for(int j=1; j<=col; j++)
    {
        int sum = 0;
        for(int i =1; i<=row; i++)
        {
            sum = sum + a[i][j];
        }
        Sum_col[j] = sum;
    }
}
void Frequency_Table()
{
    for(int i=1; i<=row; i++)
    {
        for(int j =1; j<=col; j++)
        {
            float Fre_Tab = (float)(a[i][j]/Sum_col[j]);
            a[i][j] = Roundf(Fre_Tab, 2);
        }
    }
}
/**
    Idf (inverse document frequency) xác định độ quan trọng của
    các phần tử trong tập dự liệu văn bản.
    CT : idf(i) = log(N/df(i))
    Trong đó :
    df(i) là số văn bản có chứa từ t(i)
    n là tổng số văn bản trong tập dữ liệu N = col
*/
float *Idf = new float [row];
void Arrays_Idf_Input()
{
    cout<<endl;
    int n = col;
    for(int i=1; i<=row; i++)
    {
        int cout_0 = 0;
        for(int j =1; j<=col; j++)
        {
            if(a[i][j] == 0)
            {
                cout_0++;
            }
        }
        //cout<<"Count the Number 0 in Row ("<<i<<") : "<<setw(5)<<cout_0<<endl;
        float Idf_i = log10((float)n/((float)(n-cout_0)));
        Idf[i] = Roundf(Idf_i,2);
    }
}
void Arrays_Idf_Output()
{
    cout<<endl;
    for(int i=1; i<=row; i++)
    {
        cout<<setw(8)<<"Idf("<<i<<") = "<<Idf[i];
    }
}
/**
    Trọng số (FD) của FT (Frequency_Table) được tính dưới dạng
    CT : FD(i,j) = FT(i,j) * Idf(i)
*/
void Frequency_Distribution() ///Phân phối tần số
{
    for(int i=1; i<=row; i++)
    {
        for(int j =1; j<=col; j++)
        {
            float Fre_Dis = (float)(a[i][j] * Idf[i]);
            a[i][j] = Roundf(Fre_Dis,2);
        }
    }
}
/**
   Biểu diễn FILE VĂN BẢN dưới dạng Vertor D với
   CT : D(j) = ( FD(1,j); FD(2,j); ... ; FD(col,j))
*/
void Frequency_Distribution_Vertor()
{
    for(int j=1; j<col; j++) /// không biểu diễn Vector Q
    {
        //cout<<"Vector D ("<<j<<") : "<<endl;
        for(int i =1; i<=row; i++)
        {
            cout<<setw(10)<<a[i][j];
        }
        cout<<endl<<endl;
    }
}
/// Biểu diễn Vector Q
void Frequency_Distribution_VertorQ()
{
    //cout<<"Vector Q : "<<endl;
    for(int i =1; i<=row; i++)
    {
        cout<<setw(10)<<a[i][col];
    }
    cout<<endl<<endl;
}
/// Processing Inverted File
/**
    So sánh khoảng cách giữa 2 Vector >> 0 thì càng đúng
    CT Khoảng cách Cosine = 1 - S(Q,Di) >> 0 : True
    Trong đó :
        S(Qi,Di) = Tích vô hướng 2 Vector (Q x Di) / Tích độ dài 2 Vector |Q| x |Di|
*/

float *Cosine = new float[cout_D];
void Inverted_File()
{
    for(int j = 1; j<col; j++)
    {
        //cout<<"j = "<<j<<endl;
        float sum_QxDi = 0; /// Tính tích vô hướng của Vertor Q x vector Di
        float sum_Q = 0; /// Tính bình phương của Vertor Q
        float sum_Di = 0; /// Tính bình phương của Vertor Di
        for(int i=1 ; i<=row; i++)
        {
            //cout<<" i = "<<i<<endl;
            sum_QxDi = sum_QxDi + a[i][j]*a[i][col];
            //cout<<"\t"<<a[i][j]<<" x "<<a[i][col]<<" = "<<sum_QxDi<<endl;
            sum_Di = sum_Di + a[i][j]*a[i][j];
            //cout<<"\t"<<a[i][j]<<" x "<<a[i][j]<<" = "<<sum_Di<<endl;
            sum_Q = sum_Q + a[i][col]*a[i][col];
            //cout<<"\t"<<a[i][col]<<" x "<<a[i][col]<<" = "<<sum_Q<<endl;
        }
        //cout<<sum_QxDi<<endl;
        //cout<<sum_Di<<endl;
        //cout<<sum_Q<<endl;
        float Cosine_i = (float)(1 - (sum_QxDi/(sqrt(sum_Q*sum_Di))));
        Cosine[j] = Roundf(Cosine_i,2);
        //cout<<Cosine[j]<<endl<<endl;
    }
}
void Output_Cosine()
{
    for(int j=1; j<=cout_D; j++)
    {
        cout<<setw(6)<<"D("<<j<<") = "<<Cosine[j];
    }
    cout<<endl;
}

/**
For example :
   Tham số :        5   7   1   3   9

   Vị trí arr :     1   2   3   4   5

                    1   2   -1  4   5
                    1   2   -1  -1  5
                    -1  2   -1  -1  5
                    -1  -1  -1  -1  5
                    -1  -1  -1  -1  -1

   result vị trí:   3   4   1   2   5
------------------------------------------------------------
   0.77      0.32      0.28       0.3      0.88      0.41
   0.77      0.32      -1       0.3      0.88      0.41
   0.77      0.32      -1       -1      0.88      0.41
   0.77      -1      -1       -1      0.88      0.41
   0.77      -1      -1       -1      0.88      -1
   -1      -1      -1       -1      0.88      -1
   -1      -1      -1       -1      -1      -1

   result :     3   4   2   6   1   5
*/
void Resulf_Cosine()
{
    cout<<endl<<"Result Cosine (D,Qi) : "<<endl;
    int i = 1;
    while(i<=cout_D)
    {
        if(Cosine[i] != -1)
        {
            int mi = i;
            for(int j=1; j<=cout_D; j++)
            {
                if(Cosine[j] != -1 && Cosine[j] < Cosine[mi])
                {
                    mi = j;
                }
            }
            Cosine[mi] = -1;
            i = 1;
            //Output_Cosine();
            cout<<setw(10)<<"D ("<<mi<<")";
            //cout<<endl;
        }
        else
            i++;
    }
    cout<<endl;
}
int main()
{
    freopen("Data_IF.txt","r",stdin);
    //freopen("Output_IF.txt","w",stdout);
    cout << "\tInverted File by Manh Quang"<<endl<<endl;
    Input_data();
    cout<<"Input Data"<<endl;
    Output_data();
    //cout<<"\nFrequency Table"<<endl;
    //Arrays_Sum_Col();
    //Frequency_Table();
    //Output_data();
    cout<<"\nInverse Document Frequency"<<endl;
    Arrays_Idf_Input();
    Arrays_Idf_Output();
    cout<<"\n\nFrequency Distribution"<<endl;
    Frequency_Distribution();
    Output_data();
    cout<<"\nFrequency Distribution Vector"<<endl<<endl;
    Frequency_Distribution_Vertor();
    Frequency_Distribution_VertorQ();
    cout<<"Inverted File"<<endl;
    Inverted_File();
    cout<<endl<<"Cosine D and Qi : "<<endl;
    Output_Cosine();
    Resulf_Cosine();
    return 0;
}
