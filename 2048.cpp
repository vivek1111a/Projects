#include<iostream>
#include<cstdlib>
using namespace std;

int length(int n){
    int k=0;
    if(n==0) return 1;
    while(n){
        k++;
        n=n/10;
    }
    return k;
}
class game{
    public:
    int arr[4][4];
    game(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                arr[i][j]=0;
            }
        }
    }
    void display(){
            int len[4]={0};
        for(int column=0;column<4;column++){
        for(int i=0;i<4;i++){
            len[column]=max(len[column],length(arr[i][column]));
        }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int newsp=len[j]-length(arr[i][j])+1;
                while(newsp--)
                {
                    cout<<" ";
                }
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
    int score(){
        int count=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                count+=arr[i][j];
            }
        }
        return count;
    }
    bool valid(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(arr[i][j]!=0){return true;}
            }
        }
        return false;
    }
     bool validmoveing(game gm){
        bool value=true;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                value=value&&(arr[i][j]==gm.arr[i][j]);
            }
        }
        return value;
       }
     void copy(game gm){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                arr[i][j]=gm.arr[i][j];
            }
        }
     }
    
};


void info();
void run(string n);
void compress(game*& gm,char ch);
void add(game*& gm,char ch);
void clearScreen();
void insert(game* &gm);
void switchcase2(int* &n2,int* &n1);
void switchcase3(int* &n3,int* &n2,int* &n1);
void switchcase4(int* &n4,int* &n3,int* &n2,int* &n1);


int main(){
    cout<<"hi, what is your name?"<<endl;
    string n;
    cin>>n;
    cout<<"1)start\n2)information\n3)exit\n";
    char ch;
    cin>>ch;
    switch (ch)
    {
    case '1':
         run(n);
        break;
        
    case '2':
         info();
        break;
        
    case '3':
         return 0;
        break;
    
    default:
        break;
    }
    return 0;
}

void run(string n){
     bool flag=true;
     game gm;
     game gemoobj;
     gemoobj.arr[0][0]=5;
     game* gemo=&gemoobj;
     while(flag){
        game* gmm=&gm;
        if(!(gmm->validmoveing(*gemo))){insert(gmm);}
        gemoobj.copy(gm);
        gm.display();
        gm.score();
        cout<<"your score is - "<<gm.score()<<"\n give me direction"<<endl;
        char cha;
        cin>>cha;
        compress(gmm,cha);
        add(gmm,cha);
        compress(gmm,cha);
        clearScreen();
        flag =gm.valid();
     }
     cout<<n<<"your game is over.\n your score is:      "<<gm.score()<<endl;
}

void insert(game* &gm){
    int i=rand()%4;
    int j=rand()%4;
    if(gm->arr[i][j]==0){
        int addit=rand()%4;
        if(addit){
        gm->arr[i][j]=2;}
        else{
          gm->arr[i][j]=4;  
        }
    }
    else{insert(gm);}
}

void compress(game* &gm,char ch){
    switch (ch)
    {
    case 'd':
         for(int i=0;i<4;i++){
            int* ptr4=&gm->arr[i][3];int* ptr3=&gm->arr[i][2];int* ptr2=&gm->arr[i][1];int* ptr1=&gm->arr[i][0];
            switchcase4(ptr4,ptr3,ptr2,ptr1);
         }
        break;
    case 'a':
         for(int i=0;i<4;i++){
            int* ptr4=&gm->arr[i][3];int* ptr3=&gm->arr[i][2];int* ptr2=&gm->arr[i][1];int* ptr1=&gm->arr[i][0];
            switchcase4(ptr1,ptr2,ptr3,ptr4);
         }
        break;
    case 's':
         for(int i=0;i<4;i++){
            int* ptr4=&gm->arr[3][i];int* ptr3=&gm->arr[2][i];int* ptr2=&gm->arr[1][i];int* ptr1=&gm->arr[0][i];
            switchcase4(ptr4,ptr3,ptr2,ptr1);
         }
        break;
    case 'w':
         for(int i=0;i<4;i++){
            int* ptr4=&gm->arr[3][i];int* ptr3=&gm->arr[2][i];int* ptr2=&gm->arr[1][i];int* ptr1=&gm->arr[0][i];
            switchcase4(ptr1,ptr2,ptr3,ptr4);
         }
        break;
        break;
    default:
        break;
    }
}
void switchcase2(int* &n1,int* &n2){
    if(*n1==0){
        int temp=*n1;
        *n1=*n2;
        *n2=temp;
    }
}
void switchcase3(int* &n3,int* &n2,int* &n1){
    if(*n3==0){switchcase2(n3,n2);if(*n3==0){switchcase2(n3,n1);};}
    if(*n3!=0){switchcase2(n2,n1);}
}
void switchcase4(int* &n4,int* &n3,int* &n2,int* &n1){
      if(*n4==0){switchcase3(n4,n3,n2);if(*n4==0){switchcase2(n4,n1);};}
     if(*n4!=0){switchcase3(n3,n2,n1);}
}

void add2(int* n2,int* n1){
    if(*n1==*n2){
        *n2+=*n2;
        *n1=0;
    }
}
void add(game* & gm,char ch){
     switch (ch)
     {
     case 'd':
         for(int i=0;i<4;i++){
            int* ptr4=&gm->arr[i][3];int* ptr3=&gm->arr[i][2];int* ptr2=&gm->arr[i][1];int* ptr1=&gm->arr[i][0];
            add2(ptr4,ptr3);add2(ptr3,ptr2);add2(ptr2,ptr1);
         }
        break;
    case 'a':
         for(int i=0;i<4;i++){
            int* ptr4=&gm->arr[i][3];int* ptr3=&gm->arr[i][2];int* ptr2=&gm->arr[i][1];int* ptr1=&gm->arr[i][0];
            add2(ptr1,ptr2);add2(ptr2,ptr3);add2(ptr3,ptr4);
         }
        break;
    case 's':
         for(int i=0;i<4;i++){
            int* ptr4=&gm->arr[3][i];int* ptr3=&gm->arr[2][i];int* ptr2=&gm->arr[1][i];int* ptr1=&gm->arr[0][i];
            add2(ptr4,ptr3);add2(ptr3,ptr2);add2(ptr2,ptr1);
         }
        break;
    case 'w':
         for(int i=0;i<4;i++){
            int* ptr4=&gm->arr[3][i];int* ptr3=&gm->arr[2][i];int* ptr2=&gm->arr[1][i];int* ptr1=&gm->arr[0][i];
            add2(ptr1,ptr2);add2(ptr2,ptr3);add2(ptr3,ptr4);
         }
        break;
        break;
     default:
        break;
     }
}

void info(){
    cout<<"don't come here you dumb"<<endl;
    char chhh;
    cin>>chhh;
    main();
}

void clearScreen() {
    system("cls");
}