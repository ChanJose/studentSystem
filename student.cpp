//
//  student.cpp
//  studentSystem
//
//  Created by ChanJose on 2019/1/2.
//  Copyright © 2019年 ChanJose. All rights reserved.
//

#include "student.h"
//string id; // 学生的学号
//string name; // 姓名
//string birthday; // 出生日期：如1995-01-01
//int sex; // 1:表示是男生，0:表示是女生
//string phone; // 电话
//string address; // 地址

// 新建学生通讯录信息
// 如：20192101011 ChanJose 2000-01-01 1 15626453333 广东广州
Node *Create() {
    int i = 1;
    char ch = 'Y'; // 是否继续输入学生通讯录信息
    Node *head = new Node(); // 头结点，不存放数据
    if(NULL == head) {
        cerr << "内存空间分配失败" << endl;
        exit(1);
    }
    head->next = NULL;
    while(ch == 'Y') {
        cout << "请输入第" << i << "位学生的学号、姓名、出生日期、姓别（1:表示是男生，0:表示是女生）、电话和地址(以空格隔开):" << endl;
        Node *newNode = new Node(); // 新建结点
        if(NULL == newNode) {
            cerr << "内存空间分配失败" << endl;
            exit(1);
        }
        cin >> newNode->id >> newNode->name >> newNode->birthday >> newNode->sex >> newNode->phone >> newNode->address;
        newNode->next = NULL;
        // 采用头插入
        newNode->next = head->next; // 新结点的next保存首结点（头结点的下一个结点）
        head->next = newNode; // 头指针往前移
        i++;
        cout << "是否继续输入学生的通讯录信息？(Y/N):";
        cin >> ch;
    }
    return head;
}

// 向学生通讯录插入学生信息
bool InsertStudent(Node *head) {
    cout << "请输入学生的学号、姓名、出生日期、姓别（1:表示是男生，0:表示是女生）、电话和地址(以空格隔开):" << endl;
    Node *newNode = new Node(); // 新建结点
    if(NULL == newNode) {
        cerr << "内存空间分配失败" << endl;
        exit(1);
    }
    cin >> newNode->id >> newNode->name >> newNode->birthday >> newNode->sex >> newNode->phone >> newNode->address;
    newNode->next = head->next; // 新结点的next保存首结点（头结点的下一个结点）
    head->next = newNode; // 头指针往前移
    return true; // 插入成功
}

// 在通讯录中删除学生信息
bool DeleteStudent(Node *head, string id) {
    Node *prev = head;
    Node *p = head->next;
    
    while(p != NULL && p->id != id) { // 也可以用strcmp,但不知道为什么我引入了#include <cstring>还是发现找不到strcmp函数
        prev = p;
        p = p->next;
    }
    if(p == NULL)
        return false;
    prev->next = p->next;
    delete p;
    p = NULL;
    return true;
}

// 从文件中读取通讯录信息
Node *ReadFromFile() {
    Node *head = new Node(); // 头结点，不存放数据
    if(NULL == head) {
        cerr << "内存空间分配失败" << endl;
        exit(1);
    }
    ifstream inFile;
    inFile.open("student.txt", ios::in); // 以读的方式打开文件
    if(!inFile.is_open())
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    Node *newNode = new Node(); // 新建结点
    if(NULL == newNode) {
        cerr << "内存空间分配失败" << endl;
        exit(1);
    }
    while(!inFile.eof()) { // 当未到文件尾
        Node *newNode = new Node(); // 新建结点
        if(NULL == newNode) {
            cerr << "内存空间分配失败" << endl;
            exit(1);
        }
        // 从文件中输入数据
        inFile >> newNode->id >> newNode->name >> newNode->birthday >> newNode->sex >> newNode->phone >> newNode->address;
        newNode->next = head->next; // 新结点的next保存首结点（头结点的下一个结点）
        head->next = newNode; // 头指针往前移
    }
    inFile.close(); // 关闭文件
    return head;
}

// 向文件写入学生通讯录信息
bool WriteToFile(Node *head) {
    Node *p = head->next;
    
    // 以写模式打开文件
    ofstream outFile;
    outFile.open("student.txt", ios::out);
    if(!outFile)
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    while(p != NULL) {
        // 写入文件
        outFile << p->id << " " << p->name << " " << p->birthday << " " << p->sex << " " << p->phone << " " << p->address << endl;
        p = p->next; // 往后移
    }
    return true;
}

// 在通讯录中查询学生信息（按学号查询）
bool FindStudent(Node *head, string id) {
    Node *p = head->next;
    
    while(p != NULL && p->id != id) { // 也可以用strcmp,但不知道为什么我引入了#include <cstring>还是发现找不到strcmp函数
        p = p->next;
    }
    if(p == NULL)
        return false;
    return true;
}

// 在屏幕中输出全部学生信息
void PrintStudent(Node *head) {
    Node *p = head->next;
    
    while(p != NULL) {
        cout << "学号：" << p->id << " 姓名:" << p->name << " 出生日期：" << p->birthday;
        if(p->sex == 1)
            cout << " 性别：男";
        else
            cout << " 性别：女";
        cout << " 电话:" << p->phone << " 地址：" << p->address << endl;
        p = p->next;
    }
}
