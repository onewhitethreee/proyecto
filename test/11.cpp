#include <bits/stdc++.h>
using namespace std;
//#define rep(i, a, b) for(int i=a;i<b;i++)
//#define rrep(i, a, b) for(int i=a;i>b;i--)

struct  Student{
    int no,age;
    string name,sex,school,class_1,hobby;
    //class是一个C++的关键字，所以用class_1表示班级
    Student(){

    }
    Student(int no1){
        no = no1;
    }
};

vector<Student> banji;//banji代表存储快班所有学生的动态数组

/*
 * 返回-1代表在班级中没有查到该学生，否则返回学生在其中的下标
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
//    string op[6]={"编号","姓名",};
    cout<<"输入添加学生的 编号 姓名 性别 年龄 学校 班级 爱好:\n";
    cin>>s.no>>s.name>>s.sex>>s.age>>s.school>>s.class_1>>s.hobby;
    if(isInBanji(s)==-1) {
        banji.push_back(s);
        cout<<"成功添加一个学生!"<<endl;
        return ;
    }
    cout << "该编号学生已经存在，无法反复添加!" << endl;
}

void delStu(){
    cout<<"输入需要删除的学生编号:"<<endl;
    int no;
    cin>>no;
    Student s(no);//调用Student(int no1)构造函数
    int ind = isInBanji(s);
    if(ind!=-1){
        banji.erase(banji.begin()+ind);//删除下标为ind的学生
        cout<<"成功删除一个学生!"<<endl;
        return ;
    }
    cout<<"该编号学生不存在，无法删除!"<<endl;
}

void changeStu(){
    cout<<"输入需要修改的学生的编号:";
    int no;
    cin>>no;
    Student s(no);
    int ind = isInBanji(s);
    if(ind==-1){
        cout<<"该编号学生不存在，无法修改!"<<endl;
        return ;
    }
    int op;
    while(1){
        cout<<"0-退出修改\n"
              "1-修改姓名\n"
              "2-修改性别\n"
              "3-修改年龄\n"
              "4-修改学校\n"
              "5-修改班级\n"
              "6-修改爱好\n";
        cin>>op;
        if(op==0)break;
        cout<<"原信息:";
        switch (op) {
            case 1:cout<<banji[ind].name<<"   修改后:";
                cin>>banji[ind].name;break;
            case 2:cout<<banji[ind].sex<<"   修改后:";
                cin>>banji[ind].sex;break;
            case 3:cout<<banji[ind].age<<"   修改后:";
                cin>>banji[ind].age;break;
            case 4:cout<<banji[ind].school<<"   修改后:";
                cin>>banji[ind].school;break;
            case 5:cout<<banji[ind].class_1<<"   修改后:";
                cin>>banji[ind].class_1;break;
            case 6:cout<<banji[ind].hobby<<"   修改后:";
                cin>>banji[ind].hobby;break;
        }
    }
}

void findStu(){
    cout<<"输入需要查询的学生编号(查询全部输入-1):\n";
    int no;
    cin>>no;
    if(no==-1){
        printf("%3s %3s %2s %3s %10s %8s %20s\n",
               "编号","姓名","性别","年龄","学校","班级","爱好");
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
            cout<<"该编号学生不存在，请输入正确的编号!"<<endl;
        }
        else{
            s = banji[ind];
            printf("%3s %3s %2s %3s %10s %8s %20s\n",
                   "编号","姓名","性别","年龄","学校","班级","爱好");
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
        cout<<"0-退出\n";
        cout<<"1-增加学生\n";
        cout<<"2-删除学生\n";
        cout<<"3-修改学生\n";
        cout<<"4-查询学生\n";
        cout<<"选择系统功能：";
        cin>>option;
        if(option==0){
            break;
        }
        switch (option) {
            //调用自己实现的函数功能
            case 1:addStu();break;
            case 2:delStu();break;
            case 3:changeStu();break;
            case 4:findStu();break;
            default:cout<<"请输入正确的编号\n";
        }
    }
    writeToFile();
}
