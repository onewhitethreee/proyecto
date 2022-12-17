#include <bits/stdc++.h>
using namespace std;
//#define rep(i, a, b) for(int i=a;i<b;i++)
//#define rrep(i, a, b) for(int i=a;i>b;i--)

struct  Student{
    int no,age;
    string name,sex,school,class_1,hobby;
    //class��һ��C++�Ĺؼ��֣�������class_1��ʾ�༶
    Student(){

    }
    Student(int no1){
        no = no1;
    }
};

vector<Student> banji;//banji����洢�������ѧ���Ķ�̬����

/*
 * ����-1�����ڰ༶��û�в鵽��ѧ�������򷵻�ѧ�������е��±�
 */
int isInBanji(Student& s){
    for(int i=0;i<banji.size();i++){
        if(s.no==banji[i].no){
            return i;
        }
    }
    return -1;
}

void writeToFile(){
    ofstream fout("student.txt");
    for(auto& s:banji) {
        fout << s.no << " " << s.name << " " << s.sex << " " << s.age << " " << s.school << " " << s.class_1 << " "
             << s.hobby << endl;
    }
    fout.close();
}
void readFromFile(){
    ifstream fin("student.txt");
    Student s;
    while(!fin.eof()){
        fin>>s.no>>s.name>>s.sex>>s.age>>s.school>>s.class_1>>s.hobby;
        if(fin.fail())
            break;
        banji.push_back(s);
    }
    fin.close();
}

void addStu(){
    Student s;
//    string op[6]={"���","����",};
    cout<<"�������ѧ���� ��� ���� �Ա� ���� ѧУ �༶ ����:\n";
    cin>>s.no>>s.name>>s.sex>>s.age>>s.school>>s.class_1>>s.hobby;
    if(isInBanji(s)==-1) {
        banji.push_back(s);
        cout<<"�ɹ����һ��ѧ��!"<<endl;
        return ;
    }
    cout << "�ñ��ѧ���Ѿ����ڣ��޷��������!" << endl;
}

void delStu(){
    cout<<"������Ҫɾ����ѧ�����:"<<endl;
    int no;
    cin>>no;
    Student s(no);//����Student(int no1)���캯��
    int ind = isInBanji(s);
    if(ind!=-1){
        banji.erase(banji.begin()+ind);//ɾ���±�Ϊind��ѧ��
        cout<<"�ɹ�ɾ��һ��ѧ��!"<<endl;
        return ;
    }
    cout<<"�ñ��ѧ�������ڣ��޷�ɾ��!"<<endl;
}

void changeStu(){
    cout<<"������Ҫ�޸ĵ�ѧ���ı��:";
    int no;
    cin>>no;
    Student s(no);
    int ind = isInBanji(s);
    if(ind==-1){
        cout<<"�ñ��ѧ�������ڣ��޷��޸�!"<<endl;
        return ;
    }
    int op;
    while(1){
        cout<<"0-�˳��޸�\n"
              "1-�޸�����\n"
              "2-�޸��Ա�\n"
              "3-�޸�����\n"
              "4-�޸�ѧУ\n"
              "5-�޸İ༶\n"
              "6-�޸İ���\n";
        cin>>op;
        if(op==0)break;
        cout<<"ԭ��Ϣ:";
        switch (op) {
            case 1:cout<<banji[ind].name<<"   �޸ĺ�:";
                cin>>banji[ind].name;break;
            case 2:cout<<banji[ind].sex<<"   �޸ĺ�:";
                cin>>banji[ind].sex;break;
            case 3:cout<<banji[ind].age<<"   �޸ĺ�:";
                cin>>banji[ind].age;break;
            case 4:cout<<banji[ind].school<<"   �޸ĺ�:";
                cin>>banji[ind].school;break;
            case 5:cout<<banji[ind].class_1<<"   �޸ĺ�:";
                cin>>banji[ind].class_1;break;
            case 6:cout<<banji[ind].hobby<<"   �޸ĺ�:";
                cin>>banji[ind].hobby;break;
        }
    }
}

void findStu(){
    cout<<"������Ҫ��ѯ��ѧ�����(��ѯȫ������-1):\n";
    int no;
    cin>>no;
    if(no==-1){
        printf("%3s %3s %2s %3s %10s %8s %20s\n",
               "���","����","�Ա�","����","ѧУ","�༶","����");
        for(auto& s: banji){
            printf("%3d %3s %2s %3d %10s %8s %20s\n",
                   s.no,s.name.c_str(),s.sex.c_str(),s.age,
                   s.school.c_str(),s.class_1.c_str(),s.hobby.c_str());
//            cout<<s.no<<" "<<s.name<<" "<<s.sex<<" "<<s.age<<" "<<s.school<<" "<<s.class_1<<" "<<s.hobby<<endl;
        }
    }
    else{
        Student s(no);
        int ind = isInBanji(s);
        if(ind == -1){
            cout<<"�ñ��ѧ�������ڣ���������ȷ�ı��!"<<endl;
        }
        else{
            s = banji[ind];
            printf("%3s %3s %2s %3s %10s %8s %20s\n",
                   "���","����","�Ա�","����","ѧУ","�༶","����");
            printf("%3d %3s %2s %3d %10s %8s %20s\n",
                   s.no,s.name.c_str(),s.sex.c_str(),s.age,
                   s.school.c_str(),s.class_1.c_str(),s.hobby.c_str());
        }
    }
}

int main() {
    int option;
    readFromFile();
    while(1){
        cout<<"0-�˳�\n";
        cout<<"1-����ѧ��\n";
        cout<<"2-ɾ��ѧ��\n";
        cout<<"3-�޸�ѧ��\n";
        cout<<"4-��ѯѧ��\n";
        cout<<"ѡ��ϵͳ���ܣ�";
        cin>>option;
        if(option==0){
            break;
        }
        switch (option) {
            //�����Լ�ʵ�ֵĺ�������
            case 1:addStu();break;
            case 2:delStu();break;
            case 3:changeStu();break;
            case 4:findStu();break;
            default:cout<<"��������ȷ�ı��\n";
        }
    }
    writeToFile();
}
