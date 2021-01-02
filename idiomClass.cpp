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
    string loser="我认输";
    int end=1;
    int z;
    while(end)
    {
        cout<<"请输入你的成语"<<endl;
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
            cout<<"                  放 ";
			Sleep(100);
			cout<<"你 ";
			Sleep(100);
			cout<<"一 ";
			Sleep(100);
			cout<<"马 \n";
			Sleep(500);
			cout<<"                  我";
			Sleep(100);
			cout<<"强";
			Sleep(100);
			cout<<"吧"<<endl;
			Sleep(500);
			cout<<"                  渣";
			Sleep(100);
			cout<<"渣";
			Sleep(100);
			cout<<"！"<<endl;
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
            cout<<"你赢了，是（1）否（0）继续？"<<endl;
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
            cout<<"输入错误，请重新输入：";
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
    cout<<"      1.成语接龙              2.成语查询"<<endl;
    cout<<"      3.查某字开头的成语       4.查某字结尾的成语"<<endl;
    cout<<"      5.查含某个字或词的成语   6.查AABB型成语"<<endl;
    cout<<"      7.查AABC型成语          8.查ABAB型成语"<<endl;
    cout<<"      9.查ABCC型成语          10.查ABAC型成语"<<endl;
    cout<<"      11.藏头成语             12.藏尾成语"<<endl;
    cout<<"      13.自动成语接龙（最短）  14.自动成语接龙（最长）"<<endl;
    cout<<"      15.最长接龙             16.退出（0切换英文菜单）"<<endl;
}

void showmenu1()
{
    cout<<"帅的人不用英文!（0换回主菜单）"<<endl;
}

void idiomsolitaire()
{
    cout<<"共有:2761个成语导入成功"<<endl;
    a.IdiomsSolitaire();
    cout<<"\npress any key to return to the menu"<<endl;
    getchar();getchar();
}


