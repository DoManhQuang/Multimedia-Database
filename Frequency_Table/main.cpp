#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int col;
int row;
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
    for(int i=1;i<=row;i++)
    {
        for(int j =1;j<=col;j++)
        {
            cin>>a[i][j];
        }
    }
}
void Output_data()
{
    for(int i=1;i<=row;i++)
    {
        for(int j =1;j<=col;j++)
        {
            cout<<setw(10)<<a[i][j];
        }
        cout<<endl;
    }
}
/// Làm tròn Số Thực
double Roundf(double Real_Numbers , int result_Round)
{
    int Decimal_Number = 1;
    for(int i=1;i<=result_Round; i++)
    {
        Decimal_Number = Decimal_Number *10;
    }
    return roundf(Real_Numbers*Decimal_Number)/Decimal_Number;
}

/**
    Chuẩn hóa về bảng tần số a[i][j] = a[i][j] / sum (a[1->col][j])
*/
int *Sum_col;
void Arrays_Sum_Col()
{
    Sum_col = new int [col];
    for(int j=1;j<=col;j++)
    {
        int sum = 0;
        for(int i =1;i<=row;i++)
        {
            sum = sum + a[i][j];
        }
        Sum_col[j] = sum;
    }
}
void Frequency_Table()
{
    for(int i=1;i<=row;i++)
    {
        for(int j =1;j<=col;j++)
        {
           float Fre_Tab = (float)(a[i][j]/Sum_col[j]);
           a[i][j] = Roundf(Fre_Tab , 2);
        }
    }
}

/**
    Idf (inverse document frequency) xác định độ quan trọng của
    các phần tử trong tập dự liệu văn bản CT : idf(i) = log(N/df(i))
    Trong đó :
    df(i) là số văn bản có chứa từ t(i)
    N là tổng số văn bản trong tập dữ liệu N = col
*/
float *Idf = new float [row];
void Arrays_Idf_Input()
{
    cout<<endl;
    int n = col;
    for(int i=1;i<=row;i++)
    {
        int cout_0 = 0;
        for(int j =1;j<=col;j++)
        {
            if(a[i][j] == 0)
            {
                cout_0++;
            }
        }
        cout<<"Count the Number 0 in Row ("<<i<<") : "<<setw(6)<<cout_0<<endl;
        float Idf_i = log10((float)n/((float)(n-cout_0)));
        Idf[i] = Roundf(Idf_i,2);
    }
}
void Arrays_Idf_Output()
{
    cout<<endl;
    for(int i=1;i<=row;i++)
        {
            cout<<setw(10)<<"Idf("<<i<<") = "<<Idf[i];
        }
}
/**
    Trọng số (FD) của FT (Frequency_Table) được tính dưới dạng
    CT : FD(i,j) = FT(i,j) * Idf(i)
*/
void Frequency_Distribution()
{
    for(int i=1;i<=row;i++)
    {
        for(int j =1;j<=col;j++)
        {
            float Fre_Dis = (float)(a[i][j] * Idf[i]);
            a[i][j] = Roundf(Fre_Dis,2);
        }
    }
}
/**
   Biểu diễn FT dưới dạng Vertor với
   CT : Vector FT(j) = ( FD(1,j); FD(2,j); ... ; FD(col,j))
*/
void Frequency_Distribution_Vertor()
{
    for(int j=1;j<=col;j++)
    {
        cout<<"Vector FT("<<j<<") : "<<endl;
        for(int i =1;i<=row;i++)
        {
            cout<<setw(10)<<a[i][j];
        }
        cout<<endl<<endl;
    }
}
int main()
{
    cout << "\tFrequency Table by Manh Quang"<<endl<<endl;
    freopen("Input_Data.txt","r",stdin);
    freopen("Output_Data.txt","w",stdout);
    cout<<"Input Data"<<endl;
    Input_data();
    Output_data();
    cout<<"\nFrequency Table"<<endl;
    Arrays_Sum_Col();
    Frequency_Table();
    Output_data();
    cout<<"\nInverse Document Frequency"<<endl;
    Arrays_Idf_Input();
    Arrays_Idf_Output();
    cout<<"\n\nFrequency Distribution"<<endl;
    Frequency_Distribution();
    Output_data();
    cout<<"\nFrequency Distribution Vector"<<endl<<endl;
    Frequency_Distribution_Vertor();
    return 0;
}












