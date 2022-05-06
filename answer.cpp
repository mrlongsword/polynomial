/**************************************************
 *  2022/5/6  wefir@ncyu.csie                     *
 *                                                *
 *      ,----..    .--.--.      ,---,    ,---,.   *
 *     /   /   \  /  /    '. ,`--.' |  ,'  .' |   *
 *    |   :     :|  :  /`. / |   :  :,---.'   |   *
 *    .   |  ;. /;  |  |--`  :   |  '|   |   .'   *
 *    .   ; /--` |  :  ;_    |   :  |:   :  |-,   *
 *    ;   | ;     \  \    `. '   '  ;:   |  ;/|   *
 *    |   : |      `----.   \|   |  ||   :   .'   *
 *    .   | '___   __ \  \  |'   :  ;|   |  |-,   *
 *    '   ; : .'| /  /`--'  /|   |  ''   :  ;/|   *
 *    '   | '/  :'--'.     / '   :  ||   |    \   *
 *    |   :    /   `--'---'  ;   |.' |   :   .'   *
 *     \   \ .'              '---'   |   | ,'     *
 *      `---`                        `----'       *
 *                                                *
 **************************************************/
#include<iostream>
#define buff 100
using namespace std;
int main()
{
    double arr1[buff] = {0}; //被除式
    double arr2[buff] = {0}; //除式
    double arr3[buff] = {0}; //商

    int p;//被除式最高次
    int q;//除式最高次


    cout << "被除式最高次:";
    cin >>p;
    cout<< "除式最高次:";
    cin>>q;
    int sp = p+1; //被除式項數
    int sp2 = p+1;//被除式項數

    /*
        先輸入被除式係數,以空格隔開,由高到低次
    */
    cout<<"輸入被除式係數,以空格隔開:";
    for(int i=0; i<(p+1); i++)
    {
        cin>>arr1[i];
    }
    cout<<"輸入除式係數,以空格隔開:";

    /*
        再輸入除式係數,以空格隔開,由高到低次
    */
    for(int i=0; i<(q+1); i++)
    {
        cin>>arr2[i];
    }

    /*
        開始做主要運算
    */

    double c = arr2[0];
    int counter = 0;

    for(int i = 0; i<buff; i++,sp--)
    {
        if(sp < (q+1))
        {
            break;
        }

        double mult = arr1[i]/c;
        arr3[i] = mult;
        counter ++;
        for(int j=0; j<(q+1); j++)
        {
            arr1[i+j]=arr1[i+j]-(arr2[j]*mult);
        }

    }

    cout<<endl;

    /*
        底下就只是處理輸出
    */
    cout<<"商:";
    bool flag1 = false;
    for(int i = 0; i<counter; i++)
    {
        if(arr3[i]!=0)
        {
            if(arr3[i] > 0)
            {
                if(flag1)
                {
                    cout<<"+ ";
                }

                cout<<arr3[i];
                flag1 = true;
                if(counter-i-1>0)
                    cout<<"x^"<<counter-i-1<<" ";

            }
            else
            {
                cout<<"-";
                if(flag1)
                    cout<<" ";
                cout<<-1*arr3[i];
                flag1=true;
                if(counter-i-1 > 0)
                    cout<<"x^"<<counter-i-1<<" ";
            }
        }
    }

    cout<<endl;

    cout<<"餘式:";
    bool flag2 = false;
    for(int i=0; i<sp2; i++)
    {
        if(arr1[i]!=0)
        {
            if(arr1[i] > 0)
            {
                if(i < sp2 && i > 0 && flag2 == true)
                    cout<<"+ ";
                cout<<arr1[i];
                flag2 = true;

                if(sp2-i-1>0)
                    cout<<"x^"<<sp2-i-1<<" ";

            }
            else
            {
                cout<<"-";
                if(flag2)
                    cout<<" ";

                cout<<(-1*arr1[i]);
                flag2=true;

                if(sp2-i-1 > 0)
                    cout<<"x^"<<sp2-i-1<<" ";
            }
        }

    }
    if(!flag2)
        cout<<0;
    cout<<endl;

}
