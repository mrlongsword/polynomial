# include<iostream>
#define buff 10
using namespace std;
int main()
{
    double arr1[buff] = {0}; //被除式
    double arr2[buff] = {0}; //除式
    double arr3[buff] = {0}; //商
    double arr4[buff] = {0}; //餘式

    int p;//被除式最高次
    int q;//除式最高次


    cout << "被除式最高次:";
    cin >>p;
    cout<< "除式最高次:";
    cin>>q;
    int sp = p+1; //number of non zero tokens in arr1[]

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


    for(int i=0; i<buff; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<buff; i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    double c = arr2[0];
    int counter = 0;

    for(int i = 0; i<buff; i++,sp--)
    {
        cout<<"sp:"<<sp<<endl;
        if(sp < (q+1))
        {
            cout<<"Done\n";
            break;
        }

        double mult = arr1[i]/c;
        arr3[i] = mult;
        counter ++;
        for(int j=0; j<(q+1); j++)
        {
            arr1[i+j]=arr1[i+j]-(arr2[j]*mult);
        }

        cout<<"c:"<<c<<endl;
        cout<<"mult:"<<mult<<endl;
        cout<<"arr1[] now:"<<endl;
        for(int z=0; z<buff; z++)
            cout<<arr1[z]<<" ";
        cout<<endl;

    }


    cout<<"商:";
    for(int i=0; i<buff; i++)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<endl;

    cout<<"餘式:";
    for(int i=0; i<buff; i++)
    {
        cout<<arr1[i]<<" ";
    }

    cout<<endl;

}
