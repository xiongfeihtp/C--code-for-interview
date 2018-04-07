#include <fstream>
#include <time.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void TxtWrite(){
    int index[50];
    double x_pos[50],y_pos[50];
    srand((unsigned)time(NULL));
    for(int i=0;i<50;i++){
        index[i]=i;
        x_pos[i]=rand()%1000*0.01;
        y_pos[i]=rand()%2000*0.01;
    }
    string file_name="/Users/xiongfei/txt_out.txt";
    fstream outfile(file_name.c_str(),ios::out);
    if(!outfile.is_open()){
        cerr<<"打开文件错误"<<endl;
        return;
    }
    for(int i=0;i<50;i++){
        outfile<<setw(5)<<index[i]<<"\t"<<setw(10)<<x_pos[i]\
            <<"\t"<<setw(10)<<y_pos[i]<<endl;
    }
    outfile.close();
}
void TextRead(){
    string file_name="/Users/xiongfei/txt_out.txt";
    fstream infile(file_name.c_str(),ios::in);
    vector<int> index;
    vector<double> x_pos;
    vector<double> y_pos;
    if(!infile.is_open()){
        cerr<<"打开文件错误"<<endl;
    }
    cout<<"mode为1，按字符读入并输出；mode为2，按行读入输出;mode为3，知道数据格式，按行读入并输出"<<endl;
    int mode=1;
    cin>>mode;
    if(mode==1){
        char ch;
        //一个字节一个字节进行读取，不忽略空格
        while(((ch=infile.get())!=EOF)){
            cout<<ch;
        }
    }else if (mode==2){
        string buff;
        //一行一行读取
        while(!infile.eof()){
            getline(infile,buff);
            //防止多读
            if(infile.fail()) {
                break;
            }
            cout<<buff<<"\t"<<endl;
        }
    }else if(mode==3){
        int index_temp;
        double x_pos_temp=0,y_pos_temp=0;
        while(!infile.eof()){
            //一行一行读取，忽略空格
            infile>>index_temp>>x_pos_temp>>y_pos_temp;
            //防止多读
            if(infile.fail()) {
                break;
            }
            index.push_back(index_temp);
            x_pos.push_back(x_pos_temp);
            y_pos.push_back(y_pos_temp);
            cout << index_temp << "\t" << x_pos_temp << "\t" << y_pos_temp << endl;
        }
    }
    infile.close();
}

void DataWrite(){
    double pos[200];
    for(int i=0;i<200;i++){
        pos[i]=i;
    }
    string file_path="/Users/xiongfei/txt_out.dat";
    fstream outfile(file_path,ios::binary);
    if(!outfile.is_open()){
        cerr<<"创建文件失败"<<endl;
        return;
    }
    outfile.write((char*)pos,200*sizeof(double));
    outfile.close();
}

void DataRead(){
    double pos[200];
    string file_path="/Users/xiongfei/txt_out.dat";
    fstream infile(file_path,ios::binary);
    if(!infile.is_open()){
        cerr<<"打开文件失败"<<endl;
        return;
    }
    infile.read((char*)pos,200*sizeof(double));
    for(int i=0;i<200;i++)
        cout<<pos[i]<<endl;
    infile.close();
}

void DataRead_new(){
    streampos size;
    char* memblock;
    string file_path="/Users/xiongfei/txt_out.dat";
    //追加到文件末尾
    ifstream file(file_path,ios::in|ios::binary|ios::ate);
    if(file.is_open()){
        size=file.tellg();//返回文件当前位置，也就是文件的长度
        memblock=new char[size];
        //seekg（）是对输入文件定位，它有两个参数：第一个参数是偏移量，第二个参数是基地址。
        file.seekg(0,ios::beg);
        file.read((char*)memblock,size);
        file.close();
        cout<<"the entire file content is in memory"<<endl;
        delete[] memblock;
    }else{
        cout<<"unable to open file"<<endl;
    }
}


int main(void){
    TxtWrite();
    TextRead();
}
