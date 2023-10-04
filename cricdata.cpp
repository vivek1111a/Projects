#include<iostream>
#include<cstdlib>
using namespace std;

class batsman{
    public:
    string name;
    int ball;
    int run;
    int four;
    int six;
    batsman(){
        ball=0;
        run=0;
        four=0;
        six=0;
    }
    void info(){
        cout<<name<<" : runs - "<<run<<"   balls - "<<ball<<"   strike rate - "<<100*(float)run/ball<<"  "<<four<<"  "<<six<<endl;
    }
};

class bowler{
    public:
    string name;
    int balls;
    int runs;
    int out;
    bowler(){
        balls=0;
        runs=0;
        out=0;
    }
    void infos(){
        cout<<name<<" : R - "<<runs<<"   B - "<<balls/6<<"."<<balls%6<<"   ER - "<<(float)6*runs/balls<<"  W - "<<out<<endl;
    }
};

int main(){
    batsman team[11];
    bowler attack[11];
    cout<<"give me the first team"<<endl;
    for(int i=0;i<11;i++){
        cin>>team[i].name;
    }
    cout<<"give me the second team now"<<endl;
    for(int i=0;i<11;i++){
        cin>>attack[i].name;
    }
    cout<<"give me bowler :"<<endl;
    int now;
    cin>>now;
    cout<<"give me batsman :"<<endl;
    int sb,ob;
    cin>>sb>>ob;
    int scor=0,wicket=0,over=0;
    int free=0;
    while(over!=300){
        bool str=false;
        if(attack[now].balls%6 ==0 && attack[now].balls!=0){
            cout<<"over"<<endl;
            for(int i=0;i<11;i++){
                if(attack[i].balls){
                cout<<i<<")";    attack[i].infos();
                }
            }
            cout<<"Next bowler is:";
            cin>>now;
            int temp=sb;
            sb=ob;
            ob=temp;
        }
        int wic=sb;
        char ch;
        if(free==2){
            cout<<"give me feed of no ball:";
        }
        else if(free==1){
            cout<<"give me feeed on free hit:";
        }
        else{
        cout<<"give me live feed:";
        }
        cin>>ch;
        switch (ch)
        {
        case '4':
            team[sb].run+=4;attack[now].runs+=4;scor+=4;team[sb].four++;
            break;
        case '6':
            team[sb].run+=6;attack[now].runs+=6;scor+=6;team[sb].six++;
            break;
        case '0':
            break;
        case '2':
            team[sb].run+=2;attack[now].runs+=2;scor+=2;
            break;
        case '1':
            team[sb].run+=1;attack[now].runs+=1;scor+=1;
            str=true;
            break;
        case '3':
            team[sb].run+=3;attack[now].runs+=3;scor+=3;
            str=true;
            break;
        case '5':
          team[sb].ball--;attack[now].balls--;over--;scor+=5;attack[now].runs+=5;
          break;
        case 'w':
            cout<<"IT'S wicket:"<<endl<<"give me next batsman:";
            cin>>wic;
            cout<<"is that run out?  y:n"<<endl;
            char k;
            cin>>k;
            if(k=='y'){
                cout<<"strike was changed?   y:n"<<endl;
                char te;
                cin>>te;
                if(te=='y'){
                    str=true;
                }
            }
            if(k=='n'){
            attack[now].out++;}
            wicket++;
            break;
        case 'd':
            attack[now].balls--;attack[now].runs++;scor++;team[sb].ball--;over--;
            break;
        case 'n':
            free=3;
            break;
        case 'l':
            cout<<"give me runs on leg bye:";
            char chh;
            cin>>chh;
            switch (chh)
            {
            case '4':
                scor+=4;
                break;
            case '6':
                scor+=6;
                break;
            case '0':
                break;
            case '2':
                scor+=2;
                break;
            case '1':
                scor+=1;
                str=true;
                break;
            case '3':
                scor+=3;
                str=true;
                break;
            default:
                break;
            }
        break;
        default:
            break;
        }
        if(free>0){
            if(free!=3){
                 team[sb].ball++;
                 scor++;
                 attack[now].runs++;
            }
            if(free==1){
                attack[now].balls++;
                over++;
            }
            free--;
        }
        else{
        team[sb].ball++;
        attack[now].balls++;
        over++;
        }
        cout<<endl;
        cout<<"INDIA :"<<scor<<" - "<<wicket<<"   "<<over/6<<"."<<over%6<<"  "<<(float)scor*6/over<<endl;
        cout<<"*";
        if(free!=3){
        team[sb].info();
        team[ob].info();
        attack[now].infos();
        cout<<endl;
        }
        sb=wic;
        if(str){
            int temp=sb;
            sb=ob;
            ob=temp;
        }
    }
    cout<<"Batting stat:"<<endl;
    for(int i=0;i<11;i++){
        team[i].info();
    }
    cout<<endl<<"bowling stat:"<<endl;
    for(int i=0;i<11;i++){
                if(attack[i].balls){
                    attack[i].infos();
                }
            }
    return 0;
}