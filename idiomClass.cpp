#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

void idiomsolitaire();
void showmenu();
void showmenu1();
void dog();
struct letter{
	char a[16];
	int b;
};
class idiomApp
{
    private:
      string idi;
      ifstream ip;
      int flag;
    public:
      void IdiomsSolitaire();
      void IdiomsSearch(string);
};
void idiomApp::IdiomsSolitaire()
{
    string x;
    string loser="������";
    int end=1;
    int z;
    while(end)
    {
        cout<<"��������ĳ���"<<endl;
		cin>>x;
        z=0;
        for(int i=0;x[i]!='\0';i++)
        {
            z++;
        }
        ip.clear();
        ip.open("idiom.txt");
        if(x==loser)
        {
            cout<<"                  �� ";
			Sleep(100);
			cout<<"�� ";
			Sleep(100);
			cout<<"һ ";
			Sleep(100);
			cout<<"�� \n";
			Sleep(500);
			cout<<"                  ��";
			Sleep(100);
			cout<<"ǿ";
			Sleep(100);
			cout<<"��"<<endl;
			Sleep(500);
			cout<<"                  ��";
			Sleep(100);
			cout<<"��";
			Sleep(100);
			cout<<"��"<<endl;
            dog();
            ip.close();
            break;
        }
        if(!ip) cout<<"ip.open error"<<endl;
        ip>>idi>>flag;
        while(flag==0)
        {
            if(idi[0]==x[z-2]&&idi[1]==x[z-1])
            {
                cout<<idi<<endl;
                flag=0;
                break;
            }
            ip>>idi>>flag;
        }
        if(flag==1)
        {
            cout<<"��Ӯ�ˣ��ǣ�1����0��������"<<endl;
			cin>>end;
        }
        ip.close();
    }
}

void idiomApp::IdiomsSearch(string s)
{
    ip.clear();
    ip.open("idiomsearch");
    if(!ip) cout<<"ip.open error"<<endl;
    

}

















void dog()
{
 cout<<"                        ::"<<endl;
 cout<<"                       :;J7, :,                        ::;7:"<<endl;
 cout<<"                       ,ivYi, ,                       ;LLLFS:"<<endl;
 cout<<"                       :iv7Yi                       :7ri;j5PL"<<endl;
 cout<<"                      ,:ivYLvr                    ,ivrrirrY2X,"<<endl;
 cout<<"                      :;r@Wwz.7r:                :ivu@kexianli."<<endl;
 cout<<"                     :iL7::,:::iiirii:ii;::::,,irvF7rvvLujL7ur"<<endl;
 cout<<"                    ri::,:,::i:iiiiiii:i:irrv177JX7rYXqZEkvv17"<<endl;
 cout<<"                 ;i:, , ::::iirrririi:i:::iiir2XXvii;L8OGJr71i"<<endl;
 cout<<"               :,, ,,:   ,::ir@mingyi.irii:i:::j1jri7ZBOS7ivv,"<<endl;
 cout<<"                  ,::,    ::rv77iiiriii:iii:i::,rvLq@huhao.Li"<<endl;
 cout<<"              ,,      ,, ,:ir7ir::,:::i;ir:::i:i::rSGGYri712:"<<endl;
 cout<<"            :::  ,v7r:: ::rrv77:, ,, ,:i7rrii:::::, ir7ri7Lri"<<endl;
 cout<<"           ,     2OBBOi,iiir;r::        ,irriiii::,, ,iv7Luur:"<<endl;
 cout<<"         ,,     i78MBBi,:,:::,:,  :7FSL: ,iriii:::i::,,:rLqXv::"<<endl;
 cout<<"         :      iuMMP: :,:::,:ii;2GY7OBB0viiii:i:iii:i:::iJqL;::"<<endl;
 cout<<"        ,     ::::i   ,,,,, ::LuBBu BBBBBErii:i:i:i:i:i:i:r77ii"<<endl;
 cout<<"       ,       :       , ,,:::rruBZ1MBBqi, :,,,:::,::::::iiriri:"<<endl;
 cout<<"      ,               ,,,,::::i:  @arqiao.       ,:,, ,:::ii;i7:"<<endl;
 cout<<"     :,       rjujLYLi   ,,:::::,:::::::::,,   ,:i,:,,,,,::i:iii"<<endl;
 cout<<"     ::      BBBBBBBBB0,    ,,::: , ,:::::: ,      ,,,, ,,:::::::"<<endl;
 cout<<"     i,  ,  ,8BMMBBBBBBi     ,,:,,     ,,, , ,   , , , :,::ii::i::"<<endl;
 cout<<"     :      iZMOMOMBBM2::::::::::,,,,     ,,,,,,:,,,::::i:irr:i:::,"<<endl;
 cout<<"     i   ,,:;u0MBMOG1L:::i::::::  ,,,::,   ,,, ::::::i:i:iirii:i:i:"<<endl;
 cout<<"     :    ,iuUuuXUkFu7i:iii:i:::, :,:,: ::::::::i:i:::::iirr7iiri::"<<endl;
 cout<<"     :     :rk@Yizero.i:::::, ,:ii:::::::i:::::i::,::::iirrriiiri::,"<<endl;
 cout<<"      :      5BMBBBBBBSr:,::rv2kuii:::iii::,:i:,, , ,,:,:i@petermu.,"<<endl;
 cout<<"           , :r50EZ8MBBBBGOBBBZP7::::i::,:::::,: :,:,::i;rrririiii::"<<endl;
 cout<<"               :jujYY7LS0ujJL7r::,::i::,::::::::::::::iirirrrrrrr:ii:"<<endl;
 cout<<"            ,:  :@kevensun.:,:,,,::::i:i:::::,,::::::iir;ii;7v77;ii;i,"<<endl;
 cout<<"            ,,,     ,,:,::::::i:iiiii:i::::,, ::::iiiir@xingjief.r;7:i,"<<endl;
 cout<<"         , , ,,,:,,::::::::iiiiiiiiii:,:,:::::::::iiir;ri7vL77rrirri::"<<endl;
 cout<<"          :,, , ::::::::i:::i:::i:i::,,,,,:,::i:i:::iir;@Secbone.ii:::"<<endl;

}

idiomApp a;	

int main(){
    system("color 3f");

    int choice=1;
    int flag=1;
    while(choice!=16){
        if(flag) showmenu();
        else showmenu1();
        while(!(cin>>choice)||(choice<0)||(choice>16)){
            cout<<"����������������룺";
            cin.clear();
            cin.sync();
        }
       
        switch(choice){
            case 0:
                flag=1-flag;
                break;
            case 1:
                idiomsolitaire();
                break;
        }
    }
    return 0;
}

void showmenu()
{
    cout<<"                  ZSSSSSSK           "<<endl;
    cout<<"      1.�������              2.�����ѯ"<<endl;
    cout<<"      3.��ĳ�ֿ�ͷ�ĳ���       4.��ĳ�ֽ�β�ĳ���"<<endl;
    cout<<"      5.�麬ĳ���ֻ�ʵĳ���   6.��AABB�ͳ���"<<endl;
    cout<<"      7.��AABC�ͳ���          8.��ABAB�ͳ���"<<endl;
    cout<<"      9.��ABCC�ͳ���          10.��ABAC�ͳ���"<<endl;
    cout<<"      11.��ͷ����             12.��β����"<<endl;
    cout<<"      13.�Զ������������̣�  14.�Զ�������������"<<endl;
    cout<<"      15.�����             16.�˳���0�л�Ӣ�Ĳ˵���"<<endl;
}

void showmenu1()
{
    cout<<"˧���˲���Ӣ��!��0�������˵���"<<endl;
}

void idiomsolitaire()
{
    cout<<"����:2761�����ﵼ��ɹ�"<<endl;
    a.IdiomsSolitaire();
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}


