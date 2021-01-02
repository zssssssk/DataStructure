#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
#include<conio.h>


using namespace std;

void create();
void showmenu1();

struct Trituple
{
    int row,col;
    int val;
};

class SparseMatrix
{
public:
    SparseMatrix(int maxt=100)
    {
        maxterms=maxt;
    };
    ~SparseMatrix()
    {
        rows=0;
        cols=0;
        terms=0;
        maxterms=0;
        data=NULL;
    };
    bool TransposeTo(SparseMatrix &);
    void Output();
    void Create();
    int GetTerms();
    void Output1();
    int Getmaxterms();
    void clearz();
    void input();
    void Getelem();
    void Setelem();

private:
    Trituple *data;
    int rows,cols,terms;
    int maxterms;

};

void SparseMatrix::Setelem()
{
    int r,c,v;
    cout<<"Please input the row number:";
    cin>>r;
    cout<<"Please input the column number:";
    cin>>c;
    cout<<"Please input the values to be set:";
    cin>>v;
    cout<<"The element "<<v<<" is set successfully."<<endl;
    terms++;
    Trituple *b;
    b=new Trituple[terms];
    for(int i=0;i<terms;i++)
    {
        if(i!=terms-1)
        {
            b[i]=data[i];
        }
        else
        {
            b[i].row=r;
            b[i].col=c;
            b[i].val=v;
        }
    }
    delete[] data;
    data = new Trituple[terms]; 
     for(int i=0;i<terms;i++)
    {
        
            data[i]=b[i];
      }
        
    delete[] b;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<terms;j++)
        {
            int m=(data[j].row)*10+(data[j].col);
            if(m==i)
            {
                cout<<data[j].val<<"  ";
                break;
            }
            else if(j==terms-1)
                cout<<"0  ";
        }
        if(terms==0)
            cout<<"0  ";


        if((i+1)%rows==0)
            {
                cout<<endl;
                cout<<endl;
            }
    }

        cout<<"Press any key to return to the menu."<<endl;
        getch();

}

void SparseMatrix::Getelem()
{
    int r,c;
    cout<<"Please input the row number:";
    cin>>r;
    cout<<"Please input the column number:";
    cin>>c;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<terms;j++)
        {
            int m=(data[j].row)*10+(data[j].col);
            if(m==i)
            {
                cout<<data[j].val<<"  ";
                break;
            }
            else if(j==terms-1)
                cout<<"0  ";
        }
        if(terms==0)
            cout<<"0  ";


        if((i+1)%rows==0)
            {
                cout<<endl;
                cout<<endl;
            }
    }
     for(int j=0;j<terms;j++)
        {
            if(data[j].row==r&&data[j].col==c)
            {
                cout<<"The element is:"<<data[j].val<<endl;
                break;
            }
            else if(j==terms-1)
                cout<<"The element is:"<<"0"<<endl;
        }
        cout<<"Press any key to return to the menu."<<endl;
        getch();

}

void SparseMatrix::input()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<terms;j++)
        {
            int m=(data[j].row)*10+(data[j].col);
            if(m==i)
            {
                cout<<data[j].val<<"  ";
                break;
            }
            else if(j==terms-1)
                cout<<"0  ";
        }
        if(terms==0)
            cout<<"0  ";


        if((i+1)%rows==0)
            {
                cout<<endl;
                cout<<endl;
            }
    }
    int n;
    cout<<"Please input the number of the None Zero Elements:";
    cin>>n;
    terms=n;
    for(int i=0;i<n;i++)
    {
        data=new Trituple[terms];

        for(int i=0;i<terms;i++)
        {
            data[i].row=rand()%10;
            data[i].col=rand()%10;
            data[i].val=rand()%9+1;
        }
    }
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<terms;j++)
        {
            int m=(data[j].row)*10+(data[j].col);
            if(m==i)
            {
                cout<<data[j].val<<"  ";
                break;
            }
            else if(j==terms-1)
                cout<<"0  ";
        }
        if(terms==0)
            cout<<"0  ";


        if((i+1)%rows==0)
            {
                cout<<endl;
                cout<<endl;
            }
    }
    double f,c;
    f=n*100/maxterms;
    c=(maxterms-terms*3)*100/maxterms;
    cout<<"The Total Element of the Sparse Matrix is:"<<maxterms<<endl;
    cout<<"Amount of None Zero Elements of the Sparse Matrix is :"<<terms<<endl;
    cout<<"The Sparse Factor of the Sparse Matrix is:"<<f<<"%"<<endl;
    cout<<"The Compression Ratio of the Triangular Matrix is:"<<c<<"%"<<endl;
    cout<<"Press any key to return to the menu."<<endl;
    getch();
}

void SparseMatrix::clearz()
{
    	
    cout<<"The None Zero Elements have been cleared."<<endl;
    if(data!=NULL)
    {
    	
    
    delete[] data;
    terms=0;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<terms;j++)
        {
            int m=(data[j].row)*10+(data[j].col);
            if(m==i)
            {
                cout<<data[j].val<<"  ";
                break;
            }
            else if(j==terms-1)
                cout<<"0  ";
        }
        if(terms==0)
            cout<<"0  ";


        if((i+1)%rows==0)
            {
                cout<<endl;
                cout<<endl;
            }
    }
}
    cout<<"The Total Element of the Sparse Matrix is:"<<maxterms<<endl;
    cout<<"Amount of None Zero Elements of the Sparse Matrix is :"<<terms<<endl;
    cout<<"The Sparse Factor of the Sparse Matrix is:0%"<<endl;
    cout<<"The Compression Ratio of the Triangular Matrix is:100%"<<endl;
    cout<<"Press any key to return to the menu."<<endl;
    getch();
    

}

void SparseMatrix::Output1()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<terms;j++)
        {
            int m=(data[j].row)*10+(data[j].col);
            if(m==i)
            {
                cout<<data[j].val<<"  ";
                break;
            }
            else if(j==terms-1)
                cout<<"0  ";
        }
        if(terms==0)
            cout<<"0  ";


        if((i+1)%rows==0)
            {
                cout<<endl;
                cout<<endl;
            }
    }
    cout<<"The None Zero Elements of the Sparse Matrix are:"<<endl;
    cout<<"Row:";
    for(int i=0;i<terms;i++)
    {
        cout<<" "<<data[i].row;
    }
    cout<<endl;
    cout<<"Col:";
    for(int i=0;i<terms;i++)
    {
        cout<<" "<<data[i].col;
    }
    cout<<endl;
    cout<<"Val:";
    for(int i=0;i<terms;i++)
    {
        cout<<" "<<data[i].val;
    }
    cout<<endl;
    cout<<"Press any key to return to the menu."<<endl;
    getch();
}

void SparseMatrix::Output()
{
    cout<<"The status of the Sparse Matrix is:"<<endl;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<terms;j++)
        {
            int m=(data[j].row)*10+(data[j].col);
            if(m==i)
            {
                cout<<data[j].val<<"  ";
                break;
            }
            else if(j==terms-1)
                cout<<"0  ";
        }
        if(terms==0)
            cout<<"0  ";


        if((i+1)%rows==0)
            {
                cout<<endl;
                cout<<endl;
            }
    }
    double f,c;
    f=terms*100/maxterms;
    c=(maxterms-terms*3)*100/maxterms;
    cout<<"The Total Element of the Sparse Matrix is:"<<maxterms<<endl;
    cout<<"Amount of None Zero Elements of the Sparse Matrix is :"<<terms<<endl;
    cout<<"The Sparse Factor of the Sparse Matrix is:"<<f<<"%"<<endl;
    cout<<"The Compression Ratio of the Triangular Matrix is:"<<c<<"%"<<endl;
    cout<<"Press any key to return to the menu."<<endl;
    cout<<"Press any key to return to the menu."<<endl;
    getch();
}

int SparseMatrix::GetTerms()
{
    return terms;
}

int SparseMatrix::Getmaxterms()
{
    return maxterms;
}

bool SparseMatrix::TransposeTo(SparseMatrix &B)
{
    cout<<"The Original Sparse Matrix is:"<<endl;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<terms;j++)
        {
            int m=(data[j].row)*10+(data[j].col);
            if(m==i)
            {
                cout<<data[j].val<<"  ";
                break;
            }
            else if(j==terms-1)
                cout<<"0  ";
        }
        if(terms==0)
            cout<<"0  ";


        if((i+1)%rows==0)
            {
                cout<<endl;
                cout<<endl;
            }
    }
    cout<<"Row:";
    for(int i=0;i<terms;i++)
    {
        cout<<" "<<data[i].row;
    }
    cout<<endl;
    cout<<"Col:";
    for(int i=0;i<terms;i++)
    {
        cout<<" "<<data[i].col;
    }
    cout<<endl;
    cout<<"Val:";
    for(int i=0;i<terms;i++)
    {
        cout<<" "<<data[i].val;
    }

    B.rows=cols;
    B.cols=rows;
    B.terms=terms;
    if(terms>0)
    {
        B.data=new Trituple[terms];
        int p=0;
        for(int j=0;j<cols;j++)
            for(int k=0;k<terms;k++)
        {
            if(data[k].col==j)
            {
                B.data[p].row=j;
                B.data[p].col=data[k].row;
                B.data[p].val=data[k].val;
                if(p<terms)
                p++;
            }
        }
        data=B.data;
    }
    cout<<endl;

    return true;
}

void SparseMatrix::Create()
{
    cols=10;
    rows=10;
    maxterms=100;
    srand(time(NULL));
    int m=rand()%10;
    terms=m+1;
    data=new Trituple[terms];

    for(int i=0;i<m+1;i++)
    {
        data[i].row=rand()%10;
        data[i].col=rand()%10;
        data[i].val=rand()%9+1;
    }


    for(int i=0;i<100;i++)
    {
        for(int j=0;j<terms;j++)
        {
            int m=data[j].row*10+(data[j].col);
            if(m==i)
            {
                cout<<data[j].val<<"  ";
                break;
            }
            else if(j==terms-1)
                cout<<"0  ";
        }


        if((i+1)%rows==0)
            {
                cout<<endl;
                cout<<endl;
            }
    }

}

void showmenu1()
{
	cout<<"***************************************************************"<<endl;
	cout<<"*    1.Create Sparse Matrix     2.Show Matrix Status          *"<<endl;
	cout<<"*                                                             *"<<endl;
	cout<<"*    3.Show None Zero Triples   4.Clear Matrix                *"<<endl;
	cout<<"*                                                             *"<<endl;
	cout<<"*    5.Clear None Zero Elements 6.Set Random Values           *"<<endl;
	cout<<"*                                                             *"<<endl;
	cout<<"*    7.Get Element              8.Set Element                 *"<<endl;
	cout<<"*                                                             *"<<endl;
	cout<<"*    9.Transpose of Matrix      10.exit<0 for Chinese Menu>   *"<<endl;
	cout<<"*                                                             *"<<endl;
	cout<<"*                                                             *"<<endl;
	cout<<"***************************************************************"<<endl;
}

void showmenu()
{
      cout<<"                   zzzzzzzzzzz                               "<<endl; 
	cout<<"    1.创建稀疏矩阵           2.显示稀疏矩阵                  "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"    3.显示非零三元组表       4.置空稀疏矩阵                  "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"    5.清空非零值             6.设置非零随机值                "<<endl;
	cout<<"                                                            "<<endl;
	cout<<"    7.获取矩阵元素           8.设置矩阵元素值                "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"    9.矩阵转置               10.退出<按0显示英文菜单>        "<<endl;

}

SparseMatrix a;
SparseMatrix b;

int main(){
	system("color 3f");
	int flag=1;



	int choice=1;
	while(choice!=16)
	{
	    if(flag==1)
		    showmenu();
        else
        {
             showmenu1();
        }
		cout<<"\n请选择：";
		while(!(cin>>choice)||(choice<0)||(choice>16))
		{
			cout<<"输入错误，请重新输入：";
			cin.clear();
			cin.sync();
		}
		switch(choice){
		    case 0:
				cout<<"you select 0..."<<endl;
				flag=-flag;

				break;
			case 1:
				cout<<"you select 1..."<<endl;
				create();
				break;
			case 2:
				cout<<"you select 2..."<<endl;
				a.Output();
				break;
            case 3:
				cout<<"you select 3..."<<endl;
				a.Output1();
				break;
            case 4:
				cout<<"you select 4..."<<endl;
				a.~SparseMatrix();
				cout<<"The Sparse Matrix has been cleared."<<endl;
				cout<<"The Total Element of the Sparse Matrix is:"<<a.Getmaxterms()<<endl;
				cout<<"Amount of None Zero Elements of the Sparse Matrix is :"<<a.GetTerms()<<endl;
				cout<<"Press any key to return to the menu."<<endl;
                getch();
				break;
            case 5:
				cout<<"you select 5..."<<endl;
				a.clearz();

				break;

            case 6:
				cout<<"you select 6..."<<endl;
				a.input();


				break;
            case 7:
				cout<<"you select 7..."<<endl;
				a.Getelem();


				break;
            case 8:
				cout<<"you select 8..."<<endl;
				a.Setelem();
				break;
            case 9:
				cout<<"you select 9..."<<endl;
				a.TransposeTo(b);

				cout<<"The Transposed Sparse Matrix is:"<<endl;
				a.Output1();
				b.~SparseMatrix();
				break;

			case 10:
				cout<<"you select 10..."<<endl;
				cout<<"good bye"<<endl;
				return 0;
				break;
			default:
				cout<<"valid input."<<endl;
				break;
		}
	}
	return 0;
}



void create()
{

    cout<<"Sparse Matrix has been created with random rows/cols/values:"<<endl;
    cout<<endl;
    a.Create();
    cout<<"Press any key to return to the menu."<<endl;
    getch();

}
